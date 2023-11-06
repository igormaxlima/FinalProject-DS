#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// DECLARACOES DAS FUNCOES SOBRE O MENU DE FUNCIONARIO
typedef struct
{
    char id[10];
    char username[51];
    char password[16];
} Employee;

char generateEmployeeID();
void addEmployee();
bool verifyEmployeeLogin(char *id, char *password);
void employeeMenu();

#endif