#include "libBareMetal.h"
#include "lexisLib.h"

/*
* return true if flagName is setted. Flag starts with '-' char
*/
int flagSet(char*args[], int, char*flagName);

/*
* return value of flagName. Value of flag is next argument after flagName.
*/
char* flagValue(char*args[], int, char*flagName);
