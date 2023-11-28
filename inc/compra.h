#ifndef COMPRA_H
#define COMPRA_H
#include "estoque.h"
#include "cliente.h"

// DECLARACOES DAS FUNCOES SOBRE A COMPRA DE PRODUTOS
typedef struct ShoppingCartNode
{
    product product;
    struct ShoppingCartNode *next;
} ShoppingCartNode;

typedef struct
{
    ShoppingCartNode *first;
    ShoppingCartNode *last;
    int size;
} ShoppingCart;

typedef struct
{
    ShoppingCart cart;
    User user;     // usuario que comprou
    float price;   // preco total da compra
    int quantity;  // quantidade de produtos comprados
    char date[21]; // DD/MM/YYYY - HH:MM:SS

} Purchase;

void purchaseProduct();
ShoppingCartNode *createShoppingCartNode(product product);
ShoppingCart initializeCart();
void listPurchases();
void deletePurchase();
void searchPurchase();
void modifyPurchase();

#endif