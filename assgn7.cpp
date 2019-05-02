/*
Name:Shardul Pathak
Roll no:222021
Gr No:17u666
Batch:B1
*/

#include<iostream>
using namespace std;

class hashtable
{
int table[10];
public :

void initialize()
{
  int i;
  for(i=0;i<10;i++)
  table[i]=-1;
}

int hash1(int k)
{
  int ans=k%10;
  return ans;
}

int hash2(int k2)
{
  int prime=7; //Changes upon change in table_size
  int a=prime-(k2%prime);
  return a;
}

void hash(int key)
{
  int index1=hash1(key);
  if(table[index1]!=-1)
  {
    int index2=hash2(key);
    int i=1;
    while(1)
    {
    int newindex=(index1+(i*index2))%10;
      if(table[newindex]==-1)
      {
        table[newindex]=key;
        break;
      }
      i++;
    }
  }
  
  else
  table[index1]=key;
}

void display()
{
	int i;
	for(i=0;i<10;i++)
	cout<<table[i]<<"\t";
	cout<<endl;
}

};

int main()
{
  hashtable h;
  h.initialize();
	cout<<"Enter the elements"<<endl;
	cout<<"Enter 0 to exit"<<endl;
	int n=1,s=0;

	while(n!=0)
	{
	  cin>>n;
		if(n!=0)
		{	
	    s++;
	    if(s==10)
	    break;
	    h.hash(n);
	  }
	}
	
	h.display();
	return 0;
}
