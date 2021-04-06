#include <stdio.h>		//header files
#include <stdlib.h>
#include <string.h>
#define MAX 50			//maximum size


int top = -1, front = 0;
int stackArray[MAX];		//array decleration

void push (char);		//push method
void pop ();			// pop method

int
main ()				//main method
{
  int i, dec;
  char array[MAX], b;
  while (1)
    {
      printf ("1.Press 1 to check whether the string is palindrome or not.\n2.Press 2 to exit.\n");	//menu 
      printf ("Choose operation : ");
      scanf ("%d", &dec);
      switch (dec)
	{
	case 1:
	  printf ("\nEnter the word : \t");	//getting value
	  scanf ("%s", array);
	  for (i = 0; array[i] != '\0'; i++)
	    {
	      b = array[i];
	      push (b);		//pushing
	    }
	  for (i = 0; i < (strlen (array) / 2); i++)	//checking  the condition
	    {
	      if (stackArray[top] == stackArray[front])
		{
		  pop ();
		  front++;
		}
	      else
		{
		  printf ("%s is not a palindrome.\n\n", array);
		  break;
		}
	    }
	  if ((strlen (array) / 2) == front)
	    printf ("%s is a palindrome.\n\n", array);
	  front = 0;
	  top = -1;
	  break;
	case 2:
	  return 0;
	default:
	  printf ("Invalid operation \n");
	}
    }
  return 0;			//exiting the program
}

void
push (char a)
{
  top++;
  stackArray[top] = a;
}

void
pop ()
{
  top--;
}

