#ifndef CLIENTE_H
#define CLIENTE_H

// DECLARACOES DAS FUNCOES SOBRE O GERENCIAMENTO DE CLIENTES
typedef struct
{
  int id;
  char username[50];
  char cpf[12];
  char password[15];
  char email[50];
} User;

#endif