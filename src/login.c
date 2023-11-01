#include <stdio.h>
#include "login.h"

void initialLogin()
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
      break;
    }
  }
}