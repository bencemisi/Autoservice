#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
#include "Input_ellenorzok.h"
#include <stdbool.h>
/*
Uj adat bekérésénél, a program pontosított kérdéseket tesz fel a felhasználónak,
A valaszokat ellenorzi ha az adatoknak később kulcsfontosságu szerepuk van.
Minden helyes válasz után automatikus ment a megfelelő fajlba, illetve elhelyez egy
határoló karaktert az adatok a közé. ("  : ")
Az utolsó adat után sorzáró karaktert helyez el ("  ; ")és nyit egy uj sort

*/

void Uj_Auto()
{

    printf("Az autok felvetele opciot szeretne? : ( I/N )\n");

        if(belepes_megerosites()=='I')
          printf("\n\t\t\t\tOpcio kivalasztva\n");
    else
        return;

    FILE * Auto;
    Auto = fopen("Autok.txt","a");
    if(Auto==NULL)
            {
             printf("Sikertelen fajlmegnyitas");
            return NULL;
            }
                /*
                Rendszám bekérésnél két tényezőt vizsgál a program. Az egyik a felhasználó által begépelt karaktersor hossza.
                Ugyanis egy rendszám vagy 6 karakter vagy 7 karakter hosszú '-' jel nélkül.
                A másik vizsgálat a beírt karakterek helyességére vonatkozik. A program ellenőrzi, hogy ahol betűnek kell állnia
                ott betű áll-e és ugyanezt megvizsgálja a számokra is. Ha bárhol hibát talál, új rendszámot kér a felhasználótól.
                */

     printf("\nKerem adja meg a felvenni kivant auto rendszamat nagybetuvel, hivatalos formatumban ""-"" jel nelkul.:\n");
    char ervenyes_rendszam[15];
    strcpy(ervenyes_rendszam,Rendszambekeres());
    fprintf(Auto,"%s",ervenyes_rendszam);
    fprintf(Auto," : ");

    char betu="";
    scanf("%c",&betu);             //Eldobja az entert
    /*
    Nem tárol el a program semmilyen adatot, amíg nem kap entert addig karakterenként beírja az AUTOK.TXT fájlba
    a felhasználó által beírt adatokat. Az entert az ASCII kódja alpján ellenőrzi(10)
    */
    printf("Kerem adja meg a felvenni kivant auto tipusat:\n");
        while(scanf("%c",&betu)==1 && betu != 10)
            fprintf(Auto,"%c",betu);
        fprintf(Auto," : ");

    printf("Kerem adja meg a felvenni kivant auto evjaratat:\n");

    char beolvasottev[5]="";        //Maximum 4 karakter lehet vagy ervenytelen bemenet +1 lezáró 0


     bool jo_az_ev = false;
     while(!jo_az_ev)
     {
         scanf("%s",beolvasottev);
         int evszam = strlen(beolvasottev);
         if(evszam!=4)
            {
                printf("\nErvenytelen evszam. Kerem probalja ujra.\n");
                continue;
            }
         int beolvasottszamkent= atoi(beolvasottev);
         if(beolvasottszamkent< 1885 || beolvasottszamkent>= 2023)
            {
                printf("Az autod idoutazo???\nAdd meg ismet az evszamot : ");
                continue;
            }
               if((beolvasottev[0]<48 || beolvasottev[0]>57) || (beolvasottev[1]<48 || beolvasottev[1]>57) || (beolvasottev[2]<48 || beolvasottev[2]>57) || (beolvasottev[3]<48 || beolvasottev[3]>57))
//                                 1.karakter - szam                                            2.karakter - szam                                          3.karakter - szam                                           4.karakter - szam
                   {
                    printf("\nIlyen evszamu nem lehet az auto\n");
                        continue;
                    }
            jo_az_ev= true;
            beolvasottev[5]='\0';                   //srting lezaras

        }
    for(int i = 0;beolvasottev[i]!='\0';i++)
                fprintf(Auto,"%c",beolvasottev[i]);

    fprintf(Auto," : ");

    //Vizsga ervenyesseg

    char ervenyes_vizsga_datum[15];
    strcpy(ervenyes_vizsga_datum,ellenorzott_evszam_bekeres_auto_felfevetelhez());
    fprintf(Auto,"%s",ervenyes_vizsga_datum);
    fprintf(Auto," : ");


    scanf("%c",&betu); //Beolvassa az enter, majd eldobja
     /*
    Nem tárol el a program semmilyen adatot, amíg nem kap entert addig karakterenként beírja az AUTOK.TXT fájlba
    a felhasználó által beírt adatokat. Az entert az ASCII kódja alpján ellenőrzi(10)
    */
    printf("Kerem adja meg a felvenni kivant auto tulajdonosanak szemelyi igazolvany szamat:\n");
    while(scanf("%c",&betu)==1 && betu != 10)               //ASCII Kodja az ENTERNEK---> 10
        {fprintf(Auto,"%c",betu);}
   fprintf(Auto," ;");                                                              //Sorvege
    fprintf(Auto,"\n");                                                              //Uj auto adatainak kezdese

    fclose(Auto);

    printf("\nA folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
    char valasz;
    scanf(" %c",&valasz);
}

void Uj_ugyfel()
{


    printf("Az ugyfelek felvetele opciot szeretne? : ( I/N )\n");

    if(belepes_megerosites()=='I')
          printf("\n\t\t\t\tOpcio kivalasztva\n");
    else
        return;

    FILE * Ugyfel;
    Ugyfel = fopen("Ugyfelek.txt","a");
    if(Ugyfel==NULL)
            {
                printf("Sikertelen fajlmegnyitas");
                return NULL;
            }

            /*
            A program nem tárolja el az adatokat, hanem karakterenként átmásolja a
            Ugyfelek.txt fajlba, amíg ENTER-t nem üt a felhasználó. Az 'enter' inputot
            az ASCII kódtábla szerint vizsgálja (ASCII Kodja az ENTERNEK---> 10)
            */
     printf("\nKerem adja meg a felvenni kivant ugyfel nevet szokozzel elvalasztva ekezetes betuk nelkul:\n");
    char betu;
    scanf("%c",&betu);
    while(scanf("%c",&betu)==1 && betu != 10)
        fprintf(Ugyfel,"%c",betu);
    fprintf(Ugyfel," : ");

    printf("Kerem adja meg a felvenni kivant ugyfel e-mail cimet:\n");
    while(scanf("%c",&betu)==1 && betu != 10)
        fprintf(Ugyfel,"%c",betu);
    fprintf(Ugyfel," : ");

    printf("Kerem adja meg a felvenni kivant ugyfel szemelyi igazolvany szamat:\n");
    int max = 20;
    while(scanf("%c",&betu)==1 && betu != 10 && max>0 )
        {
               fprintf(Ugyfel,"%c",betu);
                max--;
        }
    fflush(stdin);

   fprintf(Ugyfel," ;");                                                              //Sorvege

    fprintf(Ugyfel,"\n");                                                              //Új sorba lépés a következõ beolvasáshoz
    fclose(Ugyfel);

    printf("\nA folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
    char valasz;
    scanf(" %c",&valasz);
}



void Javitasok_felvetele(void)
{
  printf("Uj javitast szeretne hozzadni a nyilvantartashoz?  ( I/N )\n");
    if(belepes_megerosites()=='I')
          printf("\n\t\t\t\tOpcio kivalasztva\n");
    else
        return;

    FILE* javitasok;
    javitasok = fopen("Javitasok.txt","a");
        if(javitasok==NULL)
            {
                printf("Sikertelen fajlmegnyitas");
                return NULL;
            }

    printf("\nKerem adja meg a javitott auto rendszamat, nagybetuvel, kotojel nelkul :\n");
     char ervenyes_rendszam[15];
    strcpy(ervenyes_rendszam,Rendszambekeres());
    fprintf(javitasok,"%s",ervenyes_rendszam);
    fprintf(javitasok," : ");

    int ar;
    printf("Kerem adja meg a javitas arat elvalasztas nelkul :");

    while (true) {
        int sikerult = scanf("%d", &ar);                      //Biztosítja hogy a felhasználó csak számot tudjon megadni
        if (sikerult != 1) {
                printf("Amit megadtal, nem szam volt!\n");
                scanf("%*[^\n]");                                                                       //Eldobja az entert
        } else if (ar< 0) {
                printf("Az ar nem lehet negativ osszeg\n");           //Biztosítja a megfelel értékhatárokat
        } else {
            break;
        }
    }
    char c[1000];             //Az arkeresnel beirt karaktereket elveti
    gets(c);

    fprintf(javitasok,"%d",ar);
    fprintf(javitasok," : ");

     char ervenyes_vizsga_datum[15];
    strcpy(ervenyes_vizsga_datum,ellenorzott_evszam_bekeres_javitas_felfevetelhez());
    fprintf(javitasok,"%s",ervenyes_vizsga_datum);
    fprintf(javitasok," : ");
            /*
            A leírás megadásánál dinamikus tömböt használok, hogy változatos legyen a programom.
            Amíg a beolvasott új karakterem nem enter addig mindig, megnyújtja a tömböt.
            Enter ellenorzése ASCII kód alapján
            */
    printf("Kerem adja meg a javitas leirasat (ekezet nelkul):\n");
    int db = 0;
    char *leiras = NULL;
    char ujkarakter;
    scanf("%c", &ujkarakter);
    while (scanf("%c", &ujkarakter) == 1 && ujkarakter != 10)
            {
            //Ha nem enter akkor itt nyujtok
            char *ujtomb = (char*) malloc(sizeof(char) * (db+1));
            if(ujtomb==NULL)
                {
                    printf("Hiba a memoriafoglalasnal");
                    return NULL;
                }
            for (int i = 0; i < db; i++)
                ujtomb[i] = leiras[i];
            free(leiras);
            leiras = ujtomb;
            leiras[db] = ujkarakter;
            ++db;
            }
        ++db;
        char *ujtomb = (char*) malloc(sizeof(char) * (db+1));
        if(ujtomb==NULL)
        {
                    printf("Hiba a memoriafoglalasnal");
                    return NULL;
        }
    for (int i = 0; i < db; i++)
        ujtomb[i] = leiras[i];

    free(leiras);
    leiras = ujtomb;
    leiras[db-1] = '\0';
    ++db;

    fprintf(javitasok,leiras);
    fprintf(javitasok,"; \n");

    free(leiras);
    fclose(javitasok);
    printf("\nA folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
      char valasz;
    scanf(" %c",&valasz);
}
