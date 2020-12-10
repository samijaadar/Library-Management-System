#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include "book.cpp"

using namespace std;
char fnameC[100]="client_record.txt";
struct ClientR
{
	char id[5],name[15],age[5],sex[5],telephon[15],Bid[10];
};
class Client
{
public: void pack(ClientR r);
		ClientR unpack(char a[]);
		void AddClient();
		void ShowC();
		int authen();
};

void Client::pack(ClientR r)
{
	fstream fp;
	fp.open(fnameC,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char dataC[45];
	strcpy(dataC,r.id);
	strcat(dataC,"|");
	strcat(dataC,r.name);
	strcat(dataC,"|");
	strcat(dataC,r.age);
	strcat(dataC,"|");
	strcat(dataC,r.sex);
	strcat(dataC,"|");
	strcat(dataC,r.telephon);
	strcat(dataC,"|");
	strcat(dataC,r.Bid);
	strcat(dataC,"|*");
	fp<<dataC<<endl;
	fp.close();
}
ClientR Client::unpack(char dataC[])
{
	ClientR r;
	int i=0,j=0;
	while(dataC[j]!='|')
		r.id[i++]=dataC[j++];
	r.id[i]='\0';
	i=0;
	j++;
	while(dataC[j]!='|')
		r.name[i++]=dataC[j++];
	r.name[i]='\0';
	i=0;
	j++;
	while(dataC[j]!='|')
		r.age[i++]=dataC[j++];
	r.age[i]='\0';
	i=0;
	j++;
	while(dataC[j]!='|')
		r.sex[i++]=dataC[j++];
	r.sex[i]='\0';
	i=0;
	j++;
	while(dataC[j]!='|')
		r.telephon[i++]=dataC[j++];
	r.telephon[i]='\0';
	i=0;
	j++;
	while(dataC[j]!='|')
		r.Bid[i++]=dataC[j++];
	r.Bid[i]='\0';
	return(r);
}
void Client::AddClient()
{
	ClientR r;
	Book b;
	cout<<"\nEnter ID:";
	cin>>r.id;
	cout<<"\nEnter Name:";
	cin>>r.name;
	cout<<"\nEnter Age:";
	cin>>r.age;
	cout<<"\nEnter Sex (M/F):";
	cin>>r.sex;
	cout<<"\nEnter Telephon Number:";
	cin>>r.telephon;
	b.ShowB();
	cout<<"\nEnter book id:";
	cin>>r.Bid;
	pack(r);
}
void Client::ShowC()
{
	fstream fp;
	char dataC[500];
	ClientR r;
	fp.open(fnameC,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	while(1)
	{
		fp.getline(dataC,500,'*');
		if(fp.eof())break;
		r=unpack(dataC);
		cout<<r.id<<"\tName: "<<r.name<<"\tAge: "<<r.age<<"\tSex: "<<r.sex<<"\tContact: "<<r.telephon<<"\tBookId: "<<r.Bid<<endl;
	
	}
	fp.close();
	return;
}
int Client::authen()
{
	system("CLS");
	char o_username[20],o_password[20];
	char o_user[20]="admin",o_pass[20]="admin";
	cout<<endl<<endl;
	cout.width(25);
	cout<<"Enter Admin id and Password\n"<<"------------------------------------------------------------------------------------\n";
	cout<<endl<<"username: ";
	cin>>o_username;
	cout<<"password: ";
	cin>>o_password;
	cout<<"------------------------------------------------------------------------------------\n";
	if(strcmp(o_username, o_user)==0 && strcmp(o_password, o_pass)==0)
		return 1;
	else
		return 0;
}
