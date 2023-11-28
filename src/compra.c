#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "../inc/compra.h"

ShoppingCartNode *createShoppingCartNode(product product)
{
  ShoppingCartNode *newNode = malloc(sizeof(ShoppingCartNode));
  if (newNode)
  {
    newNode->next;
    newNode->product = product;
  }
  return newNode;
}

ShoppingCart initializeCart()
{
  ShoppingCart cart = {.first = NULL, .last = NULL, .size = 0};
  return cart;
}