/*
Name:Shardul Pathak
Roll no:222021
Gr No:17u666
Batch:B1
*/

#include<iostream>
using namespace std;

void display(int size,int a[])
{
  int i;
  for(i=0;i<size;i++)
  cout<<a[i]<<"\t";
}

int create(int size,int arr[])
{
  int i;
  for(i=0;i<size;i++)
  cin>>arr[i];
  return (arr[size]);
}

int insert(int num,int size,int arr[])
{
	arr[size]=num;
	return(arr[size]);
}

int remove(int size,int arr[])
{
	int i,n;
	cout<<"Enter the number to be deleted"<<endl;
	cin>>n;
	for(i=0;i<size;i++)
	{
		if(arr[i]==n)
		break;
	}	
	while(i<size)
	{
		arr[i]=arr[i+1];
		i++;
	}	
	size--;
	return(arr[size]);
}

void search(int size,int arr[])
{
	int num,i;
	cout<<"Enter the element to be searched"<<endl;
	cin>>num;
	for(i=0;i<size;i++)
	{
		if(arr[i]==num)
		{
		cout<<"Element found at "<<i<<endl;
		break;
		}
	}	
}

void inter(int size1,int arr1[],int size2,int arr2[])
{
	int num,i,j,k=0;
	num=size1>=size2?size1:size2;
	int res[num];
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			if(arr1[i]==arr2[j])
			{
				res[k]=arr1[i];
				k++;
			}
		}
	}
	
	cout<<"The intersection of the two sets give"<<endl;
	for(i=0;i<k;i++)
	cout<<res[i]<<"\t"<<endl;
}

void unify(int size1,int arr1[],int size2,int arr2[])
{
	int num,i,j,k=0,flag;
	num=size1+size2;
	int res[num];
	for(i=0;i<size1;i++)
	{
		res[i]=arr1[i];
		k++;
	}	
	for(i=0;i<size2;i++)
	{
		flag=0;
		for(j=0;j<size1;j++)
		{
			if(arr2[i]!=res[j])
			flag++;
		}
		if(flag==size1)
		{
			res[k]=arr2[i];
			k++;
		}	
	}
	for(i=0;i<k;i++)
	cout<<res[i]<<"\t"<<endl;
}

void diff(int size1,int arr1[],int size2,int arr2[])
{
  int i,j,flag;
  cout<<"A - B"<<endl;
  for(i=0;i<size1;i++)
  {
    flag=0;
    for(j=0;j<size2;j++)
    {
      if(arr1[i]!=arr2[j])
      flag++;
    }
    if(flag==size1)
    cout<<arr1[i]<<" ";
  }
  cout<<endl;
   cout<<"B - A"<<endl;
  for(i=0;i<size2;i++)
  {
    flag=0;
    for(j=0;j<size1;j++)
    {
      if(arr2[i]!=arr1[j])
      flag++;
    }
    if(flag==size1)
    cout<<arr2[i]<<" ";
  }
  cout<<endl;
  
}

void subset(int size1,int arr1[],int size2,int arr2[])
{
	int i,j,flag=0;

  for(i=0;i<size1;i++)
  {
    for(j=0;j<size2;j++)
    {
      if(arr1[i]==arr2[j])
         flag++;
    }	
  }
  if(flag==size1)
	cout<<"A is a subset of B"<<endl;

flag=0;	
for(i=0;i<size2;i++)
  {
    for(j=0;j<size1;j++)
    {
      if(arr2[i]==arr1[j])
      flag++;
    }
  }
  if(flag==size2)
	cout<<"B is a subset of A"<<endl;
	
}

int main()
{
  int i,m,n,choice;
  char ch,c;
  cout<<"Enter number of elements in set A"<<endl;
  cin>>m;
  cout<<"Enter number of elements in set B"<<endl;
  cin>>n;
  int a[m],b[n];
  cout<<"Enter elements of set A"<<endl;
  a[m]=create(m,a);
  cout<<"Enter elements of set B"<<endl;
  b[n]=create(n,b);
  cout<<"Elements of set A are : ";
  display(m,a);
  cout<<"\nELements of set B are : ";
  display(n,b);
  do{
  	cout<<"\nEnter\n1.Insert\n2.Delete\n3.Search\n4.Size\n5.Intersection\n6.Union\n7.Difference\n8.Subset"<<endl;
  	cin>>choice;
  	switch(choice)
  	{
  		case 1:
  		{
  			int elm;
  			cout<<"Enter the element to be inserted"<<endl;
  			cin>>elm;
  			cout<<"Enter the set in which you want to enter this element(A/B)"<<endl;
  			cin>>c;
  			if((c=='a')||(c=='A'))
  			{
  			a[m]=insert(elm,m++,a);
  			display(m,a);
  			cout<<endl;
  			}
  			else if((c=='b')||(c=='B'))
  			{
  			b[n]=insert(elm,n++,b);
  			display(n,b);
  			cout<<endl;
  			}
  		}
  		break;
  		case 2:
  		{
  			cout<<"Enter the set to delete the element"<<endl;
  			cin>>c;
  			if((c=='a')||(c=='A'))
  			{
  				a[m]=remove(m--,a);
  				display(m,a);
  				cout<<endl;
  			}	
  			else if((c=='b')||(c=='B'))
  			{
  				b[n]=remove(n--,b);
  				display(n,b);
  				cout<<endl;
  			}
  		}
  		break;
  		case 3:
  		{
  			cout<<"Enter the set to search the element"<<endl;
  			cin>>c;
  			if((c=='a')||(c=='A'))
  				search(m,a);	
  			else if((c=='b')||(c=='B'))
  				search(n,b);
  		}
  		break;
  		case 4:
  		{
  			cout<<"Enter the set to find its size"<<endl;
  			cin>>c;
  			if((c=='a')||(c=='A'))
  				cout<<"Size is "<<m<<endl;	
  			else if((c=='b')||(c=='B'))
  				cout<<"Size is "<<n<<endl;	
  		
  		}
  		break;
  		case 5:
  		{
  			inter(m,a,n,b);
  		}
  		break;
  		case 6:
  		{
  			unify(m,a,n,b);
  		}
  		break;
		  case 7:
		  {
		  	diff(m,a,n,b);
		  }
		break;
		case 8:
		{
			subset(m,a,n,b);
		}
		break;
		default:
		cout<<"Invalid option"<<endl;
  	}
  	cout<<"Do you want to continue?"<<endl;
  	cin>>ch;
  }
  while (ch=='y');
  return 0;
}

