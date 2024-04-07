#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include<time.h>
#include "Struktura.h"

char belepes_megerosites(void)
{
    char valasz[500]="";                                                                      // 500 karakter elég nagy egy eldöntendő kérdésre adott válasz tárolásához, még helytelen input esetén is
    while(strcmp(valasz,"N")!=0)
          {
            printf("Kerem 'I'-vel vagy 'N'-nel valaszoljon :");
            scanf(" %s",&valasz);
            if(strlen(valasz)>1)
                  {
                      printf("Helytelen formatumu valasz, probalja ujra: ");
                      continue;
                  }
                  valasz[1]='\0';
              if(strcmp(valasz,"I")==0)
              {
                  return valasz[0];
              }
          }
    if(strcmp(valasz,"N")==0)
        {return valasz[0];}


}

char* ellenorzott_evszam_bekeres_auto_felfevetelhez(void)
{

        char *evszam;
        char ervenyesseg[12];                   //Ebben lesz kialakítva a helyesen megadott inputokból a fájlnak megfelelő formátum

       char ev[5];
       char honap[3];
       char nap[3];


        int hossz;
        bool jo_az_evszam = false;
        bool jo_a_honapszam = false;
        bool jo_a_napszam = false;
        while(!jo_az_evszam)
        {
                printf("Kerem adja meg a jarmu muszaki vizsgajanak ervenyessegenek az evet:");
                scanf("%s",ev);
                hossz = strlen(ev);
                if(hossz!=4)
                    {
                printf("Ervenytelen evszam. Kerem probalja ujra.\n");
                continue;
                    }
                if((ev[0]!=50) ||(ev[1]!=48) ||(ev[2]!=50) ||(ev[3]<50 || ev[3]>54))    //Legalabb 2022
                {
                    printf("Ervenytelen evszamot adott meg, vagy a muszaki vizsga mar lejart.\n");
                    printf("A forgalmit maximum 4 evre adjak ki.\n");
                    continue;
                }
                 jo_az_evszam=true;

        }

        ev[5]='\0';

        while(!jo_a_honapszam)
            {
            /*
            Karakterenként vizsgálom a megadott számot, ha bármi hiba újat kérek
            */
            printf("Kerem adja meg a vizsga ervenyessegenek honapjat ket tizedes jeggyel: ");
            scanf("%s",honap);
            hossz = strlen(honap);
            if(hossz!=2)
                {
                    printf("\nErvenytelen honapszam. Kerem probalja ujra.\n");
                    continue;
                }
            if(honap[0]=='1')
                {
                    if(honap[1]<47 || honap[1]>50)
                        {
                            printf("Ervenytelen honapszamot adott meg\n");
                            continue;
                        }
                }
            else  if(honap[0]=='0')
                {
                    if(honap[1]<49 || honap[1]>57)
                        {
                            printf("Ervenytelen honapszamot adott meg\n");
                            continue;
                        }
                }else
                {
                    continue;
                }
            jo_a_honapszam=true;
            }
        strcpy(ervenyesseg,ev);
        strcat(ervenyesseg,".");
        honap[3]='\0';
          strcat(ervenyesseg,honap);
        strcat(ervenyesseg,".");
        int melyik_honap;
        int honapokegymasutan[12] = { 31 ,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};              //A honapok napjai sorban
        sscanf(honap,"%d",&melyik_honap);
        int kivalasztott_honap=honapokegymasutan[melyik_honap-1];
        while(!jo_a_napszam)
            {
            printf("Kerem adja meg a vizsga ervenyessegenek napjat ket tizedes jeggyel: ");
            /*
            Karakterenként vizsgálom a megadott számot, ha bármi hiba újat kérek
            */
            scanf("%s",nap);
            hossz = strlen(nap);
            if(hossz!=2)
                {
                    printf("\nErvenytelen napszam. Kerem probalja ujra.\n");
                    continue;
                }
            if(melyik_honap==2)
                {
                    if(atoi(nap)<0 || atoi(nap)>28)
                        {
                            printf("Ervenytelen napszamot adott meg, a februar csak 28 napos\n");
                            continue;
                        }
                }
            else
                {
                    if(nap[0]<48 || nap[0]>51)
                        {
                            printf("Ervenytelen napszamot adott meg\n");
                            continue;
                        }
            if(nap[1]<48 || nap[1]>57)
                    {
                        printf("Ervenytelen napszamot adott meg\n");
                        continue;
                    }
            else  if(nap[0]=='3')
                {
                if(atoi(nap)>kivalasztott_honap)
                    {
                    printf("Ervenytelen napszamot adott meg. Az adott honapban nincs ennyi nap.\n");
                    continue;
                    }
                }
            }

         jo_a_napszam=true;
        }
        nap[3]='\0';

        //Kialakítom a fájlomban elvárt formátumot
        //majd visszaadom a rá mutató pointert.



        strcat(ervenyesseg,nap);
        ervenyesseg[12] = '\0';
        evszam = ervenyesseg;

                return evszam;
}

