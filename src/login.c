#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "../inc/login.h"
#include "../inc/cliente.h"
#include "../inc/validations.h"
#include "../inc/funcionario.h"

void authMenuClient()
{
  char ch;
  while (1)
  {
    printf("1 - Cadastrar Usuário\n");
    printf("2 - Fazer Login\n");
    printf("Q - Sair\n");
    printf("Opção: ");
    ch = getchar();
    if (ch == 'q' || ch == 'Q')
      break;

    switch (ch)
    {
    case '1':
      system("clear");
      addUser();
      break;
    case '2':
      system("clear");
      char cpf[12];
      char password[16];
      printf("CPF: ");
      scanf(" %[^\n]%*c", cpf);
      printf("Senha: ");
      scanf(" %[^\n]%*c", password);
      unsigned int userHash = hashClient(password);
      if (verifyClientLogin(cpf, &userHash) == true)
      {
        sleep(1);
        printf("Login bem sucedido!\n");
        sleep(2);
        clientMenu();
      }
      else
      {
        printf("Login Falhou!\n");
        printf("Veja se já foi cadastrado e tente novamente...\n");
        sleep(3);
        system("clear");
      }
      break;
    }
  }
}

void authMenuEmployee()
{
  char ch;
  while (1)
  {
    printf("1 - Cadastrar Novo Funcionário\n");
    printf("2 - Fazer Login\n");
    printf("Q - Sair\n");
    printf("Opção: ");
    ch = getchar();
    if (ch == 'q' || ch == 'Q')
      break;

    switch (ch)
    {
    case '1':
      system("clear");
      addEmployee();
      break;
    case '2':
      system("clear");
      char id[11];
      char password[16];
      printf("Digite seu ID de funcionário: ");
      scanf(" %[^\n]%*c", id);
      printf("Digite sua senha: ");
      scanf(" %[^\n]%*c", password);
      unsigned int employeeHash = hashEmployee(password);
      if (verifyEmployeeLogin(id, &employeeHash))
      {
        sleep(1);
        printf("Login bem sucedido!\n");
        sleep(2);
        employeeMenu();
      }
      else
      {
        printf("Falha no login. Verifique suas credenciais.\n");
        sleep(3);
        system("clear");
      }
      break;
    }
  }
}