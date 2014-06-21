#include "argparser.h"

int flagSet(char*args, int len, char*flagName){
	int argc=1;
	char **argArr;		//512 params 512 len even
	argArr=&args;
	for(int i=0; i<len; i++)
		if(args[i]==' '){
			argc++;
			if(args[i+1]!=' ' && args[i+1]!= '\n')
				argArr[argc]=&args[i+1];}
				
	for(int i=0;i<argc;i++)
		b_output(argArr[i]);
	
	return 0;
}

char* flagValue(char*args, int argc, char*flagName){
	return "hhh";
}
