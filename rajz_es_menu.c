#include <stdio.h>
#include <stdbool.h>
void Logo_Rajz()                        //ASCII art text
{
    printf("\t                  _________________\n");
    printf("\t              _.-'_____  _________ _`.\n");
    printf("\t            .` ,'      ||         | `.`.\n");
    printf("\t          .` ,'        ||         |   `.`.\n");
    printf("\t        .`  /          ||         |  ,' ] `....___\n");
    printf("\t      _`__.'''''''''''''''''''''''`''''''''|..___ `-.._\n");
    printf("\t    .'                  [='                '     `'-.._`.\n");
    printf("\t  ,:/.'''''''''''''''''''|''''''''''''''''''|'''''''''''\\'\ \n");
    printf("\t  //||    _..._         |                  '    _..._  |)|\n");
    printf("\t /|//   ,',---.`.       |                  |  .',---.`.\\>|\n");
    printf("\t(':/   //' .-. `\\       \\_________________/  '/' .-. `\\\\|_)\n");
    printf("\t `-...'||  '-'  ||________,,,,,,,,,,,,,,,__.'||  '-'  ||-'\n");
    printf("\t       '.'.___.','                           '.'.___.','\n");
    printf("\t         '-.m.-'                               '-.m.-'");
    printf("\n*****************************************************************************\n");
    printf("\n--------------------------------AUTOSZERVIZ-------------------------------- \n");
}

void menukiiras()
{   system("cls");                                      //Kitakarítom a képernyőt
    Logo_Rajz();
    printf("\n\t\t\t  Mit szeretnel csinalni?\n");
    printf("*****************************************************************************");
    printf("\n[1]   Uj ugyfel felvetele a nyilvantartasba\n");
    printf("[2]   Felvett ugyfelek megtekintese\n");
    printf("[3]   Uj auto felvetele a nyilvantartasba\n");
    printf("[4]   Auto torlese nyilvantartasbol\n");
    printf("[5]   Elvegzett javitas felvetele a nyilvantartasba\n");
    printf("[6]   Egy adott jarmu szervizkonyve\n");
    printf("[7]   Kozeli lejaratu muszaki vizsgas autok kilistazasa\n");
    printf("[8]   Ugyfel keresese\n");
    printf("[9]   Rendszam alapu kereses");
    printf("\n\t\t\t\t\t\t[0]   Kilepes a programbol\n");
    printf("*****************************************************************************\n");
    printf("Erdemes bekapcsolnia a Caps Lock-ot mert a program tobb helyen csak a kert formaban megadott valaszokat fogadja csak el.\n\n");

}
int menupontvalasztas(void)
{
    printf("Valasszon menupontot:");
while (true) {

        fflush(stdin);
        char olvasott_str[2]="";
        int olvasott_int;
        scanf("%s", &olvasott_str);                      //Biztosítja hogy a felhasználó csak számot tudjon megadni
        if(strlen(olvasott_str)>1)                        //Ha az elso karakter elfogadott de a többi nem akkor ne szálljon el a program
                    {
                    printf("Helytelen formatumu valasz, probalja ujra: ");
                        continue;
                    }
        olvasott_str[1]='\0';
        olvasott_int=atoi(olvasott_str);

        if (olvasott_str[0]<47 || olvasott_str[0]>58) {
            printf("Amit megadtal, nem szam volt!\n");
            scanf("%*[^\n]");                                                                       //Eldobja az entert
        } else if (olvasott_int >9 || olvasott_int < 0) {
            printf("A megadott szam nem volt megfelelo! (min: 0, max: 9)\n");           //Biztosítja a megfelelõ értékhatárokat
        } else {
            return olvasott_int;
        }
    }
}
