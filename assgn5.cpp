/*
Name:Shardul Pathak
Roll no:222021
Gr No:17u666
Batch:B1
*/

#include<iostream>
using namespace std;

class  kruskalsalgo
{
  int d[20],visited[20],weight[20][20],dist[20],v;
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
        d[i]=0;
        visited[i]=0;
        dist[i]=0;
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
    
    void kruskal()
    {
      int i,j,min,k=0,m=0,n,temp;
      for(i=0;i<v;i++)
      {
        for(j=0;j<v;j++)
        {
          if(weight[i][j]!=0)
          {
            d[k]=weight[i][j];
            k++;
          }
        }
      }
      
      for(i=0;i<k+1;i++)
      {
        for(j=0;j<k+1;j++)
        {
          if(d[i]<d[j])
          {
            temp=d[i];
            d[i]=d[j];
            d[j]=temp;
          }
        }
      }
      
      for(i=0;i<v;i++)
      {
        for(j=0;j<v;j++)
        {
        if(weight[i][j]==d[m])
        {
          if(visited[j]==0)
          {
            dist[m]=d[m];
            m++;
            visited[j]=1;
          }
        }
        }
      }
      
    } 
    
    void display()
    {
      int i,sum=0;
      cout<<"The cost of the minimum spanning tree is"<<endl;
      for(i=0;i<v;i++)
      	sum=sum+dist[i];
      cout<<sum;
      cout<<endl;
    }
};

int main()
{
  kruskalsalgo k;
  k.create();
  k.kruskal();
  k.display();

  return 0;
}

