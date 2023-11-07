#ifndef ESTOQUE_H
#define ESTOQUE_H

// DECLARACOES DAS FUNCOES SOBRE O ESTOQUE DE PRODUTOS E SEU GERENCIAMENTO

typedef struct Product
{
    int id;
    char name[50];
    float price;
    int quantity;
    struct Product *left;
    struct Product *right;
}product;

product *addProduct(product *root, char *name, float price, int quantity);
void listProducts(product *p);
void updateProduct(product *root, char *name, float new_price);
void deleteProduct();
void searchProduct();
void updateProductQuantity();
void listProductsAlfabetically();
void listProductsByPrice();
void list_productsByQuantity();
void list_productsById();

#endif

