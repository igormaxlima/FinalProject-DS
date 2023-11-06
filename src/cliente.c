#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "../inc/cliente.h"
#include "../inc/validations.h"

unsigned int hashClient(char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash += *str;
        str++;
    }
    return hash;
}

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

  //Hashing user password
  unsigned int passwordHash = hashClient(newUser.password);
  newUser.hash = passwordHash;

  fprintf(userFile, "%s,%s,%s,%u\n", newUser.username, newUser.cpf, newUser.email, newUser.hash);
  fclose(userFile);
  printf("Usuário cadastrado com sucesso!\n");
}

bool verifyClientLogin(char *cpf, unsigned int *hash)
{
  User user;
  FILE *usersFile = fopen("./data/clientes.csv", "r");

  if (!usersFile)
  {
    fprintf(stderr, "Error ao abrir arquivo.\n");
    return false;
  }

  while (fscanf(usersFile, "%[^,], %[^,], %[^,], %u", user.username, user.cpf, user.email, &user.hash) != EOF)
  {
    if (strcmp(user.cpf, cpf) == 0 && user.hash == *hash)
    {
      fclose(usersFile);
      return true;
    }
  }

  fclose(usersFile);
  return false;
}

void clientMenu()
{
  printf("MENU DO CLIENTE!!!!!!\n");
  return;
}
