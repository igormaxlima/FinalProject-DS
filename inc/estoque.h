#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
    int height;
    struct product *left;
    struct product *right;
} product;

// Organização para utilização da árvore em arquivo
void writeProductToFile(FILE *file, product *root);
product *readProductsFromFile();

// funções para balanceamento da árvore
int height(product *N);
int max(int a, int b);
product *rightRotate(product *y);
product *leftRotate(product *x);
int getBalance(product *N);

//
product *addProduct(product *root, char *name, float price, int quantity);
void listProductsAlphabetically(product *root);
void updateProductPrice(product *root, char *name, float new_price);

// algoritmos de busca
product *searchProductAlphabetically(product* root, char* name)
product *searchProductById(product* root, int id);

// outras manipulações
void deleteProduct(product *root, char *name);
void updateProductQuantity(product *root, char *name, int new_quantity);
void anyProductsMissing(product *root);
void list_productsById();

#endif

