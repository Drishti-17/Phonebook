#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
void menu(void);
void password(void);
void addnew(void);
void search(void);
void list(void);
void deletevalue(void);
void exit(void);

int main(){
	password();
}

void addnew(){
	system("cls");
	FILE *fptr;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[20];
	fptr=fopen("phonebook.txt","ab+");
	if(fptr==NULL){
		printf("File creation unsuccessful");
	}
	else{
		printf("Enter the new data\n");
		printf("Name:-");
		scanf("%s",name);
		printf("Address:-");
		scanf("%s",address);
		printf("Gender:-");
		scanf("%s",gender);
		printf("Gmail:-");
		scanf("%s",gmail);
		printf("Phone Number:-");
		scanf("%lf",&phone);
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		printf("Data added successfully\n");
	}
	fclose(fptr);
	char ch;
	printf("Enter y for menu option.");
	while((ch=getch())=='y'){
		menu();
	}
}

void search(){
	FILE *fptr;
	int flag=0;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[20];
	char name1[100];
	system("cls");
	printf("Enter the name of the person you want to see the detail of:  ");
	scanf("%s",name1);
	fptr=fopen("phonebook.txt","r");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		if(strcmp(name,name1)==0){
			printf("Record Found\n");
			printf("----------------------------------------\n");
		printf("Name:\t%s\n",name);
		printf("Address:\t%s\n",address);
		printf("Gender:\t%s\n",gender);
		printf("Gmail:\t%s\n",gmail);
		printf("Phone Number:\t%.0lf\n",phone);
			printf("----------------------------------------\n");
		flag=1;
			printf("Enter y for menu option.");
	while(getch()=='y'){
		menu();
	}
	}
}
	if(flag==0){
		system("cls");
		printf("No record found.\n");
		printf("Enter y to open menu.\n");
		if(getch()=='y'){
			menu();
		}
	
	}
	

	fclose(fptr);
}
void list(){
		FILE *fptr;
	char name[100],address[100],gmail[100],gender[8];
	double phone;
	int f;
	fptr=fopen("phonebook.txt","r");
	system("cls");
	printf(" PHONEBOOK DETAILS\n");
	while(fscanf(fptr,"%s %s %s %s %lf",name,address,gender,gmail,&phone)!=EOF){
		
			printf("------------------------------------------\n");
		printf("Name:%s\n",name);
		printf("Address:%s\n",address);
		printf("Gender:%s\n",gender);
		printf("Gmail:%s\n",gmail);
		printf("Phone:%.0lf\n",phone);
			f=1;
				printf("------------------------------------------\n");
				printf("\n\n");
		}
		printf("Enter y for menu section:");
		while(getch()=='y'){
			menu();
		}
			fclose(fptr);
			}




void deletevalue(){
	FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8];
	int f=0;
	double phone,phone1;
	fptr=fopen("phonebook.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	printf("Enter the CONTACT name that you want to delete: ");
	scanf("%s",name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		if(strcmp(name,name1)==0)
		{
			f=1;
			printf("Record deleted successfully\n");
			
		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		}
	}
	if(f==0){
		printf("Record Not found.\n");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("phonebook.txt","w");
	fclose(fptr);
	fptr=fopen("phonebook.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		
	}
	
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for menu option.");
	if(getch()=='y'){
		menu();
	};
}
void exit(){
	system("cls");
	printf("Phonebook exited");
}
void password(void){
	char passwords[20]={"hello"};
	int j;
	int z;
char ch[10]="hello",pass[20];
printf("Enter the password\n");
scanf("%s",pass);
	if(strcmp(ch,pass)==0){
		menu();
	}
	else{
		printf("\nYou entered the wrong password.\n");
		printf("------------------------------------------------\n");
		char ch;
	printf("Enter p to re-enter the password\n");
	while((ch=getch())=='p'){
		password();
	}
		password();
}
}
void menu(){
	system("cls");
	printf("PHONEBOOK DIRECTORY\n");
	printf("1.Add New\n");
	printf("2.Search\n");
	printf("3.List\n");
	printf("4.Delete\n");
	printf("5.Exit\n");
	switch(getch()){
		case '1':
			addnew();
			break;
		case '2':
			search();
			break;
		case '3':
			list();
			break;
		case '4':
			deletevalue();
			break;
		case '5':
			exit();
			break;
		default:
			system("cls");
			printf("Invalid Enter.");
			getch();
}
}


