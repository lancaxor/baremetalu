#include "lexisLib.h"

//(1+x)^a=1+sum(in k=1..n)(a*(a-1)*(a-2)*...*(a-(k-1))/k! *x^k

double pow(double num, double power){	//only integer
	if(power==0)		//power=0		//work
		return 1.0;
	else if(power==1)	//power=1		//work
		return num;
	else if(power>1){	//power>1		//work
		double res=1;
		for(int i=0;i<power;i++)
			res*=num;
		return res;}
	else if(power<0){	//power<0		//work
		num=1/num;
		double res=1;
		for(int i=0;i<power;i++)
			res*=num;
		return res;}
	else			//0<power<1		//NOT work
		{return 0;}
return -100500.100500;
}

int findchar(char* str,int len,char template){
for(int i=0;i<len;i++)
if(str[i]==template)
return i;
return -1;}


long strton(const char* string){	//success
long result=0;
int currNum=0;
int strlen=strLen(string);
for(int i=0;i<strlen;i++){
currNum=string[i]-'0';
result*=10;
result+=currNum;}
return result;
}

void itostr(long num, char* outStr){	//success
int len=1;
long tmp_num=num;
while(1){	//get len
if((int)(tmp_num/=10)==0) break;
len++;}
b_mem_allocate((unsigned long*)outStr,len);

for(int i=0;i<len;i++){
long tmp_1=num-(int)(num/(int)pow(10,i+1))*(int)pow(10,i+1);
tmp_1/=pow(10,i);
*(outStr+len-i-1) = '0'+tmp_1;}}

int strLen(const char*str){	//success
int res=0;
while(*str++)
res++;
return res;}
