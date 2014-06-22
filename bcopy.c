#include "bcopy.h"

char* myAddr="FD:E3:E6:63:AC:00";
int sendMyAddr=1;
char*fileAddr;
char *destAddr;
char packet[1500];
char*eof = "<EOF>";

unsigned int b_file_seek(unsigned int file, unsigned int offset, unsigned int origin){}	//feature now is not avaiable
unsigned int b_file_create(unsigned int* filename, unsigned int size){}			//https://github.com/ReturnInfinity/BareMetal-OS/blob/master/programs/libBareMetal.h
unsigned int b_file_query(unsigned int* filename){}					// -- the path to origin file.

void SendFile(){
	sendMyAddr=0;
	unsigned long fileHandle=0;
	unsigned int curPos=0;

	b_ethernet_rx(packet);		//receive addr
	
	if(strcmp(destAddr,packet)==0){	//packet sender is needed addr
		char*buf;
		int readMore=1;
		b_mem_allocate((unsigned long*)buf, 1500);			//allocate memory for buffer;
		b_system_config(networkcallback_set, 0);	//don`t need callback after connection
		fileHandle = b_file_open(fileAddr);
		if(fileHandle==0){
			b_output("Error while opening");
			return;}
		while(readMore==1){
			b_file_seek(fileHandle, curPos, 0);
			unsigned int read = b_file_read(fileHandle, buf, 1499);
			curPos += read;
			b_ethernet_tx(buf, read);		//send current part of file
			if(read<1499){		// EOF
				readMore=0;
				b_file_close(fileHandle);
				b_ethernet_tx(eof, 6);		//send EOF signal to remote
				break;}}
		b_mem_release((unsigned long*)buf, 1500);
	}
}

int main(int argc,char*argv[]){
	if(flagSet(argv, argc, "-s")==1){	//start server. format: bcopy.app -s remote_addr path_to_file
		b_system_config(networkcallback_set, (unsigned long int)SendFile);	//set CallBack
		fileAddr=argv[3];
		destAddr=argv[2];
		while(sendMyAddr == 1)		//wait for client
			b_ethernet_tx(myAddr, strLen(myAddr));}
	else{		//start client. format: bcopy -f -m source dest // -m?source is MAC:source is filename
		if(flagSet(argv,argc, "-f")==1)		//force create file even if exists
			b_file_create(destAddr, 1073741824);		//1 MiB
		
		if(flagSet(argv, argc,"-m")==1){		//from remote
			destAddr=argv[4];
			if(b_file_query(destAddr)!=0 && flagSet(argv,argc, "-f")==0){	//file exists && flag -f not set
				b_output("File already exists");
				return -1;}

				unsigned int eof=0;
				b_ethernet_rx(packet);	//server addr
				b_ethernet_tx(myAddr, strLen(myAddr));	//send my addr
				unsigned long fh = b_file_open(destAddr);
				while(eof==0){
					unsigned long received = b_ethernet_rx(packet);
					if(strcmp(packet, eof))	eof=1;
					else	b_file_write(fh, packet, received);}
				b_file_close(fh);
		}else{	//local
			destAddr=argv[argc];
			fileAddr=argv[argc-1];
			if(b_file_query(destAddr)!=0 && flagSet(argv,argc, "-f")==0){	//file exists && flag -f not set
					b_output("File already exists");
					return -1;}
			unsigned int fhin = b_file_open(fileAddr);
			unsigned int fhout = b_file_open(destAddr);
			char*buf;
			b_mem_allocate((unsigned long*)buf, 1073741823);
			unsigned int read = b_file_read(fhin, buf, 1073741823);
			b_file_write(fhout, buf, read);
			b_mem_release((unsigned long*)buf, 1073741823);
			b_file_close(fhin);
			b_file_close(fhout);
	}}
	b_system_config(networkcallback_set, 0);	//unset CallBack
	return 0;}
