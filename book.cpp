#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
char fnameB[100]="book_record.txt";

struct BookR{
	char id[20],Title[20], Author[20], Genre[20], Editor[20];
};
class Book{
	public:
		void pack(BookR r);
		BookR unpack(char a[] );
		void AddBook();
		void ShowB();
};

void Book::pack(BookR r){
	fstream fp;
	fp.open(fnameB,ios::out|ios::app);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	char dataB[45];
	strcpy(dataB,r.id);
	strcat(dataB,"|");
	strcat(dataB,r.Title);
	strcat(dataB,"|");
	strcat(dataB,r.Author);
	strcat(dataB,"|");
	strcat(dataB,r.Genre);
	strcat(dataB,"|");
	strcat(dataB,r.Editor);
	strcat(dataB,"|*");
	fp<<dataB<<endl;
	fp.close();
}

BookR Book::unpack(char dataB[]){
		BookR r;
	int i=0,j=0;
	while(dataB[j]!='|')
		r.id[i++]=dataB[j++];
	r.id[i]='\0';
	i=0;
	j++;
	while(dataB[j]!='|')
		r.Title[i++]=dataB[j++];
	r.Title[i]='\0';
	i=0;
	j++;
	while(dataB[j]!='|')
		r.Author[i++]=dataB[j++];
	r.Author[i]='\0';
	i=0;
	j++;
	while(dataB[j]!='|')
		r.Genre[i++]=dataB[j++];
	r.Genre[i]='\0';
	i=0;
	j++;
	while(dataB[j]!='|')
		r.Editor[i++]=dataB[j++];
	r.Editor[i]='\0';
	return(r);
}

void Book::AddBook(){
	BookR r;
	cout<<"\nEnter ID:";
	cin>>r.id;
	cout<<"\nEnter Title:";
	cin>>r.Title;
	cout<<"\nEnter Author:";
	cin>>r.Author;
	cout<<"\nEnter genre:";
	cin>>r.Genre;
	cout<<"\nEnter Editor:";
	cin>>r.Editor;
	pack(r);
}
void Book::ShowB()
{
	fstream fp;
	char dataB[500];
	BookR r;
	fp.open(fnameB,ios::in);
	if(fp==NULL)
	{
		cout<<"\ncan not open file";
		exit(0);
	}
	while(1)
	{
		fp.getline(dataB,500,'*');
		if(fp.eof())break;
		r=unpack(dataB);
		cout<<r.id<<"\tTitle: "<<r.Title<<"\tAuthor: "<<r.Author<<"\tGenre: "<<r.Genre<<"\tEditor: "<<r.Editor<<endl;

	}
	fp.close();
	return;
}
