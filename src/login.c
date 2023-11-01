#include <stdio.h>
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

void initialMenu()
{
  char ch;
  while (1)
  {
    printf("1 - Funcionario\n");
    printf("2 - Cliente\n");
    printf("Q - Sair\n");
    printf("Opção: ");
    ch = getchar();
    if (ch == 'q' || ch == 'Q')
      break;

    switch (ch)
    {
    case '1':
      break;
    case '2':
      addUser();
      break;
    }
  }
}
