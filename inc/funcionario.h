#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// DECLARACOES DAS FUNCOES SOBRE O MENU DE FUNCIONARIO
typedef struct
{
    char id[10];
    char username[51];
    char password[16];
    unsigned int hash;
} Employee;

unsigned int hashEmployee(char *str);
char generateEmployeeID();
void addEmployee();
bool verifyEmployeeLogin(char *id, unsigned int *passwordHash);
void employeeMenu();
void clearBuffer();

#endif