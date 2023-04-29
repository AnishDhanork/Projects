#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
// C program to create loading bar
#include <windows.h>
  
using namespace std;
static int p=0;
class a
{
		char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
		void admin_login();
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void search();
		void position(int i);
}bus[10];//here we declare the number of buses we can have.-
// Function to creating loading bar
void loadingBar()
{
    system("color 0A");
    char a = 177, b = 219;
  
    cout<<"\n\n\n\n";
    cout<<"\n\n\n\n\t\t"<< "Loading...\n\n";
    cout<<"\t\t\t";
    for (int i = 0; i < 20; i++)
        cout<<"--"<< a;
    cout<<"\r";
    cout<<"\t\t\t";
    for (int i = 0; i < 20; i++) {
        cout<<"--"<< b;
        Sleep(100);
    }
}
void exitBar()
{
    system("color 0B");
    char a = 177, b = 219;
  
    cout<<"\n\n\n\n";
    cout<<"\n\n\n\n\t\t"<< "Exit...\n\n";
    cout<<"\t\t\t";
    for (int i = 0; i < 20; i++)
        cout<<"--"<< a;
    cout<<"\r";
    cout<<"\t\t\t";
    for (int i = 0; i < 20; i++) {
        cout<<"--"<< b;
        Sleep(100);
    }
}
void vline(char ch)
{
	for (int i=80;i>0;i--)
		{
			cout<<ch;
		}
}
void logo()
{
    cout<<"\t\t\t _____________________________________________________\n";
  	cout<<"\t\t\t )           __________________                      (\n";
  	cout<<"\t\t\t(            |________________|              O        )\n";
  	cout<<"\t\t\t )           |   BUS TICKET   |                      (\n";
  	cout<<"\t\t\t(          |||           ___  |||            O        )\n";
  	cout<<"\t\t\t )           |___________|_|__|                      (\n";
  	cout<<"\t\t\t(            |__            __|              O        )\n";
  	cout<<"\t\t\t )           |__)  _______ (__|                      (\n";
  	cout<<"\t\t\t(            |________________|              O        )\n";
  	cout<<"\t\t\t )              |__|    |__|                         (\n";
  	cout<<"\t\t\t(                                            O        )\n";
    cout<<"\t\t\t )___________________________________________________(\n";
}
void a:: admin_login()
{
	cout<<"\nIn Admin\n";
	int w;
	logo();
		do
			{		
				cout<<"\n\n\n\n";
				cout<<"\t\t\t 1.Install \n\t\t\t  2.Show \n\t\t\t 3.Buses Available. \n\t\t\t 4.Exit";
				cout<<"\n\t\t\t Enter your choice:-> ";
				cin>>w;
				switch(w)
				{
					case 1:
					bus[p].install();
					break;
					case 2:
					bus[0].show();
					break;
					case 3:
					bus[0].avail();
					break;
					case 4:
						cout<<"EXIT ADMIN";
					break;
						
				}
			}while(w!=4);
}

void a::install()
{
	cout<<"Enter bus no: ";
	cin>>bus[p].busn;
	cout<<"\n Enter Driver's name: ";
	cin>>bus[p].driver;
	cout<<"\n Arrival time: ";
	cin>>bus[p].arrival;
	cout<<"\n Departure: ";
	cin>>bus[p].depart;
	cout<<"\n From: \t\t\t";
	cin>>bus[p].from;
	cout<<"\n To: \t\t\t";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void a::allotment()
{
	int seat,ch;
	char number[5];
	top:
	cout<<"Do you want to see the available buses?\n If yes enter 1";
	cin>>ch;
	if(ch==1)
	{
		avail();
	}
	cout<<"Bus no: ";
	cin>>number;
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		cout<<"\n Seat number: ";
		cin>>seat;
		if (seat>32)
			{
				cout<<"\n There are only 32 seats available in this bus.";
			}
		else
			{
			if (strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
				{
					cout<<"Enter passanger's name: ";
					cin>>bus[n].seat[seat/4][(seat%4)-1];
					break;
				}
			else
				cout<<"The seat no. is already reserved.\n";
			}
	}
	if (n>p)
	{
		cout<<"Enter correct bus no.\n";
		goto top;
	}
}
void a::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}
void a::show()
{
	int n;
	char number[5];
	cout<<"Enter bus no: ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
			break;
	}
	while (n<=p)
	{
		vline('*');
		cout<<" \n Bus no: \t"<<bus[n].busn
		<<"\n Driver: \t"<<bus[n].driver<<"\t\t Arrival time:\t"
		<<"\n From:\t\t"<<bus[n].from<<"\t\t To: \t\t\t"<<
		bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1;
		for (int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
					cout<<"\n The seat no "<<a-1<<" is reserved for "<<bus[n].seat[i][j]<<" .";
			}
		}break;
	}	if(n>p)
			cout<<"enter correct bus no.";
}
void a::position(int l)
{
	int s=0,p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j],"Empty")==0)
				{
					cout.width(5);
					cout.fill(' ');
					cout<<s<<".";
					cout.width(10);
					cout.fill(' ');
					cout<<bus[l].seat[i][j];
					p++;
				}
			else
				{
					cout.width(5);
					cout.fill(' ');
					cout<<s<<".";
					cout.width(10);
					cout.fill(' ');
					cout<<bus[l].seat[i][j];
				}
		}
	}
		cout<<"\n\n There are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}
