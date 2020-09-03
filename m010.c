/* m010.c - Day of the week.

   This program takes two integers read as command line arguments
   representing, respectively, the day and the month of a date in
   year 2020, and produces as output the corresponding day of the week.
   Output should be: Sunday, Monday, Thursday, Wednesday, Thursday,
   Friday, Saturday.

   E.g.

      command line    : m010 2 6
      expected output : Thursdays

   Directions:

      Please, edit function day_of_week();
      do no not change function main().

 */

#include <stdio.h>
#include <stdlib.h>

#define USAGE "m010 <day> <month>\n"

enum {sun, mon, tue, wed, thu, fri, sat};

/* Return the day of the week in the numeric form:
   Sunday=0, Monday=1... Saturday=6.*/
int day_of_week (int day, int month)
{
  int i, current=0, days[12];

  days[0]=31;
  days[1]=29;
  days[2]=31;
  days[3]=30;
  days[4]=31;
  days[5]=30;
  days[6]=31;
  days[7]=31;
  days[8]=30;
  days[9]=31;
  days[10]=30;
  days[11]=31;

  for(i=0; i<(month-1); i++) {
    current += days[i];       
  }

  current += day;

  switch(current%7) {
    case 5:
      return sun;
    break;

    case 6:
      return mon;
    break;

    case 0:
      return tue;
    break;
    
    case 1:
      return wed;
    break;

    case 2:
      return thu;
    break;

    case 3:
      return fri;
    break;
    
    case 4:
      return sat;
    break;

    default:
      return 0;
    break;
  }
}

/* Do not edit function main. */
int main (int argc, char **argv)
{
  int day, month, dweek;
  int g;

  if (argc < 3)
    {
      printf (USAGE);
      exit(1);
    }
  
  day = atoi(argv[1]);
  month = atoi(argv[2]);

  dweek = day_of_week (day, month);
  
  switch (dweek)
    {
    case sun:
      printf ("Sunday\n");
      break;
    case mon:
      printf ("Monday\n");
      break;
    case tue:
      printf ("Tuesday\n");
      break;
    case wed:
      printf ("Wednesday\n");
      break;
    case thu:
      printf ("Thursday\n");
      break;
    case fri:
      printf ("Friday\n");
      break;
    case sat:
      printf ("Saturday\n");
      break;
    default:
      printf ("Something wrong\n");
      break;
    }
  
  return 0;
}
