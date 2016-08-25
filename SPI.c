#include <stdio.h>
#include <stdlib.h>
//Raspberry pi Register initialization
int CS=0;
int FIFO=0;
int CLK=0;
int DLEN=0;
int LTOH=0;
int DC=0;

//CS Pins
int TA=7;
int CSPOL0=21;
int CSPOL1=22;
int CSPOL2=23;
int CSPOL=6;
int CPHA=2;
int CS0=0;
int CS1=1;
int TXD=18;
int RXD=17;
int DONE=16;

void spi_init(void)
{
 	CS=(1<<CPHA);   //TA=1, Chip select 0,
 	CLK=1;

}
int main()
{
	time(NULL);
	spi_init();
	int clock=0,i=0,j=0;
	int MISO=0,MOSI=0;
	while(i<16)
	{
		MISO=0;
		int data=rand()%256;
		printf("Data generated %d \n", data);
		CS|=(1<<TA)|(1<<TXD);
		j=0;
		while(j<16)
		{
			if(clock==1)
			{
				int bit=(data&1);
				printf("Transferring bit %d   \n", bit);
				data=data>>1;
				MISO=(MISO>>1)|(bit<<7);
			}

			clock=(clock+1)&1;
			j++;
		}
		printf("Data transferred %d \n", MISO);
		i++;
		//clock=(clock+1)&1;
	}
}