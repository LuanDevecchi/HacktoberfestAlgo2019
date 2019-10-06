/*

Transform a number (any base) represented by a string into an integer in decimal.

From classes of Federal University Of Goiás (UFG) in Brazil.

*/

#include <ctype.h>
#include <stdio.h>

int string2num(char *s, int base) {

  int a = 0;

  //The value of *s represents the decimal
  //value of the character in the ASCII table.
  for ( ; *s; s++){

    //Since the string is converted to an integer, the value
    //of "(* s - '0')" is the value of the character respectively
    //in decimal. For example, if *s = 50, where '0' = 48, the given
    //value is 2 (50 in the ASCII table represents character 2).

      if(isdigit(*s)) //if [0 - 9]
        a = a * base + (*s - '0');

      else //if [a - z]
        a = a * base + (*s - 'a' + 10);
  }
  return a;
}

int main () {

  //exemples
  //(number, base)
  printf("%d\n", string2num("1000", 2)); //return 8
  printf("%d\n", string2num("a09b", 16));
  printf("%d\n", string2num("k09b", 30));

  return 0;
}
