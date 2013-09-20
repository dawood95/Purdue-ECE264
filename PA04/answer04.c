/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>

void displayArrAll(int * , int);
void displayArrIncreasing(int *, int);
void displayArrDeccreasing(int *, int);
void partitionHelper(int *, int, int, int, int);
void partition(int *,int , int, int);
int isIncreasing(int *, int);
int isDecreasing(int *, int);

/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */

void displayArrAll(int *array, int end)
{
  int i = 0;
  printf("= %d",array[i]);
  for(i = 1; i<=end; i++)
    {
      printf(" + %d",array[i]);
    }
  printf("\n");
}

void displayArrIncreasing(int *array, int end)
{
  if(isIncreasing(array,end) == 1)
    {
      int i = 0;
      printf("= %d",array[i]);
      for(i = 1; i<=end; i++)
	{
	  printf(" + %d",array[i]);
	}
      printf("\n");
    }
}

void displayArrDecreasing(int *array, int end)
{
  if(isDecreasing(array,end) == 1)
    {
      int i = 0;
      printf("= %d",array[i]);
      for(i = 1; i<=end; i++)
	{
	  printf(" + %d",array[i]);
	}
      printf("\n");
    }
}

int isDecreasing(int *array, int end)
{
  int i = 0;
  for(i = 0; i<end;i++)
    {
      if(array[i] <= array[i+1])
	{
	  return 0;
	}
    }
  return 1;

}
int isIncreasing(int *array, int end)
{
  int i = 0;
  for(i = 0; i<end;i++)
    {
      if(array[i] >= array[i+1])
	{
	  return 0;
	}
    }
  return 1;
}

void partitionHelper(int *array, int value, int firstElement, int index, int functionNumber)
{
  array[index] = firstElement;
  if(firstElement == value)
    {
      switch(functionNumber)
	{
	case (1): 
	  displayArrAll(array,index);
	  break;
	case (2):
	  displayArrIncreasing(array,index);
	  break;
	case (3):
	  displayArrDecreasing(array,index);
	  break;
	}
    }
  else if(value-firstElement > 0)
    {
      partition(array,value-firstElement,index + 1,functionNumber); 
    }
  else
    {
      displayArrAll(array,0);
    }
}

void partition(int *array,int value, int index, int functionNumber)
{
  int firstElement;
  for(firstElement = 1; firstElement <= value; firstElement++)
    {
      partitionHelper(array,value,firstElement,index,functionNumber);
    }
}

void partitionAll(int value)
{
  int array[MAXLENGTH];
  printf("partitionAll %d\n", value); 
  partition(array,value,0,1);
}

/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionIncreasing(int value)
{
  int array[MAXLENGTH];
  printf("partitionIncreasing %d\n", value);
  partition(array,value,0,2);
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionDecreasing(int value)
{
  int array[MAXLENGTH];
  printf("partitionDecreasing %d\n", value);
  partition(array,value,0,3);
}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOdd(int value)
{
  printf("partitionOdd %d\n", value);
  
}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEven(int value)
{
  printf("partitionEven %d\n", value);

}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOddAndEven(int value)
{
  printf("partitionOddAndEven %d\n", value);
  
}

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */



void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);

}
