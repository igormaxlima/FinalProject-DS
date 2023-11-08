// Descrição: Arquivo responsável por implementar as funções do arquivo estoque.h
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../inc/estoque.h"

//Funções para read e write no CSV da árvore
void writeProductToFile(product *root) {
    FILE *file = fopen("data/products.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    writeProductToFileHelper(file, root);
    fclose(file);
}

void writeProductToFileHelper(FILE *file, product *root) {
    if (root != NULL) {
        fprintf(file, "%d,%s,%.2f,%d\n", root->id, root->name, root->price, root->quantity);
        writeProductToFileHelper(file, root->left);
        writeProductToFileHelper(file, root->right);
    }
}

product *readProductsFromFile() {
    FILE *file = fopen("data/products.csv", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return NULL;
    }
    product *root = NULL;
    int id;
    char name[50];
    float price;
    int quantity;

    while (fscanf(file, "%d,%49[^,],%f,%d\n", &id, name, &price, &quantity) == 4) {
        root = addProduct(root, id, name, price, quantity);
    }

    fclose(file);
    return root;
}

product* createTree() {
    return NULL;
}
// Funções de manipulação da árvore


product* addProduct(product *root, int id, char *name, float price, int quantity) {
    // If the tree is empty, the new product becomes the root
    if (root == NULL) {
        product *new_product = (product*)malloc(sizeof(product));
        new_product->id = id;
        strcpy(new_product->name, name);
        new_product->price = price;
        new_product->quantity = quantity;
        new_product->left = NULL;
        new_product->right = NULL;
        return new_product;
    }

    //se raiz existe, continuar com a criação do nó
    
    if (strcmp(name, root->name) < 0)
        root->left = addProduct(root->left, id, name, price, quantity);
    else if (strcmp(name, root->name) > 0)
        root->right = addProduct(root->right, id, name, price, quantity);

    return root;
}

void listProductsAlphabetically(product *root) { // em ordem
    if (root != NULL) {
        // lado esquerdo do nó
        listProductsAlphabetically(root->left);

        // Printar as informações do produto
        printf("ID: %d \n", root->id);
        printf("Nome: %s \n", root->name);
        printf("Preço: %.2f \n", root->price);
        printf("Quantidade: %d \n", root->quantity);
        printf("-------------------\n");

        // recorrencia no filho da direita
        listProductsAlphabetically(root->right);
    }
}

product *searchProductAlphabetically(product* root, char* name) {
    if(root == NULL){
        printf("Produto não encontrado\n");
        return NULL;
    }
    if (root != NULL && strcmp(root->name, name) == 0) {
        printf("Nome do produto: %s \n", root->name);
        printf("Preço: %.2f \n", root->price);
        printf("Quantidade: %d \n", root->quantity);
        printf("-------------------\n");
        return root;
    }
    if (root != NULL && strcmp(root->name, name) < 0)
        return searchProductAlphabetically(root->right, name);
    if (root != NULL && strcmp(root->name, name) > 0)
        return searchProductAlphabetically(root->left, name);
    
    printf("Produto não encontrado\n");
    return NULL;
}

product *searchProductById(product *root, int id){
    if(root == NULL){
        printf("Produto não encontrado\n");
        return NULL;
    }
    if (root != NULL && root->id == id) {
        printf("Nome do produto: %s \n", root->name);
        printf("Preço: %.2f \n", root->price);
        printf("Quantidade: %d \n", root->quantity);
        printf("-------------------\n");
        return root;
    }
    if (root != NULL && root->id < id)
        return searchProductById(root->right, id);
    if (root != NULL && root->id > id)
        return searchProductById(root->left, id);
    
    printf("Produto não encontrado\n");
    return NULL;
}

product* deleteProduct(product *root, char *name) {
    if (root == NULL) {
        printf("Produto não encontrado\n");
        return root;
    }
    if (strcmp(name, root->name) < 0)
        root->left = deleteProduct(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = deleteProduct(root->right, name);
    else {
        if (root->left == NULL) {
            product *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            product *temp = root->left;
            free(root);
            return temp;
        }
        product *temp = minValueNode(root->right);
        strcpy(root->name, temp->name);
        root->price = temp->price;
        root->quantity = temp->quantity;
        root->right = deleteProduct(root->right, temp->name);
    }
    return root;
}
product* minValueNode(product* node) {
    product* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}
void updateProductPrice(product *root, char *name, float new_price) {
    if (root == NULL) {
        printf("Produto não encontrado\n");
        return;
    }
    if (strcmp(root->name, name) < 0)
        updateProductPrice(root->right, name, new_price);
    else if (strcmp(root->name, name) > 0)
        updateProductPrice(root->left, name, new_price);
    else {
        root->price = new_price;
    }
}

void updateProductQuantity(product *root, char *name, int new_quantity) {
    if (root == NULL) {
        printf("Produto não encontrado\n");
        return;
    }
    if (strcmp(root->name, name) < 0)
        updateProductQuantity(root->right, name, new_quantity);
    else if (strcmp(root->name, name) > 0)
        updateProductQuantity(root->left, name, new_quantity);
    else {
        root->quantity = new_quantity;
    }
}
void anyProductsMissing(product *root){
    //buscar se tem algum produto em falta, imprimir todos os produtos em falta
    if (root != NULL) {
        // lado esquerdo do nó
        anyProductsMissing(root->left);

        //printar o que está em falta
        if(root->quantity == 0){
            printf("Esse(s) produtos está(ão) em falta: \n");
            printf("ID: %d \n", root->id);
            printf("Nome: %s \n", root->name);
            printf("Preço: %.2f \n", root->price);
            printf("Quantidade: %d \n", root->quantity);
            printf("-------------------\n");
        }

        // Recorrer no filho da direita
        anyProductsMissing(root->right);
    }
}

