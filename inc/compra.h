#ifndef COMPRA_H
#define COMPRA_H
#include "estoque.h"
#include "cliente.h"

// DECLARACOES DAS FUNCOES SOBRE A COMPRA DE PRODUTOS

typedef struct Purchase
{
    product products; // nós de produtos
    User user; // usuario que comprou
    float price; // preco total da compra
    int quantity; // quantidade de produtos comprados
    char date[21]; // DD/MM/YYYY - HH:MM:SS
    
}purchase;

void comprar_produto();
void listar_compras();
void excluir_compra();
void buscar_compra();
void alterar_compra();

#endif