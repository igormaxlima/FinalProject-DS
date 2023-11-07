// Descrição: Arquivo responsável por implementar as funções do arquivo estoque.h
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "../inc/estoque.h"

product *addProduct(product *root, char *name, float price, int quantity) {
    if (root == NULL) {
        product *new_product = (product*)malloc(sizeof(product));
        strcpy(new_product->name, name);
        new_product->price = price;
        new_product->quantity = quantity;
        new_product->left = NULL;
        new_product->right = NULL;
        return new_product;
    }

    if (strcmp(name, root->name) < 0) {
        root->left = addProduct(root->left, name, price, quantity);
    } else if (strcmp(name, root->name) > 0) {
        root->right = addProduct(root->right, name, price, quantity);
    }

    return root;
}
void listProducts(product *p){
    
}