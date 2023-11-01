#include <stdio.h>
#include <stdlib.h>
#include "../inc/cliente.h"

void addUser() {
    char filename[] = "clientes.csv";
    FILE *userFile = fopen(filename, "a"); 

    if (!userFile) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return;
    }

    User newUser;
    printf("Username: ");
    scanf("%[^\n]", newUser.username);
    printf("CPF: ");
    scanf("%d", &newUser.cpf);
    printf("Senha: ");
}