char* ellenorzott_evszam_bekeres_javitas_felfevetelhez(void)
{

        char ev[5];
       char honap[3];
       char nap[3];


    int egy_ev_masodpercben = 365*24*3600;
    int mostani_ev=time(NULL)/egy_ev_masodpercben;
    int hol_allok=0;
    char * evszam;
    char ervenyesseg[12];

        int hossz;
        bool jo_az_evszam = false;
        bool jo_a_honapszam = false;
        bool jo_a_napszam = false;

        while(!jo_az_evszam)
        {
            printf("Kerem adja meg a jarmu javitasanak az evet:");
            scanf("%s",ev);
            hossz = strlen(ev);
            if(hossz!=4)
                {
                    printf("Ervenytelen evszam. Kerem probalja ujra.\n");
                    continue;
                }
           if(atoi(ev)<2000 || atoi(ev)>(mostani_ev+1970))          //Javítást ne lehessen 20 évnél későbbről feljegyezni
                {
                    printf("Javitast elore bejegyezni legfeljebb az idei ev vegeig lehet.\n");
                    printf("Javitast utolag bejegyezni legfeljebb az 2000-ig lehet.\n");
                    continue;
                }
                 jo_az_evszam=true;
        }

        ev[5]='\0';

            /*
            Karakterenként vizsgálom a megadott számot, ha bármi hiba újat kérek
            */
        while(!jo_a_honapszam)
            {
                printf("Kerem adja meg a javitas honapjat ket tizedes jeggyel: ");
                scanf("%s",honap);
                hossz = strlen(honap);
                if(hossz!=2)
                    {
                        printf("\nErvenytelen honapszam. Kerem probalja ujra.\n");
                        continue;
                    }
                if(honap[0]=='1')
                    {
                    if(honap[1]<47 || honap[1]>50)
                        {
                            printf("Ervenytelen honapszamot adott meg\n");
                            continue;
                        }
                    }
                else  if(honap[0]=='0')
                    {
                        if(honap[1]<49 || honap[1]>57)
                        {
                            printf("Ervenytelen honapszamot adott meg\n");
                            continue;
                        }
                    }
                jo_a_honapszam=true;
            }
        strcat(ervenyesseg,ev);
        strcat(ervenyesseg,".");
        honap[3]='\0';
        strcat(ervenyesseg,honap);
        strcat(ervenyesseg,".");

        while(!jo_a_napszam)
            {
            printf("Kerem adja meg a javitas napjat ket tizedes jeggyel: ");
            scanf("%s",nap);
            hossz = strlen(nap);
            if(hossz!=2)
                {
                    printf("\nErvenytelen napszam. Kerem probalja ujra.\n");
                    continue;
                }
            if(atoi(honap)==2)
                {
                    if(atoi(nap)<=0 || atoi(nap)>28)
                        {
                            printf("Ervenytelen napszamot adott meg, a februar csak 28 napos\n");
                            continue;
                        }
                }
             else
                {
                    if(nap[0]<48 || nap[0]>50)
                        {
                                printf("Ervenytelen napszamot adott meg\n");
                                continue;
                        }
                    if(nap[1]<48 || nap[1]>57)
                        {
                                printf("Ervenytelen napszamot adott meg\n");
                                continue;
                        }
                    else  if(nap[0]=='3')
                        {
                            if(atoi(nap)>31)
                            {
                            printf("Ervenytelen napszamot adott meg\n");
                            continue;
                            }
                        }
            }
         jo_a_napszam=true;
        }

        //Kialakítom a fájlomban elvárt formátumot
        //majd visszaadom a rá mutató pointert.

        nap[3]='\0';


        strcat(ervenyesseg,nap);
        ervenyesseg[12] = '\0';
        evszam = ervenyesseg;

                return evszam;
}

