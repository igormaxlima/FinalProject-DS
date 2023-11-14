#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../inc/funcionario.h"
#include "../inc/estoque.h"

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
  product *root = createTree();
  char ch;
  while (1) {
    printf("1 - Listar todos os produtos\n");
    printf("2 - Adicionar produto ao estoque\n");
    printf("3 - Remover produto do estoque\n");
    printf("4 - Procurar produto por nome\n");
    printf("5 - Procurar produto por ID\n");
    printf("6 - Atualizar quantidade de um produto\n");
    printf("7 - Atualizar valor de um produto\n");
    printf("8 - Verificar produto faltante\n");
    ch = getchar();
    clearBuffer();
    
    if (ch == 'q' || ch == 'Q')
      break;

    switch (ch) {
      case '1':
        system("clear");
        listProductsAlphabetically(root);
        break;
      case '2':
        system("clear");
        int id;
        char productName[50];
        float price;
        int quantity;
        printf("ID do produto: ");
        scanf("%d", &id);
        printf("Produto: ");
        scanf(" %[^\n]%*c", productName);
        printf("Valor do produto: ");
        scanf("%f", &price);
        printf("Quantidade: ");
        scanf("%d", &quantity);
    }
    }
  return;
}
