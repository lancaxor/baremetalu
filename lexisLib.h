// lexis library for bareMetal OS
// here is functions for automatization some tasks
// Author: Lexis Lyashenko (c)


#include "libBareMetal.h"

//returns $par1^$par2 (or in fortran, $par1**$par2)
double pow(double, double);

// int index = findchar(char* string, int stringLen, char Template)
// returns index of char or -1 if char Template not found in string
int findchar(char*,int,char);

// int result = strton(char* string, int size)
// convert string to integer number
// and returns result or NULL if cannot convert
// string to number
long int strton(const char*);

// itostr(int src, char* dest)
// convert integer src to string dest
void itostr(long int,char*);

// int strlen(char*str)
// return length of string str
// in num of symbols
int strLen(const char*);

// returns 0 if strings is equals
// other value -- if not equals
int strcmp(const char*, const char*);
