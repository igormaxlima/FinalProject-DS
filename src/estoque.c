#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#ifndef ESTOQUE_C
#define ESTOQUE_C

#include "../inc/estoque.h"

product* insertProduct(product* root, char* name, float price) {
    // se não tem raiz, inicia a árvore binária
    if (root == NULL) {
        return createProduct(name, price, NULL, NULL);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insertProduct(root->left, name, price);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertProduct(root->right, name, price);
    }

    // Return the (unchanged) node pointer
    return root;
}


void printProducts(product *p) {
    if (p != NULL) {
        printProducts(p->left);
        printf("Nome do produto: %s, Preço: %.2f\n", p->name, p->price);
        printProducts(p->right);
    }
}

void update_product(product* root, char* name, float new_price) {
    if (root == NULL) {
        return;
    }
    int cmp = strcmp(root->name, name);
    if (cmp == 0) {
        //atualizar o produto
        root->price = new_price;
    } else if (cmp > 0) {
        update_product(root->left, name, new_price); // percorrer por recursão a árvore binária
    } else {
        update_product(root->right, name, new_price); // percorrer por recursão a árvore binária
    }
}

void delete_product();
void search_product();
void update_product_quantity();
void list_products_alfabetically();
void list_products_by_price();
void list_products_by_quantity();
void list_products_by_id();
#endif 