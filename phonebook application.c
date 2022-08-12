#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct person {
	
    char name[35];
    char address[50];
    char phone[11];   
};
    
void menu();
void got();
void start();
void back();
void add();
void showall();
void del();
void search();

int main() {
    system("color 5f");
    start();
    return 0;
}

void back() {
    start();
}

void start() {
    menu();
}

void menu() {
	
    system("cls");
	printf("\n   **********WELCOME TO PHONEBOOK*************");

	printf("\n\n\t  MENU\t\t\n\n");
	printf("\n\t1.Create New   \n\t2.Show All   \n\t3.Search  \n\t4.Delete \n\t5.Exit");

	switch(getch()) {
		
    	case '1': add();
    			  break;
   		case '2': showall();
    			  break;
    	case '3': search();
    			  break;
    	case '4': del();
    			  break;
    	case '5': exit(0);
    			  break;
    	default:
                system("cls");
                printf("\n\tEnter 1 to 5 only");
                printf("\n\tEnter any key");
                getch();
				menu();
	}
}

void add() {
	
        system("cls");
        FILE *f;
        struct person p;
        f = fopen("phonebook","ab+");
        
        printf("\n Enter name: ");
        got(p.name);
        printf("\n Enter the address: ");
        got(p.address);
        printf("\n Enter phone no.: ");
        got(p.phone);
        
        fwrite(&p,sizeof(p),1,f);

    	fflush(stdin);
        printf("\n Record saved");

		fclose(f);

    	printf("\n\n Enter any key");
	 	getch();
    	system("cls");
    	menu();
}

void showall(){
    struct person p;
    FILE *f;
	f = fopen("phonebook","rb");
	
	if(f == NULL) {
		printf("\n File opening error: ");
		exit(1);
	}
	
	while(fread(&p,sizeof(p),1,f)==1) {
		
    	printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\n Name= %s\n Adress= %s\n Phone no= %s",p.name,p.address,p.phone);

		getch();
		system("cls");
	}
	fclose(f);
 	printf("\n Enter any key");
 	getch();
    system("cls");
	menu();
}

void search() {
    struct person p;
	FILE *f;
	char name[100];

	f=fopen("phonebook","rb");
	if(f==NULL) {
    	printf("\n Error");
    	exit(1);
	}
	printf("\n Enter name of person to search\n");
	got(name);
	while(fread(&p,sizeof(p),1,f)==1) {
    	if(strcmp(p.name,name)==0) {
        	printf("\n\tDetail Information About %s",name);
        	printf("\n Name: %s\n Address: %s\n Phone no: %s",p.name,p.address,p.phone);
    	}
        else
        	printf("\n File not found");
}
 	fclose(f);
  	printf("\n Enter any key");

	getch();
    system("cls");
	menu();
}

void del() {
	
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("phonebook","rb");
	if(f==NULL)
		{

			printf("\n DATA NOT FOUND.");

		} else {
			ft=fopen("temp","wb+");
			if(ft==NULL)

            printf("\n Error!!");
		else

        {


		printf("\n Enter CONTACT'S NAME:");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1) {
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
		
		fclose(f);
		fclose(ft);
		if(flag!=1) {
			printf("\nNO CONACT'S RECORD TO DELETE.");
			remove("temp.txt");
		} else {
			remove("phonebook");
			rename("temp.txt","phonebook");
			printf("\n RECORD DELETED SUCCESSFULLY.");
		}
	}
}
 	printf("\n Enter any key");

	getch();
    system("cls");
	menu();
}

void got(char *name) {

    int i=0,j;
    char c,ch;
    do {
        c=getch();
                if(c!=8&&c!=13)
                {
                    name[i]=c;
                    putch(c);
                    i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   
                    system("cls");
                    for(j=0;j<i;j++) {
                        ch = name[j];
                        putch(ch);
                    }
                }
    }while(c!=13);
      name[i]='\0';
}
