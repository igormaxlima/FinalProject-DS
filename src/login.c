#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "../inc/login.h"
#include "../inc/cliente.h"
#include "../inc/validations.h"

void addUser()
{
  char filename[] = "./data/clientes.csv";
  FILE *userFile = fopen(filename, "a");

  if (!userFile)
  {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    return;
  }

  User newUser;
  printf("Nome: ");
  scanf(" %[^\n]%*c", newUser.username);

  bool validCpf = false;
  while (!validCpf)
  {
    printf("CPF: ");
    scanf("%s", newUser.cpf);

    if (validateCPF(newUser.cpf) == true)
    {
      validCpf = true;
    }
    else
    {
      printf("CPF Inválido!\n");
    }
  }

  bool validEmail = false;
  while (!validEmail)
  {
    printf("Email: ");
    scanf(" %[^\n]%*c", newUser.email);

    if (validateEmail(newUser.email) == true)
    {
      validEmail = true;
    }
    else
    {
      printf("Email Inválido!\n");
    }
  }

  printf("Senha: ");
  scanf(" %[^\n]%*c", newUser.password);

  if (verifyExistenceCPF(newUser.cpf) == true)
  {
    printf("Este CPF já encontra-se cadastrado no sistema!\n");
    return;
  }

  long fileSize;
  fseek(userFile, 0, SEEK_END);
  fileSize = ftell(userFile);
  if (fileSize == 0)
  {
    fprintf(userFile, "Nome do Usuário,CPF,Email,Senha\n");
  }

  fprintf(userFile, "%s,%s,%s,%s\n", newUser.username, newUser.cpf, newUser.email, newUser.password);
  fclose(userFile);
  printf("Usuário cadastrado com sucesso!\n");
}

bool verifyLogin(char *cpf, char *password)
{
  User user;
  FILE *usersFile = fopen("./data/clientes.csv", "r");

  if (!usersFile)
  {
    fprintf(stderr, "Error ao abrir arquivo.\n");
    return false;
  }

  while (fscanf(usersFile, "%[^,], %[^,], %[^,], %[^\n]", user.username, user.cpf, user.email, user.password) != EOF)
  {
    if (strcmp(user.cpf, cpf) == 0 && strcmp(user.password, password) == 0)
    {
      fclose(usersFile);
      return true;
    }
  }

  fclose(usersFile);
  return false;
}

void authMenu()
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
      if (verifyLogin(cpf, password) == true)
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
