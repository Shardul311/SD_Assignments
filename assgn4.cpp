/*
Name:Shardul Pathak
Roll no:222021
Gr No:17u666
Batch:B1
*/

#include<iostream>
using namespace std;

class primsalgo
{
  int p[20],d[20],visited[20],weight[20][20],v;
  char n;
  public :
  
  void create()
  {
    cout<<"Enter number of vertices in the graph"<<endl;
    cin>>v;
    int i,j,a,b,w;
    for(i=0;i<v;i++)
    {
      for(j=0;j<v;j++)
      {
        weight[i][j]=0;
      }
        p[i]=0;
        d[i]=1000;
        visited[i]=0;
    }     
    
    do
    {
      cout<<"Enter the edge vertices and weight in the format a-b-weight"<<endl;
      cin>>a>>b>>w;
      weight[a][b]=w;
      cout<<"Do you want to give another input?"<<endl;
      cin>>n;	  
    }  
    while(n=='y');
  }  
    
    void prim()
    {
      int i,j,min,k,m,n;
      for(i=0;i<v;i++)
      {
        for(j=0;j<v;j++)
        {
          if(weight[i][j]!=0)
	{
          if(visited[j]==0)
	{
          if(weight[i][j]<d[j])
          {
            d[j]=weight[i][j];
            p[j]=i;
          }
	}
	}
         }
         
         min=d[0];
         
         for(k=0;k<v;k++)
         {
          if(min<d[k])
          min=d[k];
         }
         
         for(m=0;m<v;m++)
         {
          for(n=0;n<v;n++)
          {
            if(weight[m][n]==min)
            break;
          }
         }
         
         visited[j]=1;
        }    
    } 
    
    void display()
    {
      int i,sum=0;
	d[0]=0;
      cout<<"The cost of the minimum spanning tree is"<<endl;
      for(i=0;i<v;i++)
      	sum=sum+d[i];
      cout<<sum;
      cout<<endl;
      for(i=0;i<v;i++)
      cout<<"The edge exists between "<< i <<"and "<<p[i]<<endl;
    }
};

int main()
{
  primsalgo p;
  p.create();
  p.prim();
  p.display();

  return 0;
}


