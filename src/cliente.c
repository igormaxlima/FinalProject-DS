#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/cliente.h"

int checkCPF(char *cpf) {
    if (strlen(cpf) != 11) {
        return 0;
    }
    return 1;
}

void addUser() {
    char filename[] = "../data/clientes.csv";
    FILE *userFile = fopen(filename, "a"); 

    if (!userFile) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return;
    }

    User newUser;
    printf("Nome: ");
    scanf("%[^\n]", newUser.username);
    printf("CPF: ");
    scanf("%s", newUser.cpf);
    while (!checkCPF(newUser.cpf)) {
        printf("CPF inválido.\n");
        printf("CPF: ");
        scanf("%s", newUser.cpf);
    }
    printf("Senha: ");
    scanf("%s", newUser.password);

    long fileSize;
    fseek(userFile, 0, SEEK_END);
    fileSize = ftell(userFile);
    if (fileSize == 0) {
        fprintf(userFile, "Nome do Usuário,CPF,Senha\n");
    }

    fprintf(userFile, "%s, %s, %s\n", newUser.username, newUser.cpf, newUser.password);
    fclose(userFile);
    printf("Usuário cadastrado com sucesso!\n");
}

int main() {
    addUser();
}
