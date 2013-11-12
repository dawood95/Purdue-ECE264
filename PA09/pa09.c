#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa09.h"

int main(int argc, char** argv) 
{
  if(argc != 3) 
    {
      printf("Usage: ./pa09 <input file> <output file>\n");
      return EXIT_FAILURE;
    }
  
  FILE *input = NULL;
  FILE *output = NULL;
  Node *tree = NULL;
  
  input = fopen(argv[1],"r");
  
  if(input == NULL)
    {
      printf("Unable to open input file %s\n",argv[1]);
      return EXIT_FAILURE;
    }

  if(strstr(argv[1],"bit") != NULL)
    tree = createTree_bit(input);
  else
    tree = createTree_ch(input);

  output = fopen(argv[2],"w+");
  postOrderPrint(tree,output);
  deleteTree(tree);

  return EXIT_SUCCESS;
}
