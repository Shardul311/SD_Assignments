/*
Name:Shardul Pathak
Roll no:222021
Gr No:17u666
Batch:B1
*/

#include<iostream>
#include<fstream>
using namespace std;

class Student
{
    int rollno;
    char name[20];
    char div;
    char address[50];
public:

  void setData()
    {
       cout<<"Enter required details"<<endl;
       cout<<"Roll number :\t";
       cin>>rollno;
       cout<<"Name :\t";
       cin>>name;
       cout<<"Division :\t";
       cin>>div;
       cout<<"Address :\t";
       cin>>address;
    }

   void showData()
    {
	     cout<<"--------------------------------------------------"<<endl;
       cout<<"Student details are as follows : "<<endl;
       cout<<"Roll number :\t"<<rollno<<endl;
       cout<<"Name :\t"<<name<<endl;
       cout<<"Division :\t"<<div<<endl;
       cout<<"Address :\t"<<address<<endl;
       cout<<"--------------------------------------------------"<<endl;
    }
	 
    int ret_rollno()
    {
        return rollno;
    }
};

  void write_record()
  {
    ofstream out;
    out.open("student.dat",ios::binary|ios::app);

    Student obj;
    obj.setData();
    
    out.write((char*)&obj, sizeof(obj));
    
    out.close();
  }

  void display()
  {
    ifstream inFile;
    inFile.open("student.dat", ios::binary);

    Student obj;
    
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData();
    }        
    
    inFile.close();
  }

  void search(int n)
  {
    int flag=0;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    
    Student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.ret_rollno() == n)
        {
            obj.showData();
            flag=1;
        }
    }
    
    if(flag==0)
    cout<<"No student database found"<<endl;  
    inFile.close();
  }

  void delete_record(int n)
  {
    int flag=0;
    Student obj;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.ret_rollno() != n)
        {
            outFile.write((char*)&obj, sizeof(obj));
            flag=1;
        }
    }

    inFile.close();
    outFile.close();
    
    remove("student.dat");
    rename("temp.dat", "student.dat");
    
    if(flag==0)
    cout<<"No student database found"<<endl;
    else
    cout<<"Record Deleted"<<endl;
  }

  void modify_record(int n)
  {
	int flag=0;
    fstream file;
    file.open("student.dat",ios::in | ios::out);

    Student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {   
        if(obj.ret_rollno() == n)
        {
            cout<<"Please enter new details"<<endl;
            obj.setData();
            
            int pos=(-1*sizeof(obj));
            file.seekp(pos, ios::cur);
			
            file.write((char*)&obj, sizeof(obj));
            flag=1;
        }
    }
    
    if(flag==0)
    cout<<"No student database found"<<endl;
    file.close();
  }

int main()
{
  int n,i,s,d,m;
  int choice;
  char ans;
  
  cout<<"Enter number of entries"<<endl;
  cin>>n;
  for(i=0;i<n;i++)
  write_record();
  
	do
	{
    cout<<"Enter\n1.Display\n2.Search\n3.Delete\n4.Modify"<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:
      {
        display();
      }
      break;
      
      case 2:
      {
        cout<<"Enter the roll number to search for data"<<endl;
        cin>>s;
        cout<<"Search result : "<<endl;
        search(s);
      }
      break;
      
      case 3:
      {
        cout<<"Enter the number to be deleted"<<endl;
	      cin>>d;
        delete_record(d);
      }
      break;
      
      case 4:
      {
        cout<<"Enter the record to be modified"<<endl;
	      cin>>m;
        cout<<"Modified Record : "<<endl;
        modify_record(m);
      }
      break;
      
      default:
      cout<<"Invalid input"<<endl;
      
    }
    cout<<"Any further operations?"<<endl;
    cin>>ans;
  }
  while(ans=='y');		
  return 0;
}