void a::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"\n Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time:\t"<<bus[n].arrival<<"\tDeparture Time: \t"<<bus[n].depart<<"\n From: \t\t"<<bus[n].from<<"\t\t To: \t\t\t"<<bus[n].to<<"\n";
		cout<<"\n";
		vline('*');
		cout<<"\n";
		vline('_');cout<<"\n";
	}
}
void a ::search()
{
	cout<<"\n\t\t Search Category";
	string i,j;
			cout<<"\n\t\tSearch FROM";
			
			int n;
			cout<<"\n\t\t\tENTER FROM WHERE YOU WANT TO START";
			cin>>i;
			cout<<"\n\t\t\tENTER FROM WHERE YOU WANT TO GO";
			cin>>j;
			for(n=0;n<=p;n++)
				{
					if(bus[n].from==i)
					{
						if(bus[n].to==j)
						break;
					}		
				}
			while (n<=p)
			{
				vline('*');
				cout<<" \n Bus no: \t"<<bus[n].busn
				<<"\n Driver: \t"<<bus[n].driver<<"\t\t Arrival time:\t"
				<<"\n From:\t\t"<<bus[n].from<<"\t\t To: \t\t\t"<<
				bus[n].to<<"\n";
			    vline('*');
			break;
			}
			if(n>p)
				cout<<"\n\t\tEnter correct bus no.";
}
int main()
{
    loadingBar();
    a obj;
	int w;
	string pass;
	system("color 8F");
	cout<<"\n";
    logo();
	while(1)
	{
		cout<<"\n";
		vline('*');
		cout<<"\nLogin";
		cout<<"\n 1. Admin Login"<<endl;
		cout<<"2. User login"<<endl;
		vline('*');
		int ch;
		cout<<"\n";
		
	    cin>>ch;
		if(ch==1)
		{
			while(1)
			{
				cout<<"\nENTER PASSWORD FOR ADMIN LOGIN\n";
				cin>>pass;
				cout<<endl<<pass;
				if(pass=="Admin")
				{
					cout<<"correct password";
					obj.admin_login();
					break;
				}
				else
				{
					cout<<"Try Again!!!";
				}
			}		
			
		}
		else
		{
			vline('*');
			cout<<"\n";
			logo();
			cout<<"\nlogin";
	    	cout<<"\n User Login";
			cout<"\nbyfknjyf";
			cout<<"\n";
			vline('*');
			while(1)
			{
				cout<<"\n\n\n\n";
				cout<<"\t\t\t 1.Reservation\n\t\t\t 2.Show \n\t\t\t 3.Buses Available. \n\t\t\t 4.Search routes. \n\t\t\t 5.Exit";
				cout<<"\n\t\t\t Enter your choice:-> ";
				cin>>w;
				switch(w)
				{
					case 1:
						bus[p].allotment();
					break;
					case 2:
						bus[0].show();
					break;
					case 3:
						bus[0].avail();
						break;
					case 4:
						obj.search();
						break;
					case 5:	
					exitBar();
					exit(0);
		
				}
			}
			break;
		}
	}	
	return 0;
}

