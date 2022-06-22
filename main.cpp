
#include"Contact.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {

	while(1)
	{
	
	//return 0;
	int ch;
	
	cout<<"select choice:"<<endl;
	cout<<"1. Add contact  2.Display All   3.Search Contact   4.Delete Contact   5.Exit"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			int id;
			char name[50],email[50],phone[12],fb[50],city[50];
			
			cout<<"Enter ID: ";
			cin>>id;
			cout<<"enter name: ";
			cin>>name;
			cout<<"Enter email: ";
			cin>>email;
			cout<<"Enter phone: ";
			cin>>phone;
			cout<<"Enter FB: ";
			cin>>city;
			Contact c1( id,name,email,phone,fb,city);
	        addContact(c1);
	        
	        
		}
		break;
		case 2:
			{
				dispAll();
				
			}
			break;
		case 3:
		{
			int id;
			
			cout<<"Enter the id Searched for:";
			cin>>id;
			
			search(id);
			
			}
			break;
		
		case 4:
			{
				int id;
				cout<<"Enter the id to be deleted for:";
				cin>>id;
				deleteRecord(id);
				
			}
		break;
		
		case 5:
		{
			exit(0);
			
		}	
			
		}
		
	}


}
