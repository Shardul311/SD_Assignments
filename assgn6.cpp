/*
Name:Shardul Pathak
Roll no:222021
Gr No:17u666
Batch:B1
*/

#include <iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int largest =i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    int temp;
 
    if((l<n)&&(arr[l]>arr[largest]))
        largest =l;
 
    if((r<n)&&(arr[r]>arr[largest]))
        largest = r;
 
    if(largest!=i)
    {
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n)
{
  int i,temp;
    for(i=(n/2)-1;i>=0;i--)
        heapify(arr,n,i);
 
    for(i=n-1;i>=0;i--)
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
    }
}

int main()
{
    int n;
    cout<<"Enter number of students"<<endl;
    cin>>n;
    int arr[n],i;
    cout<<"Enter the marks"<<endl;
    for(i=0;i<n;i++)
    cin>>arr[i];
    heapSort(arr,n);
    cout<<"Sorted array is"<<endl;
      for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
