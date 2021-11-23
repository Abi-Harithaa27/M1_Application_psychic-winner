#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int password();
void addrecord();
void viewrecord();
void editrecord();
void editpassword();
void deleterecord();
void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n PLEASE LOGIN FIRST\n \n ");
    printf("ENTER USERNAME:\n  ");
	gets(uname);
	printf(" \n ENTER PASSWORD:\n  ");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0; 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\t\t             WELCOME TO YOUR PERSONAL DIARY \n\t\t\t             *** LOGIN IS SUCCESSFUL ***");
	printf("\n\n\n\t\t\t\t          Press any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n\t\t\t||USER NOT IDENTIFIED||\n");
		a++;
		getch();
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for three times!!!");
		getch();
		}
	system("cls");	
}
struct record

{
    char time[6];
    char name[30];
    char place[25];
    char note[500];
} ;
void addrecord( )
{
    FILE *fp ;
    char another = 'Y' ,time[10];
    struct record e ;
    char filename[15];
    int choice;
    system("cls");
    printf("\n\n\t\t------------------------\n");
    printf("\t\t: WELCOME TO THE ADD MENU :");
    printf("\n\t\t-------------------------\n\n");
    printf("\n\n\tENTER DATE OF YOUR RECORD[yyyy-mm-dd]   :");
    fflush(stdin);
    gets(filename);
    fp = fopen (filename, "ab+" );
    if ( fp == NULL )
    {
        fp=fopen(filename,"wb+");
        if(fp==NULL)
        {
            printf("\n!!!SYSTEM ERROR!!!");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;
	}
    }
    while ( another == 'Y'|| another=='y' )
    {
	choice=0;
	fflush(stdin);
	printf ( "\tENTER TIME[hh:mm]\t\t\t:");
	scanf("%s",time);
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
	{
	    if(strcmp(e.time,time)==0)
	    {
		printf("\n\tTHE RECORD ALREADY EXISTS.\n");
		choice=1;
	    }
	}
	if(choice==0)
	{
	    strcpy(e.time,time);
	    printf("\tENTER YOUR OR ANYBODY'S NAME\t\t:");
	    fflush(stdin);
	    scanf("%s",e.name);
	    fflush(stdin);
	    printf("\tENTER THE NAME OF THE PLACE\t\t:");
	    scanf("%s",e.place);
	    fflush(stdin);
	    printf("\n\tNOTE:\n\t");
	    scanf("%s",e.note);
	    fflush(stdin);
	    fwrite(&e,sizeof(e),1,fp);
	    printf("\n\tYOUR RECORD HAS BEEN ADDED SUCCESSFULLY.\n");
	}
	printf ( "\n\tDO YOU WANT TO ADD ANOTHER RECORD?(Y/N) " ) ;
	fflush ( stdin ) ;
        another = getchar( );
    }
    fclose ( fp ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}
void viewrecord( )
{
    struct record c ;
    char time[6],choice,filename[14];
    int ch;
    FILE *fpte ;
    system("cls");
    printf("\n\t\t\t_________________\n");
    printf("\t\t\t:  VIEWING MENU :");
    printf("\n\t\t\t_________________\n\n");
    choice=password();
    if(choice!=0)
    {
        return ;
    }
    do
    {
        printf("\n\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]:");
        fflush(stdin);
        gets(filename);
        fpte = fopen ( filename, "rb" ) ;
        if ( fpte == NULL )
        {
            puts ( "\n\tTHE RECORD DOES NOT EXIST...\n" ) ;
            printf("\tPRESS ANY KEY TO EXIT...");
            getch();
            return ;
        }
        system("cls");
        printf("\n\tVIEWING THE RECORD:\n");
            printf("\nTHE RECORD OF %s is:\n ",filename);
            while(fread(&c,sizeof(c), 1, fpte)== 1 )
            {
                printf("\nTIME\t\t: %s",c.time);
                printf("\nNAME OF RECORD\t: %s",c.name);
                printf("\nPLACE\t\t: %s",c.place);
                printf("\nNOTE\t\t: %s\n",c.note);
            }
            fflush(stdin);
        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
        scanf("%c",&choice);
    }
    while(choice=='Y'||choice=='y');
    fclose ( fpte ) ;
    return ;
}
void editrecord()
{
    struct record c ;
    char time[6],choice,filename[14];
    int num,count=0;
    FILE *fpte;
    system("cls");
    printf("\n\n\t\t:::::::::::::::::::::::::::::::\n");
    printf("\t\t\t: EDIT RECORD :");
    printf("\n\t\t:::::::::::::::::::::::::::::::\n\n");
    choice=password();
    if(choice!=0)
    {
        return ;
    }
    do
    {
        printf("\n\tENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]:");
        fflush(stdin);
        gets(filename);
        printf("ENTER THE TIME[hh:mm]: ");
        fflush(stdin);
        gets(time);
        fpte = fopen ( filename, "rb+" ) ;
        if ( fpte == NULL )
        {
        	printf("THE RECORD DOESNOT EXIST");
            printf("\nPRESS ANY KEY TO GO BACK");
            getch();
            return;
        }
        while ( fread ( &c,sizeof (c), 1,fpte ) == 1 )
        {
            if(strcmp(c.time,time)==0)
            {
                printf("\nYOUR OLD RECORD WAS AS:");
                printf("\nEDIT TIME: %s",c.time);
                printf("\nEDIT NAME: %s",c.name);
                printf("\nEDIT PLACE: %s",c.place);
                printf("\nNOTE: %s",c.note);
                printf("\n1.EDIT THE RECORD: ");
                printf("\n2.GO BACK TO MAIN MENU.");
                do
                {
                    printf("\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);
                    printf("\nENTER THE NEW DATA:");
                    switch(num)
                    {
                    case 1:
                        printf("\nNEW TIME:[hh:mm]:");
                        gets(c.time);
                        printf("\nNEW NAME:");
                        gets(c.name);
                        printf("\nNEW PLACE:");
                        gets(c.place);
                        printf("\nNOTE:");
                        gets(c.note);
                        printf("THE RECORD IS EDITED");
                        break;
                    case 2:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");
                        getch();
                        return ;
                        break;
                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                        break;
                    }
                }
                while(num<1||num>8);
                fseek(fpte,sizeof(c),SEEK_CUR);
                fwrite(&c,sizeof(c),1,fpte);
                fseek(fpte,sizeof(c),SEEK_CUR);
                fread(&c,sizeof(c),1,fpte);
                choice=5;
                break;
            }
        }
        if(choice==1)
        {
            system("cls");
            printf("\n\t\tEDITING COMPLETED...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("--------------------\n");
            printf("\nTIME: %s",c.time);
            printf("\nNEW NAME: %s",c.name);
            printf("\nMEETING AT: %s",c.place);
            printf("\nNOTE: %s",c.note);
            fclose(fpte);
            if(count==1)
        printf("\n%d FILE IS EDITED...\n",count);
    else if(count>1)
        printf("\n%d FILE ARE EDITED..\n",count);
    else
        printf("\nNO FILES EDITED...\n");
            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
            scanf("%c",&choice);
            count++;
        }
        else
        {
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            scanf("%c",&choice);
        }
    }
    while(choice=='Y'||choice=='y');
    fclose ( fpte ) ;
    if(count==1)
        printf("\n%d FILE IS EDITED...\n",count);
    else if(count>1)
        printf("\n%d FILE ARE EDITED..\n",count);
    else
        printf("\nNO FILES EDITED...\n");
    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();
}
int password()
{
    char pass[15]= {0},check[15]= {0},ch;
    FILE *fpp;
    int i=0,j;
    printf("\t<<REMEMBER YOU ONLY HAVE 3 TRIALS ALLOWED>>");
    for(j=0; j<3; j++)
    {
        i=0;
        printf("\n\n\n\tENTER THE PASSWORD:");
        pass[0]=getch();
        while(pass[i]!='\r')
        {
            if(pass[i]=='\b')
            {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
                pass[i]=getch();
            }
            else
            {
                printf("*");
                i++;
                pass[i]=getch();
            }
        }
        pass[i]='\0';
        fpp=fopen("SE","r");
        if (fpp==NULL)
        {
            printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");
            getch();
            return 1;
        }
        else
            i=0;
        while(1)
        {
            ch=fgetc(fpp);
            if(ch==EOF)
            {
                check[i]='\0';
                break;
            }
            check[i]=ch-5;
            i++;
        }
        if(strcmp(pass,check)==0)
        {
            printf("\n\n\tACCESS HAS BEEN GRANTED TO YOU\n");
            return 0;
        }
        else
        {

            printf("\n\n\tENTERED A WRONG PASSWORD\n\tACCESS DENIED TEMPORARILY FOR NOW\n\tCHECK THE PASSWORD PROPERLY:(BE CAREFUL YOU MIGHT GET LOCKED OUT)");
        }
    }
    printf("\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\tPRESS ANY KEY TO RETURN...");
    getch();
    return 1;
}
void editpassword()
{
    char pass[15]= {0},confirm[15]= {0},ch;
    int choice,i,check;
    FILE *fp;
    system("cls");
    printf("\n");
    fp=fopen("SE","rb");
    if(fp==NULL)
    {
        fp=fopen("SE","wb");
        if(fp==NULL)
        {
            printf("SYSTEM ERROR...");
            getch();
            return ;
        }
        fclose(fp);
        printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'HELLO'\n PRESS ENTER TO CHANGE PASSWORD\n\n");
        getch();
    }
    fclose(fp);
    check=password();
    if(check==1)
    {
        return ;
    }
    do
    {
        if(check==0)
        {
            i=0;
            choice=0;
            printf("\n\n\tENTER THE NEW PASSWORD:");
            fflush(stdin);
            pass[0]=getch();
            while(pass[i]!='\r')
            {
                if(pass[i]=='\b')
                {
                    i--;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    pass[i]=getch();
                }
                else
                {
                    printf("*");
                    i++;
                    pass[i]=getch();
                }
            }
            pass[i]='\0';
            i=0;
            printf("\n\tCONFIRM PASSWORD:");
            confirm[0]=getch();
            while(confirm[i]!='\r')
            {
                if(confirm[i]=='\b')
                {
                    i--;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    confirm[i]=getch();
                }
                else
                {
                    printf("*");
                    i++;
                    confirm[i]=getch();
                }
            }
            confirm[i]='\0';
            if(strcmp(pass,confirm)==0)
            {
                fp=fopen("SE","wb");
                if(fp==NULL)
                {
                    printf("\n\t\tSYSTEM ERROR");
                    getch();
                    return ;
                }
                i=0;
                while(pass[i]!='\0')
                {
                    ch=pass[i];
                    putc(ch+5,fp);
                    i++;
                }
                putc(EOF,fp);
                fclose(fp);
            }
            else
            {

                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
                choice=1;
            }
        }
    }
    while(choice==1);
    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    getch();
}
void deleterecord( )
{
    FILE *fp,*fptr ;
    struct record file ;
    char filename[15],another = 'Y' ,time[10];
    int choice,check;
    system("cls");
    printf("\n\n\t\t      _____________________\n");
    printf("\t\t\t:DELETE RECORD:");
    printf("\n\t\t      ____________________\n\n");
    check = password();
    if(check==1)
    {
    return ;
    }
    while ( another == 'Y' )
    {
        printf("\n\n\tHOW WOULD YOU LIKE TO DELETE?");
        printf("\n\n\t[1]. DELETE WHOLE RECORD");
        printf("\n\n\t[2]. DELETE A PARTICULAR RECORD BY TIME");
        do
        {
            printf("\n\n\tENTER YOU CHOICE:");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                printf("\n\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:");
                fflush(stdin);
                gets(filename);
                fp = fopen (filename, "wb" ) ;
                if ( fp == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
                }
                fclose(fp);
                remove(filename);
                printf("\nDELETED SUCCESFULLY...");
                break;
                case 2:
                printf("\n\tENTER THE DATE OF RECORD:[yyyy-mm-dd]:");
                fflush(stdin);
                gets(filename);
                fp = fopen (filename, "rb" ) ;
                if ( fp == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXISTS");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
                }
                fptr=fopen("temp","wb");
                if(fptr==NULL)
                {
                    printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");
                fflush(stdin);
                gets(time);
                while(fread(&file,sizeof(file),1,fp)==1)
                {
                    if(strcmp(file.time,time)!=0)
                        fwrite(&file,sizeof(file),1,fptr);
                }
                fclose(fp);
                fclose(fptr);
                remove(filename);
                rename("temp",filename);
                printf("\nDELETED SUCCESFULLY.");
                break;
                default:
                printf("\n\tYOU ENTERED WRONG CHOICE");
                break;
            }
        }
        while(choice<1||choice>2);
        printf("\n\tWOULD YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);
    }
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}

