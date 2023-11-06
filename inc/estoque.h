#ifndef ESTOQUE_H
#define ESTOQUE_H

// DECLARACOES DAS FUNCOES SOBRE O ESTOQUE DE PRODUTOS E SEU GERENCIAMENTO

typedef struct Product
{
    int id;
    char name[50];
    float price;
    int quantity;
} product;

void add_product();
void list_products();
void update_product();
void delete_product();
void search_product();
void update_product_quantity();
void list_products_alfabetically();
void list_products_by_price();
void list_products_by_quantity();
void list_products_by_id();

#endif
