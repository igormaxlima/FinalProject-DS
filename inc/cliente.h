#ifndef CLIENTE_H
#define CLIENTE_H

// DECLARACOES DAS FUNCOES SOBRE O GERENCIAMENTO DE CLIENTES
typedef struct {
    int id;
    char username[50];
    int cpf;
    char password[15];
} User;

#endif