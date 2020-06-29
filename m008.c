/* m008.c - Lastname-Names.

   This program reads the name of a person from the standard input
   in the form 'First-name middle-names last-name' and outputs the 
   name in the form 'LAST-NAME, first-name middle-names'.
   The name should be entered using only ASCII characters (26 letter 
   of latim alphabet, no diacrictics).


   E.g.

      command line    : m008
      standard input  : John Little Bill Doe 
      expected output : DOE, John Little Bill

   Directions:

      Please, edit function lasname();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

/* Converts the string 's' from first-middle-last name 
   form into LAST-first-middle form. */
void lastname (char *c)
{
  char copied[MAX];
  char finalv[MAX];
  int i=0, j, lastspace, length;

  strcpy(copied, c);
  length = strlen(copied);

  while(copied[i] != 0) {
    if(copied[i] == ' ') {
      lastspace = i;
    }
    i++;
  }

  for(j=(lastspace+1); j<length; j++) {
    if((copied[j]>='a') && (copied[j]<='z')) {
      finalv[j-(lastspace+1)] = copied[j] - ' ';
    }
    else {
      finalv[j-(lastspace+1)] = copied[j];
    }
  }

  finalv[length-(lastspace+2)] = ',';
  finalv[length-(lastspace+1)] = ' ';

  for(j=0; j<lastspace; j++) {
    finalv[length-lastspace+j] = copied[j];
  }
  
  finalv[length] = 0;
  strcpy(c, finalv);
}

/* Do not edit this function. */
int main (int argc, char **argv)
{
  int n;
  char name[MAX];

  fgets (name, MAX-1, stdin);
  
  lastname (name);

  printf ("%s\n", name);
  
  return 0;
}
