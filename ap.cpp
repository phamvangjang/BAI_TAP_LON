#include "allFunction.h"
int main()
{
    char choice;
    INTERFACE();
    while (1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\tCHON '1' DE XEM TODOS TRONG NGAY\n");
        printf("\t\t\t\t\tCHON '2' DE TAO TODO MOI CHO RIENG BAN\n");
        printf("\t\t\t\t\tCHON '3' DE XOA TODO\n");
        printf("\t\t\t\t\tCHON '4' DE THOAT KHOI UNG DUNG\n");
        printf("\t\t\t\t\tNHAP LUA CHON CUA BAN:");
        scanf("%s", &choice);
        option(choice);
    }
}
