#ifndef CLIENTE_H
#define CLIENTE_H


// DECLARACOES DAS FUNCOES SOBRE O GERENCIAMENTO DE CLIENTES
typedef struct
{
  int id;
  char username[51];
  char cpf[12];
  char password[16];
  char email[51];
  unsigned int hash;
} User;

unsigned int hashClient(char *str);
void addUser();
bool verifyClientLogin(char *name, unsigned int *hash);
void clientMenu();

#endif