char * Rendszambekeres(void)
{
     char *helyes_rendszam;
     char beolvasott[9];

     bool jo_a_rendszam = false;
     while(!jo_a_rendszam)
     {
         scanf("%s",beolvasott);
         int hossz = strlen(beolvasott);
         if(hossz<6 || hossz>7)
        {
         printf("\tErvenytelen hosszusagu adat.\nEgy rendszam vagy 6 vagy 7 karakter hosszu. Kerem probalja ujra.\n");
         continue;
         }
           if(hossz==7)                     //ASCII kódok alapján input ellenőrzés
           {
               if((beolvasott[0]<65 || beolvasott[0]>90) || (beolvasott[1]<65 || beolvasott[1]>90) || (beolvasott[2]<65 || beolvasott[2]>90) ||(beolvasott[3]<65 || beolvasott[3]>90) ||(beolvasott[4]<48 || beolvasott[4]>57) ||(beolvasott[5]<48 || beolvasott[5]>57) ||(beolvasott[6]<48 || beolvasott[6]>57))
//                                  1.karakter-betu                                             2.karakter-betu                                             3.karakter -betu                                                 4.karakter -betu                                                                5.karakter-szam                                           6.karakter-szam                                                7.karakter-szam
                {
                    printf("Ilyen rendszam nem letezik, rossz formatumot adott meg\n");
                        continue;
                }
           }
           else if(hossz == 6)         //ASCII kódok alapján input ellenőrzés
           {
               if((beolvasott[0]<65 || beolvasott[0]>90) || (beolvasott[1]<65 || beolvasott[1]>90) || (beolvasott[2]<65 || beolvasott[2]>90) ||(beolvasott[3]<48 || beolvasott[3]>57) ||(beolvasott[4]<48 || beolvasott[4]>57) ||(beolvasott[5]<48 || beolvasott[5]>57))
//                                  1.karakter-betu                                             2.karakter-betu                                             3.karakter -betu                                                 4.karakter -szam                                                                5.karakter-szam                                           6.karakter-szam
                {
                    printf("Ilyen rendszam nem letezik, rossz formatumot adott meg\n");
                        continue;
                }
           }
           jo_a_rendszam = true;
     }
     helyes_rendszam=beolvasott;
     return helyes_rendszam;
}

int Hany_sor_van_a_File_ban(FILE* file)
{
/*
Meghatározza hány sor van egy fajlban.
A fájlmegnyitás helyességét is ellenőrzi
*/
    char valasz;
    if(file==NULL)
    {
         printf("\nHiba a fajl megnyitasnal, lehet nem letezik.\n");
         printf("\n A folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
        scanf(" %c",&valasz);
            return NULL;
    }
    int sordarabszam=0;
    char c;
    do
    {
        c=fgetc(file);
        if(c=='\n')
        {
            sordarabszam++;
        }
    }while( c!= EOF);
    fclose(file);
    return sordarabszam;
}


char* szemelyi_bekeres()
{

    int tombhossz = 0;
    char *keresett = NULL;
    char ujbetu;
    scanf("%c",&ujbetu);
    int max=21;                                                                                                                                         //Adatfelvételnél korlátoztam a személyi igazolvány számát maximum 20 karakterben
    while (scanf("%c", &ujbetu) == 1 && ujbetu != 10 && max>0)
        {

        char *ujtomb = (char*) malloc(sizeof(char) * (tombhossz+2));
        if(ujtomb == NULL)
            {
                printf("Hiba a memoriafoglalasnal");
                return NULL;
            }
        for (int i = 0; i < tombhossz; i++)
            ujtomb[i] = keresett[i];
        free(keresett);
        keresett = ujtomb;
        keresett[tombhossz] = ujbetu;
        ++tombhossz;
        max--;
        }

        keresett[tombhossz]= '\0';

        return keresett;
}




