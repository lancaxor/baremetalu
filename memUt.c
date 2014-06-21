#include "memUt.h"
//#include "quickmem.h"

char packet[2048];
int running=1;
unsigned char action;
char newl[]="\n";

int main(int argc,char*argv[]){
	b_system_config(networkcallback_set, (unsigned long int)ether_receive);	// cal ether_receive when packet is in buffer
	while(running==1){
		print("\n press Q for quit: ");
		b_input(&action, 1);
		if(action=='Q'||action=='q')
			running = 0;
		else	continue;
	}
	print(newl);
	b_system_config(networkcallback_set, 0);		//clear network callback
	return 0;}

void ether_receive(){
	long int reclen = b_ethernet_rx(packet);
	b_mem_allocate((long unsigned int*)packet, reclen);		//allocate memory for packet
	//// next code will be deleted ////
	print("Received: ");
	b_output_chars(packet, reclen);
	print(newl);
	//// end of junk code ////
	b_mem_release((long unsigned int*)packet, reclen);		//release memory -- и так всё ясно, ну...
//	b_system_misc(debug_dump_mem, packet, reclen);
}


void print(char* string){
	b_output((const char*) string);
}
