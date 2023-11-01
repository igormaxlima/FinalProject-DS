#ifndef VALIDATIONS_H
#define VALIDATIONS_H
#include <stdbool.h>

// DECLARACOES DAS FUNCOES SOBRE O SISTEMA DE LOGIN PARA A APLICACAO

bool verifyExistenceCPF(char *cpf);
bool validateCPF(const char *cpf);
bool validateEmail(const char *email);

#endif