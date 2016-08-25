#include <bits/stdc++.h>
using namespace std;
/*
void generateDiff(int msb1,int lsb1,int msb2,int lsb2)
{
	int d1=(lsb1-lsb2)&255;
	int d2=((msb1-msb2)<<8)&65280;
	int dk=d2+d1;
	file<<dk<<endl;
}
*/
int main()
{
	ofstream file;
	file.open("example.txt");
	time(NULL);
	//Generate random numbers
	int n1=0,m;
	cout<<"Enter the number of data: ";
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int n=rand()%65536;
		cout<<n<<endl;
		int msb=(n&65280)>>8;
		int lsb=(n&255);
		//printf("N=%d MSB=%d LSB=%d \n",n,msb,lsb);
		int msb1=(n1&65280)>>8;
		int lsb1=(n1&255);
		int d1=(lsb-lsb1);
		int d2=((msb-msb1));
		int dk=d2+d1;
		file<<d1<<endl;
		file<<d2<<endl;
		n1=n;
	}
	file.close();
}