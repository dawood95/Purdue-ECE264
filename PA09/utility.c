#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"

Node * createTree_ch(FILE* inFile) 
{
  Stack * stack = NULL;
  Node * tree = NULL;
  char instruction = '0';

  do
    {
      instruction = fgetc(inFile);
      if(instruction == '1')
	stack = pushStack(stack,fgetc(inFile));
      else
	{
	  if(stack != NULL && stack->next == NULL)
	    {
	      if(tree != NULL)
		deleteTree(tree);
	      tree = copyTree(stack->node);
	    }
	  stack = popStackAndProcess(stack);
	}
    }while(stack != NULL);
  return tree;
}

Node * createTree_bit(FILE* inFile)
{
  int i = 1;
  Stack *stack = NULL;
  Node *tree = NULL;
  unsigned char instruction = 0;
  unsigned char primary = fgetc(inFile); 
  unsigned char secondary = 0;
  unsigned char operand = 0;
  do
    {
      if(i > 8)
	i %= 8;
      
      instruction = primary >> 7;
      if(instruction == 1)
	{
	  secondary = fgetc(inFile);
	  operand = primary << 1 ; 
	  if(i == 8 && operand != 0)  fprintf(stderr, "ERROR line %d\n", __LINE__);
	  operand  =  operand | (secondary >> (8-i)); 
	  stack = pushStack(stack,operand);
	  if(i == 8)
	    primary = fgetc(inFile);
	  else
	    primary = secondary << i;
	  
	  // Put in some if statements for what things should look like afterwards
	}
      else
	{
	  if(stack != NULL && stack->next == NULL)
	    {
	      if(tree != NULL)
		deleteTree(tree);
	      tree = copyTree(stack->node);
	    }
	  stack = popStackAndProcess(stack);
	  if(i == 8)
	    primary = fgetc(inFile);
	  else
	    primary = primary << 1;
	}
      i++;
    } while(stack != NULL);
  
  return tree;
}


Stack * pushStack(Stack* stack, char ch)
{
  if(stack == NULL)
    {
      stack = newStackNode(ch);
      return stack;
    }
  Stack * newStackHead = newStackNode(ch);
  newStackHead->next = stack;
  return newStackHead;
}

Stack * newStackNode(char ch)
{
  Stack *stack = malloc(sizeof(Stack));
  stack->node = newTreeNode(ch);
  stack->next = NULL;
  return stack;
}

Node * newTreeNode(char ch)
{
  Node *node = malloc(sizeof(Node));
  node->value = ch;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Stack * popStackAndProcess(Stack* stack)
{
  if(stack == NULL)
    return NULL;
  if(stack->next == NULL)
    return deleteStackTopNode(stack);
  Node *first = copyTree(stack->node);
  Node *second = copyTree(stack->next->node);
  stack = deleteStackTopNode(stack);
  stack = deleteStackTopNode(stack);
  Stack *newHead = newStackNode(0);
  Node *newNode = newHead->node;
  newNode->right = first;
  newNode->left = second;
  newHead->next = stack;
  return newHead;
}

Stack * deleteStackTopNode(Stack* stack)
{
  if(stack == NULL)
    return NULL;
  Stack * newHead = stack->next;
  deleteTree(stack->node);
  free(stack);
  return newHead;
}

void deleteStack(Stack* stack)
{
  if(stack->next != NULL)
    deleteStack(stack->next);
  deleteTree(stack->node);
  free(stack);
}

Node * copyTree(Node* node)
{
  if(node == NULL)
    return NULL;
  Node *copy = newTreeNode(node->value);
  copy->left = copyTree(node->left);
  copy->right = copyTree(node->right);
  return copy;
}

int getStackHeight(Stack* stack) 
{
  if(stack == NULL)
    return 0;
  else
    return 1+getStackHeight(stack->next);  
}

void postOrderPrint(Node* tree, FILE* outFile)
{
  if (tree == NULL) 
    {
      return;
    }
  fprintf(outFile,"Left\n");
  postOrderPrint(tree->left,outFile);
  fprintf(outFile,"Back\n");
  fprintf(outFile,"Right\n");
  postOrderPrint(tree->right,outFile);
  fprintf(outFile,"Back\n");
  if (tree->left == NULL && tree->right == NULL) 
    {
      fprintf(outFile,"Leaf: %c\n", tree->value);
    }
}

void deleteTree(Node* tree)
{
  if(tree == NULL)
    return;
  if(tree->left != NULL)
    deleteTree(tree->left);
  if(tree->right != NULL)
    deleteTree(tree->right);
  free(tree);
}
