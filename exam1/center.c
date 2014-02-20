/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Modified by Amanda Lee
2/20/2014

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns a heap-allocated string with length n, with
// the given string in the middle, surrounded by fillchar.
//
// For example, if s is allen, n is 10 and fillchar is .
// the result is ..allen... 

char *center(char *s, int n, char fillchar)
{
    int i;
    char *dest, *buf;

    //find the starting position of s in the final string
    int start = (n - strlen(s))/2;

    //convert the char to a char array
    char fillC[2];
    fillC[0] = fillchar;
    fillC[1] = '\0';

    //allocate memory for the string
    buf = (char *) malloc ((n+1) * sizeof(char));
    buf[0] = '\0';
    dest = buf;

    //adds the first section of fillchar
    for (i=0; i<start; i++) {
    strcpy(dest, fillC);
    dest ++;
    }

    //adds the string to be centered
    strcpy(dest,s);
    dest += strlen(s);

    //adds the last section of fillchar
    for (i = start+strlen(s); i<n; i++){
        strcpy(dest, fillC);
    dest ++;    
    }

    return buf;
}


int main (int argc, char *argv[])
{
    char *s = center("Software", 30, '.');
    printf("%s\n", s);

    char *s2 = center("Systems", 31, '-');
    printf("%s\n", s2);

    char *s3 = center("Spring 2014", 32, '*');
    printf("%s\n", s3);

    char *s4 = center("Exam 1", 33, '^');
    printf("%s\n", s4);

    return 0;
}
