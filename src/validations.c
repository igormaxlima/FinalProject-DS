#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "../inc/validations.h"
#include "../inc/cliente.h"

bool verifyExistenceCPF(char *cpf)
{
  User user;
  FILE *arquivo;

  arquivo = fopen("./data/clientes.csv", "r");

  if (!arquivo)
  {
    fprintf(stderr, "Error ao abrir arquivo para verificacão de CPF.\n");
    return false;
  }

  while (fscanf(arquivo, "%[^,], %[^,], %[^,], %[^\n]", user.username, user.cpf, user.email, user.password) != EOF)
  {
    if (strcmp(user.cpf, cpf) == 0)
    {
      fclose(arquivo);
      return true;
    }
  }

  fclose(arquivo);
  return false;
}

bool validateCPF(const char *cpf)
{
  int i;
  if (strlen(cpf) != 11)
  {
    return false;
  }

  for (i = 0; i < 11; i++)
  {
    if (!isdigit(cpf[i]))
    {
      return false;
    }
  }

  int digito1 = 0;
  int digito2 = 0;
  int peso = 10;

  for (i = 0; i < 9; i++)
  {
    digito1 += (cpf[i] - '0') * peso;
    peso--;
  }

  peso = 11;
  for (i = 0; i < 10; i++)
  {
    digito2 += (cpf[i] - '0') * peso;
    peso--;
  }

  digito1 = (digito1 * 10) % 11;
  if (digito1 == 10)
  {
    digito1 = 0;
  }

  digito2 = (digito2 * 10) % 11;
  if (digito2 == 10)
  {
    digito2 = 0;
  }

  if ((cpf[9] - '0' != digito1) || (cpf[10] - '0' != digito2))
  {
    return false;
  }

  return true;
}

bool validateEmail(const char *email)
{
  int i, atCount = 0, dotCount = 0;

  if (strlen(email) == 0 || strlen(email) > 320)
  {
    return false;
  }

  for (i = 0; email[i] != '\0'; i++)
  {
    if (email[i] == '@')
    {
      atCount++;
    }
  }

  if (atCount != 1)
  {
    return false;
  }

  if (email[strlen(email) - 1] == '.')
  {
    return false;
  }

  for (i = 0; email[i] != '\0'; i++)
  {
    if (email[i] == '.')
    {
      dotCount++;
    }
  }

  if (dotCount < 1)
  {
    return false;
  }

  return true;
}