int main()
{
    int ch;
    login();
    printf("\n\n\t-----------------------------------\n");
    printf("\t :PERSONAL DIARY MANAGEMENT SYSTEM:\n");
    printf("\t-----------------------------------");
    while(1)
    {
        printf("\n\t\n\t:MAIN MENU:");
        printf("\n\n\t[1]. ADD NOTES\t");
        printf("\n\t[2]. VIEW NOTES\t");
        printf("\n\t[3]. EDIT NOTES\t");
        printf("\n\t[4]. DELETE NOTES\t");
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
            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE ");
            getch();
            exit(0);
        default:
            printf("\nYOU ENTERED WRONG CHOICE..");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            break;
        }
        system("cls");
    }
    return 0;
}
