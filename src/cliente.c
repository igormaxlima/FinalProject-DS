#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/cliente.h"



void addUser() {
    char filename[] = "../data/clientes.csv";
    FILE *userFile = fopen(filename, "a"); 

    if (!userFile) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return;
    }

    User newUser;
    printf("Nome: ");
    scanf("%[^\n]%*c", newUser.username);
    printf("CPF: ");
    scanf("%[^\n]%*c", newUser.cpf);
    printf("Senha: ");
    scanf("%[^\n]%*c", newUser.password);

    //VERIFICA SE AS COLUNAS JÁ ESTÃO NO ARQUIVO CSV
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
