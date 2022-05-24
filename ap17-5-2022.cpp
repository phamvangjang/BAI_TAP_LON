#include "function.h"
void command(char choice)
{
    int choiceTempo;
    choiceTempo = choice;
    switch (choiceTempo)
    {
    case '1':
        seetodo();
        system("pause");
        break;
    case '2':
        createtodo();
        break;
    case '3':
        deleteTodo();
        break;
    case '4':
        repairTodo();
        system("pause");
        break;
    case '5':
        unfinishTodo();
        break;
    case '6':
        overdueTodo();
        break;
    case '7':
        rankTodo();
        break;
    case '8':
        completeTodo();
        break;
    case '9':
        exit(1);
        break;
    default:
        printf("\n\n\t\tLUA CHON KHONG HOP LE :-(\n");
        printf("\n\n\t\tMOI BAN NHAP LAI SU LUA CHON: ");
        scanf("%s", &choiceTempo);
        command(choiceTempo);
        break;
    }
}
void interface()
{
    system("color 3F");
    printf("\n\n\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n\n");
    printf("\t} : } : } : } : } : } "
           ": } : } : } :   "
           " "
           "CHAO BAN DEN VOI TODO LIST : { : { : { : { : { "
           ": { : { : { : {\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    system("pause");
}
int main()
{
    char choice, choice2;
    interface();
    while (17)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\tTODO NGAY: %d/%d/%d\n", t->tm_mday, t->tm_mon, t->tm_year + 1900);
        printf("\t\t\t\t\tCHON '1' DE XEM TODOS TRONG NGAY %d/%d/%d\n", t->tm_mday, t->tm_mon, t->tm_year);
        printf("\t\t\t\t\tCHON '2' DE TAO TODO MOI CHO RIENG BAN\n");
        printf("\t\t\t\t\tCHON '3' DE XOA TODO\n");
        printf("\t\t\t\t\tCHON '4' DE SUA TODO\n");
        printf("\t\t\t\t\tCHON '5' DE XEM TODO CHUA HOAN THANH\n");
        printf("\t\t\t\t\tCHON '6' DE XEM CAC TODO QUA HAN\n");
        printf("\t\t\t\t\tCHON '7' DE SAP XEP CAC TODO THEO MUC DO CONG VIEC\n");
        printf("\t\t\t\t\tCHON '8' DE XEM CAC TODO DA HOAN THANH\n");
        printf("\t\t\t\t\tCHON '9' DE THOAT KHOI UNG DUNG\n");
        printf("\t\t\t\t\tNHAP LUA CHON CUA BAN:");
        scanf("%s", &choice);
        command(choice);
    }
}
