#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "../inc/login.h"
#include "../inc/cliente.h"
#include "../inc/validations.h"
#include "../inc/estoque.h"


void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int main()
{
  char ch;
  while (1)
  {
    printf("1 - Funcionario\n");
    printf("2 - Cliente\n");
    printf("Q - Sair\n");
    printf("Opção: ");
    ch = getchar();
    clearBuffer();

    if (ch == 'q' || ch == 'Q')
      break;

    switch (ch)
    {
    case '1':
      system("clear");
      break;
    case '2':
      system("clear");
      authMenu();
      break;
    }
  }
  return 0;
}
