#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../inc/funcionario.h"

unsigned int hashEmployee(char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash += *str;
        str++;
    }
    return hash;
}

char generateEmployeeID()
{
  return '0' + (rand() % 10);
}

void addEmployee()
{
  srand(time(NULL));
  char filename[] = "./data/funcionarios.csv";
  FILE *employeeFile = fopen(filename, "a");

  if (!employeeFile)
  {
    fprintf(stderr, "Erro ao abrir arquivo.\n");
    return;
  }

  Employee newEmployee;
  printf("Nome: ");
  scanf(" %[^\n]%*c", newEmployee.username);
  printf("Senha: ");
  scanf(" %[^\n]%*c", newEmployee.password);

  for (int i = 0; i < 9; i++)
  {
    newEmployee.id[i] = generateEmployeeID();
  }
  newEmployee.id[9] = '\0';

  long fileSize;
  fseek(employeeFile, 0, SEEK_END);
  fileSize = ftell(employeeFile);
  if (fileSize == 0)
  {
    fprintf(employeeFile, "ID,Nome do Usuário,Senha\n");
  }

  //Hashing employee password
  unsigned int passwordHash = hashEmployee(newEmployee.password);
  newEmployee.hash = passwordHash;

  fprintf(employeeFile, "%s,%s,%u\n", newEmployee.username, newEmployee.id, newEmployee.hash);
  fclose(employeeFile);
  sleep(2);
  printf("Funcionário cadastrado com sucesso!\n");
  sleep(1);
  printf("O seu ID de funcionário é %s.\n", newEmployee.id);
  printf("Você irá precisar do seu ID para efetuar seu login, guarde-o.\n");
}

bool verifyEmployeeLogin(char *id, unsigned int *passwordHash)
{
  Employee employee;
  FILE *employeeFile = fopen("./data/funcionarios.csv", "r");

  if (!employeeFile)
  {
    fprintf(stderr, "Error ao abrir arquivo.\n");
    return false;
  }

  while (fscanf(employeeFile, "%[^,], %[^\n,], %u", employee.username, employee.id, &employee.hash) != EOF)
  {
    if (strcmp(employee.id, id) == 0 && employee.hash == *passwordHash)
    {
      fclose(employeeFile);
      return true;
    }
  }

  fclose(employeeFile);
  return false;
}

void employeeMenu()
{
  printf("MENU DO FUNCIONARIO!!!!!\n");
  return;
}
