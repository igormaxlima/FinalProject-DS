#ifndef LOGIN_H
#define LOGIN_H
#include <stdbool.h>

// DECLARACOES DAS FUNCOES SOBRE O SISTEMA DE LOGIN PARA A APLICACAO

void addUser();
void authMenu();
bool verifyLogin(char *name, char *password);

#endif