#include "bpingall.h"
int start(int argc,char**argv){
char str[100]="par1";
char str1[100]="par2";
b_system_misc(get_argv,str,str1);
b_output("param1: ");
b_output(str);
b_output("\nparam2: ");
b_output(str1);
b_output("\n");
b_output("fignya: ");
b_output(*argv	);
return 0;}
