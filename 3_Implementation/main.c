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
    char user[10]="diary";
    char pass[10]="pass@123";
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
	printf("  \n\n\t\t WELCOME TO PERSONAL DIARY  \n\t\t\t   \n The unread chapters of my life \n*** LOGIN IS SUCCESSFUL ***");
	printf("\n\n\n\t\t\t\t  Press any key to Proceed...");
	getch();
	getch();
	break;
	}
	else
	{
		printf("\n\t\t\t||USER NOT FOUND||\n You have only 3 attempts to SigIn Successfully\n");
		a++;
		getch();
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\n OOPSS!! ALL THE ATTEMPTS HAVE FAILED :-| ");
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
int main()
{
    int ch;
    login();
    printf("\n\n\t*********************************\n");
    printf("\t #WELCOME TO YOUR PERSONAL DIARY#\n");
    printf("\t*************************************\t");
    while(1)
    {
        printf("\n\t\n\t:MAIN MENU:");
        printf("\n\n\t[1]. ADD RECORD\t");
        printf("\n\t[2]. VIEW RECORD\t");
        printf("\n\t[3]. EDIT RECORD\t");
        printf("\n\t[4]. DELETE RECORD\t");
        printf("\n\t[5]. EDIT PASSWORD\t");
        printf("\n\t[6]. EXIT\t\t");

        printf("\n\n\tENTER YOUR CHOICE:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            addrecord();
            break;
        case 2:
            viewrecord();
            break;
        case 3:
            editrecord();
            break;
        case 4:
            deleterecord();
            break;
        case 5:
            editpassword();
            break;
        case 6:
            printf("\n\n\t\tTHANK YOU!! SEE YOU TOMORROW ;-D ");
            getch();
            exit(0);
        default:
             printf("\nSORRY..OPTION IS NOT AVAILABLE");
            printf("\nPRESS ANY KEY TO PROCEED");
            getch();
            break;
        }
        system("cls");
    }
    return 0;
}
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
           printf("\n!!!NOTE NOT FOUND !!!");
            printf("\nPRESS ANY KEY TO CLOSE");
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
	    printf("\tWHO'S THIS??\t\t:");
	    fflush(stdin);
	    scanf("%s",e.name);
	    fflush(stdin);
	    printf("\tVENUE\t\t:");
	    scanf("%s",e.place);
	    fflush(stdin);
	    printf("\n\tNOTE:\n\t");
	    scanf("%s",e.note);
	    fflush(stdin);
	    fwrite(&e,sizeof(e),1,fp);
	     printf("\n\tYOUR NOTE IS SUCCESSFULLY ADDED.\n");
	}
	printf ( "\n\t WANT TO ADD ANOTHER NOTE ?(Y/N) " ) ;
	fflush ( stdin ) ;
        another = getchar( );
    }
    fclose ( fp ) ;
     printf("\n\n\tPRESS ANY KEY TO CLOSE...");
    getch();
}
void viewrecord( )
{
    struct record c ;
    char time[6],choice,filename[14];
    int ch;
    FILE *fpte ;
    system("cls");
    printf("\n\t\t-----------------------------\n");
    printf("\t\t\t:   TRACK MENU:");
    printf("\n\t\t\t---------------------------\n\n");
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
                printf("\nNAME OF THE NOTE\t: %s",c.name);
                printf("\nVENUE\t\t: %s",c.place);
                printf("\nMEMO\t\t: %s\n",c.note);
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
                printf("\nYOUR OLD NOTE:");
                printf("\nEDIT TIME: %s",c.time);
                printf("\nEDIT NAME: %s",c.name);
                printf("\nEDIT VENUE: %s",c.place);
                printf("\nNOTE: %s",c.note);
                printf("\n1.EDIT THE NOTE: ");
                printf("\n2.GO BACK TO CONTENT PAGE.");
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
                        printf("\nNEW VENUE:");
                        gets(c.place);
                        printf("\nMEMO:");
                        gets(c.note);
                        printf("THE NOTE IS EDITED");
                        break;
                    case 2:
                        printf("\nPRESS ANY KEY TO CLOSE..\n");
                        getch();
                        return ;
                        break;
                    default:
                        printf("\nWE FOUND IT IS A WRONG ENTRY!! PLEASE TRY AGAIN\n");
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
            printf("\n\t\tEDITING IS DONE SUCCESSFULLY...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("--------------------\n");
            printf("\nTIME: %s",c.time);
            printf("\nNEW PERSON: %s",c.name);
            printf("\nVENUE: %s",c.place);
            printf("\nMEMO: %s",c.note);
            fclose(fpte);
            if(count==1)
        printf("\n%d ENTRY IS EDITED...\n",count);
    else if(count>1)
        printf("\n%d ENTRIES ARE EDITED..\n",count);
    else
        printf("\nNO ENTRY WAS  EDITED...\n");
            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER NOTE? (Y/N)");
            scanf("%c",&choice);
            count++;
        }
        else
        {
            printf("\nDO YOU WISH TO GIVE ANOTHER TRY? (Y/N)");
            scanf("%c",&choice);
        }
        }
    }
    while(choice=='Y'||choice=='y');
    fclose ( fpte ) ;
    if(count==1)
        printf("\n%d ENTRY IS EDITED...\n",count);
    else if(count>1)
        printf("\n%d ENTRIES ARE EDITED..\n",count);
    else
        printf("\nNO ENTRY EDITED...\n");
    printf("\tPRESS ENTER TO CLOSE THE MENU.");
    getch();
}
int password()
{
    char pass[15]= {0},check[15]= {0},ch;
    FILE *fpp;
    int i=0,j;
    printf("\t<<only 3 Attempts are Allowed !!! >>");
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
            printf("\nTHE PASSWORD IS INCORRECT!! PLEASE TRY AGAIN\n");
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
            printf("\n\n\tHURRAHH!!\t\nACCESS GRANTED\n");
            return 0;
        }
        else
        {

            printf("\n\n\t \tACCESS DENIED \n YOU HAVE ENTERED A WRONG PASSCODE\n\n\tPLEASE TRY AGAIN (*YOU HAVE ONLY FEW ATTEMPTS LEFT*)");
        }
    }
    printf("\n\t::YOU  HAVE ENTERED A WRONG PASSWORD::YOU CANNOT ACCESS ANY FILE::\n\tPRESS ANY KEY TO PROCEED...");
    
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
             printf("OOPPSS!!ERROR HAS OCCURED...");
            getch();
            return ;
        }
        fclose(fp);
       printf("\nSignin is Approved...\nYOUR CURRENT PASSWORD IS 'pass@123'\n PRESS ENTER KEY TO CHANGE PASSCODE\n\n");
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
            printf("\n\tRETYPE TO CONFIRM PASSCODE:");
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
                    printf("\n\t\tPASSCODE ERROR");
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

                printf("\n\tPASSWORD DOES NOT MATCH.");
                choice=1;
            }
        }
    }
    while(choice==1);
    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO CLOSE...")
    getch();
}
void deleterecord( )
{
    FILE *fp,*fptr ;
    struct record file ;
    char filename[15],another = 'Y' ,time[10];
    int choice,check;
    system("cls");
    printf("\n\n\t\t######################\n");
    printf("\t\t\t:DELETE RECORD:");
    printf("\n\t\t #######################\n\n");
    check = password();
    if(check==1)
    {
    return ;
    }
    while ( another == 'Y' )
    {
        
        printf("\n\n\tTHE FOLLOWING ARE OPTIONS TO DELETE A RECORD!! PRESS 1 OR 2");
        printf("\n\n\t[1]. DELETE WHOLE RECORD");
        printf("\n\n\t[2]. DELETE A PARTICULAR RECORD BY TIME");
        do
        {
            printf("\n\n\tENTER YOU CHOICE:");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                 printf("\n\tENTER THE DATE OF THE NOTE TO BE DELETED:[yyyy-mm-dd]:");
                fflush(stdin);
                gets(filename);
                fp = fopen (filename, "wb" ) ;
                if ( fp == NULL )
                {
                     printf("\nNOTE NOT FOUND");
                    printf("\nPRESS ANY KEY TO RETURN.");
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
                    printf("\nOOPPSS!! ERROR");
                    printf("\nPRESS ANY KEY TO RETURN");
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
                 printf("\n\tSORRY !! YOU HAVE A MADE A WRONG ENTRY");
                break;
            }
        }
        while(choice<1||choice>2);
       printf("\n\tWOULD YOU LIKE TO DELETE ANOTHER NOTE? (Y/N):");
        fflush(stdin);
        scanf("%c",&another);
    }
     printf("\n\n\tPRESS ANY KEY TO CLOSE...\n\t THANK YOU\n");
    getch();
}
