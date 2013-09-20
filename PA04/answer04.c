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

/********************Custom fucntions****************************/

void displayArrAll(int * , int);
void displayArrIncreasing(int *, int);
void displayArrDeccreasing(int *, int);
void displayArrOdd(int *, int);
void displayArrEven(int *, int);
void displayArrOddEven(int *, int);
void displayArrPrime(int *, int);
void partitionHelper(int *, int, int, int, int);
void partition(int *,int , int, int);
int isIncreasing(int *, int);
int isDecreasing(int *, int);
int isOdd(int *, int);
int isEven(int *, int);
int isOddEven(int *, int);
int isPrime(int *, int);
int prime(int);


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

void displayArrOdd(int *array, int end)
{
  if(isOdd(array,end) == 1)
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

void displayArrEven(int *array, int end)
{
  if(isEven(array,end) == 1)
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

void displayArrOddEven(int *array, int end)
{
  if(isOddEven(array,end) == 1)
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

void displayArrPrime(int *array, int end)
{
  if(isPrime(array,end) == 1)
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

int isPrime(int *array, int end)
{
  int i = 0;
  for(i = 0; i <= end; i++)
    {
      if(prime(array[i]) == 0)
	{
	  return 0;
	}
    }
  return 1;
}

int prime(int number)
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

int isOddEven(int *array, int end)
{
  int i = 0;
  for(i = 0; i<=end;i++)
    {
      if(((i%2 == 0) && (array[i]%2 == 0)) || ((i%2 != 0) && (array[i]%2 != 0)) )
	{
	  return 0;
	}
    }
  return 1;
}

int isOdd(int *array, int end)
{
  int i = 0;
  for(i = 0; i <= end;i++)
    {
      if((array[i]%2) == 0)
	{
	  return 0;
	}
    }
  return 1;
}

int isEven(int *array, int end)
{
  int i = 0;
  for(i = 0; i<=end;i++)
    {
      if((array[i]%2) != 0)
	{
	  return 0;
	}
    }
  return 1;
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
	case (4):
	  displayArrOdd(array,index);
	  break;
	case (5):
	  displayArrEven(array,index);
	  break;
	case (6):
	  displayArrOddEven(array,index);
	  break;
	case (7):
	  displayArrPrime(array,index);
	  break;
	}
    }
  else if(value-firstElement > 0)
    {
      partition(array,value-firstElement,index + 1,functionNumber); 
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

void partitionAll(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionAll %d\n", value); 
  partition(array,value,0,1);
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

void partitionIncreasing(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionIncreasing %d\n", value);
  partition(array,value,0,2);
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

void partitionDecreasing(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionDecreasing %d\n", value);
  partition(array,value,0,3);
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

void partitionOdd(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionOdd %d\n", value);
  partition(array,value,0,4);
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

void partitionEven(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionEven %d\n", value);
  partition(array,value,0,5);
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


void partitionOddAndEven(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionOddAndEven %d\n", value);
  partition(array,value,0,6);  
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

void partitionPrime(int value)
{
  int * array = malloc(value * sizeof(int));
  printf("partitionPrime %d\n", value);
  partition(array,value,0,7);
  free(array);
}
