/*
Name:Shardul Pathak
Roll no:222021
Gr No:17u666
Batch:B1
*/

#include<iostream>
using namespace std;

int main()
{
	int i,j,v,a,b,w;
	char ans;
	cout<<"Enter the number of airports"<<endl;
	cin>>v;
	int flight[v][v];
	for(i=0;i<v;i++)
	{
	  for(j=0;j<v;j++)
	  {
	    flight[i][j]=0;
	  }
	}
	
	cout<<"Enter the flight details in the format (a-b-time)"<<endl;
	do
	{
	  cin>>a>>b>>w;
	  flight[a][b]=w;
	  cout<<"Any more flights? (Y/N)"<<endl;
	  cin>>ans;
	}
	while(ans=='y');
	
	cout<<"The flight details are as follows"<<endl;
	for(i=0;i<v;i++)
	{
	  for(j=0;j<v;j++)
	  {
	    if(flight[i][j]!=0)
	    cout<<"Flight from "<<i<<" to "<<j<<" takes "<<flight[i][j]<<" minutes"<<endl;
	  }
	}
	return 0;
}
