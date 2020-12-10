#include<iostream>
#include<string.h>
#include<fstream>
#include "client.cpp"


using namespace std;


void menu();
void admin();


int main(){
	int x,i,choice,choice2;
	Book b;
	Client ad;
	Client c;
	while(x!=5){
		menu();
		printf("\t Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:system("cls");c.AddClient();break;
			
			case 2:system("cls");b.ShowB();break;
			
			case 3:int check;
                        check=ad.authen();
                        if(check == 1)
                        {
                              
						admin() ;
						printf("\t Enter your choice: ");
						scanf("%d",&choice2);
						switch(choice2){
							case 1:b.AddBook();system("cls");break;
							case 2:system("cls");c.ShowC() ;break;
							case 3:system("cls");break;
						}
				break;
                        }
                        else
                                cout<<endl<<"Invalid Username or Password!! Please try again...";
		
	break;
			case 4: exit(0) ;break;
			default : printf("Error");
		}
			}
			return 0;
}

void menu(){
	printf("\n\t------------------------------------------------\n");
	printf("\t\t welcome");
	printf("\n\t------------------------------------------------\n");
	printf("             1:Book ticket \n");
	printf("             2:Display Books \n");
	printf("             3:Admin\n");
	printf("             4:Exit \n");
	printf("\t================================================\n\n\n");
}
void admin(){
	system("cls");
	printf("\n\t------------------------------------------------\n");
	printf("\t\t Admin :");
	printf("\n\t------------------------------------------------\n");
	printf("             1: Add Book\n");
	printf("             2:Display user tickets \n");
	printf("             3: Exit \n");
	printf("\t================================================\n\n\n");
}
