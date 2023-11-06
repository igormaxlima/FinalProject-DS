#ifndef ESTOQUE_H
#define ESTOQUE_H

// DECLARACOES DAS FUNCOES SOBRE O ESTOQUE DE PRODUTOS E SEU GERENCIAMENTO

struct produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};


#endif