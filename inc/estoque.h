#ifndef ESTOQUE_H
#define ESTOQUE_H

// DECLARACOES DAS FUNCOES SOBRE O ESTOQUE DE PRODUTOS E SEU GERENCIAMENTO

typedef struct product
{
    int id;
    char name[50];
    float price;
    int quantity;
    struct product *left;
    struct product *right;
}product;

//árvore de produtos
product* createProduct(char* name, float price, product *left, struct product *right);
void printProducts(product *p);
void update_product(product* products, int n, product* p);
void delete_product();
void search_product();
void update_product_quantity();
void list_products_alfabetically();
void list_products_by_price();
void list_products_by_quantity();
void list_products_by_id();


#endif 