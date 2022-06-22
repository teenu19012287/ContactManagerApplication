#include<iostream>
using namespace std;
#include<fstream>
#include<cstring>


class Contact
{
	int id;
	char name[40];
	char email[40];
	char mobile[12];
	char fbID[40];
	char instaID[40];
	char address[100];
	public:
	Contact()
	{
		
	}
	Contact(int cid,const char* cname,const char* cemail,const char* cmobile,const char * cfbID,const char * caddr)
	{
		id = cid;
	
		strcpy(mobile,cmobile);
		strcpy(name,cname);
		strcpy(fbID,cfbID);
		strcpy(email,cemail);
		strcpy(address,caddr);
		
	}
	
	void disp()
	{
		cout<<"ID: "<<id<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Address: "<<address<<endl;
		
		cout<<"Email: "<<email<<endl;
		cout<<"Mobile: "<<mobile<<endl;
		cout<<"Facebook ID: "<<fbID<<endl;
	//	cout<<"City: "<<address<<endl;
		
		cout<<"============================\n";
		
		
	}
	friend void search (int id);
	
	friend void deleteRecord(int id);
	

};

void addContact(Contact c)
{
	ofstream fout("contacts.dat",ios::app);
	fout.write((char*)&c,sizeof(c));
	fout.close();
	cout<<"Contact added successfully"<<endl;
	
}
void dispAll()
{
	Contact temp;
	ifstream fin("contacts.dat");
	while(1)
	{
		fin.read((char*) &temp,sizeof(temp));
		if(fin.eof())
		{
			break;
			
		}
		else
		{
			temp.disp();
			
		}
	}
}


void search(int id)
{
	ifstream fin("contacts.dat");
	Contact temp;
	while(1)
	{
		fin.read((char*)&temp,sizeof(temp));
		if(fin.eof() )
		{
			break;
			
		}
		if(temp.id == id)
		{
			cout<<"Record found: "<<endl;
			temp.disp();
			
		}
	}
}



void deleteRecord(int id)
{
	
	ifstream  fin("contacts.dat");
	ofstream fout("temp.dat");
	
	Contact obj;
	
	
	while(1)
	{
		fin.read((char*)&obj,sizeof(obj));
		if(fin.eof())
		{
			break;
			
		}
		else
		{
			if(obj.id!=id)
			{
				fout.write((char*)&obj,sizeof(obj));
				
			}
		}
	}
	fin.close();
	fout.close();
	
	remove("contacts.dat");
	rename("temp.dat","contacts.dat");
	
}








