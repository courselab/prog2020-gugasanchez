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
  char changed[MAX];
  int i, j, length, space;

  strcpy(copied, c);
  length = strlen(copied);

  for(i=0; copied[i]!=0; i++) {
    if(copied[i] == ' ') {
      space = i;
    }
  }

  for(j=(space+1); j<length; j++) {
    if((copied[j] >= 'a') && (copied[j] <= 'z')) {
      changed[j-(space+1)] = copied[j]-32;
    }
    else {
      changed[j-(space+1)] = copied[j];
    }
  }

  changed[length-(space+1)] = ',';
  changed[length-space] = ' ';

  for(j=0; j<space; j++) {
    changed[length-space+1+j] = copied[j];
    changed[length+1] = 0;
  }

  strcpy(c, changed);
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