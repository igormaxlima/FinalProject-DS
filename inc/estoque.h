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
void writeProductToFile(product *root);
void writeProductToFileHelper(FILE *file, product *root);
product *readProductsFromFile();

// Criação da árvore
product* createTree();

//manipulação da árvore e adições
product* addProduct(product *root, int id, char *name, float price, int quantity);
void listProductsAlphabetically(product *root);
void updateProductPrice(product *root, char *name, float new_price);

// algoritmos de busca
product *searchProductAlphabetically(product* root, char* name);
product *searchProductById(product* root, int id);

// outras manipulações
product *deleteProduct(product *root, char *name);
product* minValueNode(product* node);
void updateProductQuantity(product *root, char *name, int new_quantity);
void anyProductsMissing(product *root);

#endif

