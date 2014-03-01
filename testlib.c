#include "testlib.h"
int main(int argc,char*argv[]){
char a[100],b[100];
b_output("Enter a and b: ");
b_input(a,100);
b_input(b,100);
b_output("\n");
long iA=strton(a),iB=strton(b);
long iC=iA*iB;
char *c;
itostr(iC,c);
b_output(c);
b_output("\n");
return 0;}
