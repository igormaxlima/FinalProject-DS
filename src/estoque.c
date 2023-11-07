// Descrição: Arquivo responsável por implementar as funções do arquivo estoque.h
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../inc/estoque.h"

//Funções para read e write no CSV da árvore
void writeProductToFile(FILE *file, product *root) {
    if (root != NULL) {
        fprintf(file, "%d,%s,%.2f,%d\n", root->id, root->name, root->price, root->quantity);
        writeProductToFile(file, root->left);
        writeProductToFile(file, root->right);
    }
}
product *readProductsFromFile() {
    FILE *file = fopen("products.csv", "r");
    product *root = NULL;
    int id;
    char name[50];
    float price;
    int quantity;

    while (fscanf(file, "%d,%49[^,],%f,%d\n", &id, name, &price, &quantity) == 4) {
        root = addProduct(root, name, price, quantity);
    }

    fclose(file);
    return root;
}

// Funções para balanceamento da árvore
int height(product *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

product* rightRotate(product *y) {
    product *x = y->left;
    product *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

product* leftRotate(product *x) {
    product *y = x->right;
    product *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

int getBalance(product *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

product* addProduct(product *root, char *name, float price, int quantity) {
    if (root == NULL) {
        product *new_product = (product*)malloc(sizeof(product));
        strcpy(new_product->name, name);
        new_product->price = price;
        new_product->quantity = quantity;
        new_product->height = 1;
        return new_product;
    }

    if (strcmp(name, root->name) < 0)
        root->left = addProduct(root->left, name, price, quantity);
    else if (strcmp(name, root->name) > 0)
        root->right = addProduct(root->right, name, price, quantity);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && strcmp(name, root->left->name) < 0)
        return rightRotate(root);

    if (balance < -1 && strcmp(name, root->right->name) > 0)
        return leftRotate(root);

    if (balance > 1 && strcmp(name, root->left->name) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && strcmp(name, root->right->name) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void listProductsAlphabetically(product *root) { // em ordem
    if (root != NULL) {
        // lado esquerdo do nó
        listProductsAlphabetically(root->left);

        // Then print the data of the root
        printf("Nome: %s \n", root->name);
        printf("Preço: %.2f \n", root->price);
        printf("Quantidade: %d \n", root->quantity);
        printf("-------------------\n");

        // Now recur on right child
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

void deleteProduct(product *root, char *name) {
    if (root == NULL) {
        printf("Produto não encontrado\n");
        return;
    }
    if (strcmp(root->name, name) < 0)
        deleteProduct(root->right, name);
    else if (strcmp(root->name, name) > 0)
        deleteProduct(root->left, name);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) {
            product *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            product *temp = root;
            root = root->left;
            free(temp);
        }
        else {
            product *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            strcpy(root->name, temp->name);
            root->price = temp->price;
            root->quantity = temp->quantity;
            deleteProduct(root->right, temp->name);
        }
    }
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

        // Then print the data of the root
        if(root->quantity == 0){
            printf("Nome: %s \n", root->name);
            printf("Preço: %.2f \n", root->price);
            printf("Quantidade: %d \n", root->quantity);
            printf("-------------------\n");
        }

        // Now recur on right child
        anyProductsMissing(root->right);
    }
}