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

/********************Custom fucntions intitializations****************************/

void displayArrAll(int * , int);

void partitionHelper(int *, int, int, int);
void partition(int *,int ,int);

void partitionHelperInc(int *, int, int, int);
void partitionInc(int *,int ,int);

void partitionHelperDec(int *, int, int, int);
void partitionDec(int *,int ,int);

void partitionHelperOddh(int *, int, int, int);
void partitionOddh(int *,int ,int);

void partitionHelperEvenh(int *, int, int, int);
void partitionEvenh(int *,int ,int);

void partitionHelperOE(int *, int, int, int);
void partitionOE(int *,int ,int);

void partitionHelperP(int *, int, int, int);
void partitionP(int *,int ,int);

int isPrime(int);

/*******************************************************************************/

int isPrime(int number)
{
  int i = 1;
  int count = 0;
  for(i = 1; i <= number; i++)
    {
      if(number % i == 0)
	{
	  count++;
	}
    }
  if(count == 2)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

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

/*******************************************************************/

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

void partitionHelper(int *array, int value, int firstElement, int index)
{
  array[index] = firstElement;  
  if(firstElement == value)
    {
      displayArrAll(array,index);
    }
  else if(value-firstElement > 0)
    {
      partition(array,value-firstElement,index + 1); 
    }
}

void partition(int *array,int value, int index)
{
  int firstElement;
  for(firstElement = 1; firstElement <= value; firstElement++)
    {
      partitionHelper(array,value,firstElement,index);
    }
}

void partitionAll(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionAll %d\n", value); 
  partition(array,value,0);
  free(array);
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


void partitionHelperInc(int *array, int value, int firstElement, int index)
{ 
  if(firstElement == value)
    {
      displayArrAll(array,index);
    }
  else if(value-firstElement > 0 && value-firstElement > firstElement)
    {
      partitionInc(array,value-firstElement,index + 1); 
    }
}

void partitionInc(int *array, int value, int index)
{
  int firstElement;
  for(firstElement = 1; firstElement <= value; firstElement++)
    {
      array[index] = firstElement; 
      if(index > 0 && array[index] > array[index-1])
	{
	  partitionHelperInc(array,value,firstElement,index);
	}
      else if(index == 0)
	{
	  partitionHelperInc(array,value,firstElement,index);
	}
    }
}

void partitionIncreasing(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionIncreasing %d\n", value);
  partitionInc(array,value,0);
  free(array);
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

void partitionHelperDec(int *array, int value, int firstElement, int index)
{ 
  if(firstElement == value)
    {
      displayArrAll(array,index);
    }
  else if(value-firstElement > 0)
    {
      partitionDec(array,value-firstElement,index + 1); 
    }
}

void partitionDec(int *array, int value, int index)
{
  int firstElement;
  for(firstElement = 1; firstElement <= value; firstElement++)
    {
      array[index] = firstElement; 
      if(index > 0 && array[index] < array[index-1])
	{
	  partitionHelperDec(array,value,firstElement,index);
	}
      else if(index == 0)
	{
	  partitionHelperDec(array,value,firstElement,index);
	}
    }
}

void partitionDecreasing(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionDecreasing %d\n", value);
  partitionDec(array,value,0);
  free(array);
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

void partitionHelperOddh(int *array, int value, int firstElement, int index)
{ 
  if(firstElement == value && firstElement%2 !=0)
    {
      displayArrAll(array,index);
    }
  else if(value-firstElement > 0)
    {
      partitionOddh(array,value-firstElement,index + 1); 
    }
}

void partitionOddh(int *array, int value, int index)
{
  int firstElement;
  for(firstElement = 1; firstElement <= value; firstElement++)
    {
      if(firstElement%2 != 0)
	{
	  array[index] = firstElement; 
	  partitionHelperOddh(array,value,firstElement,index);
	}
    }
}

void partitionOdd(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionOdd %d\n", value);
  partitionOddh(array,value,0);
  free(array);
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

void partitionHelperEvenh(int *array, int value, int firstElement, int index)
{ 
  if(firstElement == value && firstElement%2 ==0)
    {
      displayArrAll(array,index);
    }
  else if(value-firstElement > 0)
    {
      partitionEvenh(array,value-firstElement,index + 1); 
    }
}

void partitionEvenh(int *array, int value, int index)
{
  int firstElement;
  for(firstElement = 1; firstElement <= value; firstElement++)
    {
      if(firstElement%2 == 0)
	{
	  array[index] = firstElement; 
	  partitionHelperEvenh(array,value,firstElement,index);
	}
    }
}

void partitionEven(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionEven %d\n", value);
  partitionEvenh(array,value,0);
  free(array);
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

void partitionHelperOE(int *array, int value, int firstElement, int index)
{
  if(firstElement == value)
    {
      displayArrAll(array,index);
    }
  else if(value-firstElement > 0)
    {
      partitionOE(array,value-firstElement,index + 1); 
    }
}

void partitionOE(int *array,int value, int index)
{
  int firstElement;
  for(firstElement = 1; firstElement <= value; firstElement++)
    {
      array[index] = firstElement;  
      if(((index+1)%2 == 0 && array[index]%2 == 0) || ((index+1)%2 != 0 && array[index]%2 != 0))
	{
	  partitionHelperOE(array,value,firstElement,index);
	}
    }
}

void partitionOddAndEven(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionOddAndEven %d\n", value);
  partitionOE(array,value,0);  
  free(array);
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

void partitionHelperP(int *array, int value, int firstElement, int index)
{
  array[index] = firstElement;  
  if(firstElement == value)
    {
      displayArrAll(array,index);
    }
  else if(value-firstElement > 0)
    {
      partitionP(array,value-firstElement,index + 1); 
    }
}

void partitionP(int *array,int value, int index)
{
  int firstElement;
  for(firstElement = 1; firstElement <= value; firstElement++)
    {
      if(isPrime(firstElement) == 1)
	{
	  partitionHelperP(array,value,firstElement,index);
	}
    }
}

void partitionPrime(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionPrime %d\n", value);
  partitionP(array,value,0);
  free(array);
}
