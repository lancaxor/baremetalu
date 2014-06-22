#include "argparser.h"

int flagSet(char*args[], int argc, char*flagName){
	for(int i=0;i<argc;i++){
		if(strcmp(args[i],flagName)==0)	//equals
			return 1;		//flag setted
	}	
	return 0;				//flag not setted
}

char* flagValue(char*args[], int argc, char*flagName){
	for(int i=0; i<argc-1; i++){
		if(strcmp(args[i],flagName)==0)
			return args[i+1];
	}
	return flagName;	//if not found -- return flag
}
