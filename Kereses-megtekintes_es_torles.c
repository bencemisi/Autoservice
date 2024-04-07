#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "debugmalloc.h"
#include "Input_ellenorzok.h"
#include"Struktura.h"



void Ugyfelmegtek()
{

    printf("Az ugyfelek megtekintese opciot szeretne? : ( I/N )\n");

    if(belepes_megerosites()=='I')
          printf("\n\t\t\t\tOpcio kivalasztva\n");
    else
        return;


    FILE* Ugyfel;
    Ugyfel = fopen("Ugyfelek.txt","r");
    char valasz;
      if(Ugyfel==NULL)
            {
                printf("Sikertelen fajlmegnyitas\n");
                 printf("\n A folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
                scanf(" %c",&valasz);
                return NULL;
            }

    printf("\nItt lathatok a felvett ugyfelek adatai ( : -tal elvalasztva):\n\n");
/*
Beolvasom a sort egy nagyon nagy méretű string tömbbe
és ha a sor vége jelemet olvasom be (';') akkor új sort kezdek
*/
    char sor[500]=" ";
    char jelenleg =" ";
    while(fscanf(Ugyfel,"%s",sor)==1)
        {
            printf("%s ",sor);
            jelenleg=sor[0];
            if(jelenleg==';')
                {
                    printf("\n");
                }
        }
    fclose(Ugyfel);
    printf("\nA folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
    scanf(" %c",&valasz);
}




void Javitas_megtek(void)
{
     printf("Szervizkonyv lekerdezest szeretne? : ( I/N )\n");

    if(belepes_megerosites()=='I')
          printf("\n\t\t\t\tOpcio kivalasztva\n");
    else
        return;


    FILE*   sordarab;
    sordarab=fopen("Javitasok.txt","r");
    char valasz;
    int sordarabszam = Hany_sor_van_a_File_ban(sordarab);   //Filemegynitás ellenőrző a fv-ben

    fclose(sordarab);

    /*Bezárás majd ujranyitas annak az érdekében hogy a fájl legelejéről kezdje a  program az olvasást.
    Az előzőleg megkapott darabszámmal dinamikusan foglalok egy tömböt
    */
    FILE*   structba_szed;
    structba_szed=fopen("Javitasok.txt","r");
    if(structba_szed==NULL)
            {
                 printf("\nHiba a javitasok.txt megnyitasnal, lehet nem letezik.\n");
                 printf("\n A folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
                 scanf(" %c",&valasz);
                 return NULL;
            }
    Javitas *javitasok;
    javitasok=malloc(sordarabszam*sizeof(Javitas));
            if(javitasok==NULL)
            {
                printf("Sikertelen memoriafoglalas");
                return NULL;
            }

        //Feltölti a program az egyes javításokhoz tartozo adatokat
    for(int i=0;i<sordarabszam;i++)
        {
            int hossz;
            int db = 0;
            char *sor = NULL;
            char ujkarakter;
            while (fscanf(structba_szed,"%c", &ujkarakter) == 1 && ujkarakter != 10)
                {
            //Nyújtom a tömböt ameddig kell
                    char *ujtomb = (char*) malloc(sizeof(char) * (db+1));
                    if(ujtomb==NULL)
                        {
                            printf("Sikertelen memoriafoglalas");
                            return NULL;
                        }
                    for (int i = 0; i < db; i++)
                        ujtomb[i] = sor[i];
                    free(sor);
                    sor = ujtomb;
                    sor[db] = ujkarakter;
                    ++db;
                }
        sor[db-1]='\0';
    /*
    Strtok megváltoztatja az erdeti stringet ezért szükséges lemásolni , hogy az egyes részek hosszát és tartalma is ki lehessen nyerni
    */

    /*
    A dinamikus memóriakezeléshez, elindítok egy másik strtok függvényt, hogy ahol kell ott meg tudjam kapni
    a beírt adatok hosszát és tudjak dinamikusan memóriát foglalni.
    */
        char* sor2 =(char*) malloc(sizeof(char) * (strlen(sor)+1));
        if(sor2==NULL)
                {
                    printf("Sikertelen memoriafoglalas");
                    return NULL;
                }
        strcpy(sor2,sor);
        strcpy(javitasok[i].rendszam,strtok(sor,":"));
        strcpy(javitasok[i].ar,strtok(NULL,":"));
        strcpy(javitasok[i].datum,strtok(NULL,":"));
        hossz=strlen(strtok(NULL,":"));
        javitasok[i].leiras=malloc((hossz+1)*sizeof(char));

        if(javitasok[i].leiras==NULL)
                {
                    printf("Hiba a memoriafoglalasnal");
                    return NULL;
                }
        strtok(sor2,":");
        strtok(NULL,":");
        strtok(NULL,":");

        strcpy(javitasok[i].leiras,(strtok(NULL,":")));

        free(sor);
        free(sor2);
        }

     fclose(structba_szed);
     /*
     Itt van az igazi kereses
     Beolvasom minden sor elejéről a rendszámot, majd megvizsgálom hogy egyezik-e avval amit a felhasználó megadott.
     Ha ez teljesül akkor kiírom a sor tartalmát
     */
    FILE*   szervizkonyv;
    szervizkonyv=fopen("Javitasok.txt","r");
    if(szervizkonyv==NULL)
    {
        printf("Hiba a javitasok.txt megnyitasanal");
        return NULL;
    }
    printf("\nMilyen rendszamu auto szervizkonyvvet szeretne listazni:");

    char keres[15];
    strcpy(keres,Rendszambekeres());

    char kiszed[10]="";
    bool talalt=false;

    for(int i=0;i<sordarabszam;i++)
    {
      sscanf(javitasok[i].rendszam,"%s",kiszed);
      if(strcmp(keres,kiszed)==0)
      {
          printf("%s%s%s%s \n",javitasok[i].rendszam,javitasok[i].ar,javitasok[i].datum,javitasok[i].leiras);
          talalt=true;
      }
  }

    //Ha nem volt találat jelzem

    if(!talalt)
        {
            printf("\nNincs ilyen rendszamu auto javitasa feljegyezve.\n");
        }

    fclose(szervizkonyv);
    for(int i = 0;i<sordarabszam;i++)
        {
            free(javitasok[i].leiras);                      //Belső tömb felszabadítása
        }
    free(javitasok);                                               //Dinamikusan foglalt struktúra felszabadítása
    printf("\nA folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
    scanf(" %c",&valasz);
}

bool Auto_torles(void)
{

        /*
        A függvény mukodesenek lényege, hogy létrehoz egy másik txt fájlt és oda átmásolja a sorokat, kivéve azt amelyiket a felhasználó kiválasztott.
        Ezzel lényegében kitörli.
        */
     printf("Az autok torlese opciot szeretne? : ( I/N )\n");

    if(belepes_megerosites()=='I')
          printf("\n\t\t\t\tOpcio kivalasztva\n");
    else
        return;

        int sortorlesi_index=0;
        FILE * beolvasok;
        beolvasok= fopen("Autok.txt","r");
            if(beolvasok==NULL)
            {
                printf("\nHiba a Autok.txt megnyitasnal, lehet nem letezik.\n");
                printf("\n A folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
                char valasz;
                scanf(" %c",&valasz);
                return false;
            }


  //Itt nyitom azt a fájlt ahová másolni fogok
        FILE * temp;
        temp= fopen("Autok2.txt","w");

        if(temp == NULL)
        {
                printf("\nHiba a fajletrehozasnal.\n");
                printf("\n A folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
                char valasz;
                scanf(" %c",&valasz);
                return false;
        }
        /*
        Beszámozza es kiírja az AUTOK.txt tartalmát soronként, ebbol
        tud majd a felhasználó választani, hogy melyiket szeretné kitörölni.
        */
//**********************************
        int szamoz = 1;
        char jelenleg;
        char sorkiir[200];
        while(fgets(sorkiir,200,beolvasok))
        {
            printf("%d sor:  ",szamoz);
            szamoz++;
            printf(sorkiir);
            jelenleg=sorkiir[0];
            if(jelenleg==';')
            {
                szamoz++;
                printf("\n");
            }
        }
    fclose(beolvasok);

//*****************************************
     beolvasok= fopen("Autok.txt","r");
       if(beolvasok==NULL)
            {
                printf("Sikertelen fajlmegnyitas");
                return false;
            }

        //Végigmegyek a sorokon, ha ahhoz jutok amit a felhasználo kiválasztott, azt nem másolom át az új txt-be
        char sor[1024];
        bool megolvas = true;
        int jelenlegi_sor=1;
        printf("\nMelyik sort toroljem: ");
        scanf("%d",&sortorlesi_index);
        do
        {
            fgets(sor, 1024, beolvasok);
            if(feof(beolvasok))
            {
                megolvas = false;
            }
            else if (jelenlegi_sor!=sortorlesi_index)
                {
                    fputs(sor,temp);
                }
            jelenlegi_sor++;
        } while (megolvas);

        printf("Sortorles vegrehajtva");
        fclose(beolvasok);
        fclose(temp);
        printf("\nA folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
        char valasz;
        scanf(" %c",&valasz);
        return true;
}

void Kozeli_lejaratu_autok_listazasa(void)
{

    /*
    A létrehozott struktúrámba eltárolom a jelenleg beolvasott sor dátumát és feldolgozom.
    A szűrést kivonással hajtom végre. Kiszámolom a feljegyzett nap és a mai nap kozotti kulonbseget
    és ha ez az érték egy bizonyos határnál kisebb(30 nap) akkor megjelenítem a hozzá tartozó adatokat.
    */
     printf("A kozeli lejaratu autok kilistazasa opciot szeretne? : ( I/N )\n");
    if(belepes_megerosites()=='I')
          printf("\n\t\t\t\tOpcio kivalasztva\n");
    else
        return;

    printf("\nItt lathatoak a 30 napon belul lejaro illetve lejart muszaki vizsgas autok adatai\n\n");

//Megszámolom hány sor van a fáljlomban
     FILE*   sordarab;
    sordarab=fopen("Autok.txt","r");
     char valasz;
     int sordarabszam = Hany_sor_van_a_File_ban(sordarab);       //Filemegynitás ellenőrző a fv-ben

     FILE* lejarat;
     lejarat = fopen("Autok.txt","r");

    if(lejarat==NULL)
    {
        printf("Hiba a fajl megnyitasanal");
        return;
    }

    int honapokegymasutan[12] = { 31 ,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i =0; i<sordarabszam;i++)
    {

            int db = 0;
            char *sor = NULL;
            char datumegybe[11]; // Stringként tárolt dátum, benne az elválasztó karakterekkel
            char ujkarakter;
            while (fscanf(lejarat,"%c", &ujkarakter) == 1 && ujkarakter != 10)
                {
            //Nyújtom a tömböt ameddig kell
                    char *ujtomb = (char*) malloc(sizeof(char) * (db+1));
                    if(ujtomb==NULL)
                        {
                            printf("Sikertelen memoriafoglalas");
                            return NULL;
                        }
                    for (int i = 0; i < db; i++)
                        ujtomb[i] = sor[i];
                    free(sor);
                    sor = ujtomb;
                    sor[db] = ujkarakter;
                    ++db;
                }
            sor[db-1]='\0';

            char sor2[strlen(sor)];
            strcpy(sor2,sor);

            strtok(sor,":");
            strtok(NULL,":");
            strtok(NULL,":");
            strcpy(datumegybe,strtok(NULL,":"));

            Datum vizsga_ervenyesseg = datum_letrehoz(strtok(datumegybe,"."),strtok(NULL,"."),strtok(NULL,"."));                            //Datum típus létrehozással fügvénnyel
            vizsga_ervenyesseg.ev-=1970;       //time(NULL) 1970.01.01 tól számol


            int eltelt_honapok_napban=0;     //Az adott hónapig eltelt napok száma az évben
            for(int i =0 ; i< vizsga_ervenyesseg.honap-1;i++)
            {
                eltelt_honapok_napban+=honapokegymasutan[i];
            }

            int lejaratnapban = vizsga_ervenyesseg.ev*365+eltelt_honapok_napban+vizsga_ervenyesseg.nap;
            int sec = time(NULL);                   //1970.01.01
            int maidatumnapban=sec/3600/24;         //1970 óta eltelt napok száma



            if(lejaratnapban-maidatumnapban<30)
                    {
                        printf(sor2);
                        printf("\n");
                    }
            free(sor);
    }

    fclose(lejarat);

   printf("\nA folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
        scanf(" %c",&valasz);
}


void Ugyfel_kereses(void)
{
    /*
    A keresést személyi igazolvány szám alapján végzem, hiszen az egy egyedi azonosíto
    Először megszámolom hány sort tartalmaz a txt-m, utána soronként ellenorzom hogy
    a keresett azonnositot megtalaltam-e. Ha igen akkor kiírom az adott sorhoz tartozo adatokat.
    */
    printf("Az ugyfel kereses opciot szeretne? : ( I/N )\n");
     if(belepes_megerosites()=='I')
          printf("\n\t\t\t\tOpcio kivalasztva\n");
    else
        return;
    FILE*   sor_db;
    sor_db=fopen("Ugyfelek.txt","r");
    int sordarabszam = Hany_sor_van_a_File_ban(sor_db);

    //Itt kezdődik a keresés
    FILE * Ugyfel_keres;
    Ugyfel_keres = fopen("Ugyfelek.txt","r");
    if(Ugyfel_keres==NULL)
        {
         printf("\nHiba az ugyfelek.txt megnyitasnal, lehet nem letezik.\n");
         printf("\n A folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
         char valasz;
        scanf(" %c",&valasz);
        return NULL;
        }
    /*
    Dinamikus tömböt használok a bekért személyi igazolvány szám eltárolására, mert
    ezen adat hossza változhat attól függően mikor készült az okirat, de az adatrögzítésnél megadtam,
     hogy 20 karakternél nem lehet hosszabb.
    */
    printf("\nKerem adja meg a keresett szemely szemelyi igazolvany szamat\n");

        char* keresett=szemelyi_bekeres();
        /*
        A fálj egy teljes sorának beolvasása, a későbbi kereséshez
        */
            bool talalt= false;

     for(int i =0; i<sordarabszam;i++)
    {
            int db = 0;
            char *sor = NULL;
            char ujkarakter;
            while (fscanf(Ugyfel_keres,"%c", &ujkarakter) == 1 && ujkarakter != 10)
                {
                    char *ujtomb = (char*) malloc(sizeof(char) * (db+1));
                    if(ujtomb==NULL)
                        {
                            printf("Sikertelen memoriafoglalas");
                            return NULL;
                        }
                    for (int i = 0; i < db; i++)
                        ujtomb[i] = sor[i];
                    free(sor);
                    sor = ujtomb;
                    sor[db] = ujkarakter;
                    ++db;
            }
        sor[db-1]='\0';
        char sor2[strlen(sor)];     //Strtok miatt szükséges eltárolni egy másik változóban a beolvasott sort
        strcpy(sor2,sor);               //Addig használom az Strtok-ot amíg el nem érem a nekem kellő adatot.
        strtok(sor,":");
        strtok(NULL,":");
        char* szemelyi_ig_szam =strtok(NULL," ;");
        if(strcmp(keresett,szemelyi_ig_szam)==0)
            {
            printf(sor2);
            talalt=true;
            }
        free(sor);
    }

    if(!talalt)
    {
        printf("Nincs ilyen szemelyi igazolvany szam a nyilvantartasban");
    }
    fclose(Ugyfel_keres);
    free(keresett);
    fflush(stdin);
    printf("\nA folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
    char valasz;
    scanf(" %c",&valasz);
}


void Rendszam_alapu_kereses(void)
{
    printf("Rendszam alapjan szeretne keresni? : ( I/N )\n");

    if(belepes_megerosites()=='I')
          printf("\n\t\t\t\tOpcio kivalasztva\n");
    else
        return;

    printf("Milyen rendszamu auto adatait szeretne kilistazni?:");
       char keresett[15];
    strcpy(keresett,Rendszambekeres());

     FILE*   sordarab;
     sordarab=fopen("Autok.txt","r");
     int sordarabszam= Hany_sor_van_a_File_ban(sordarab);    //Filemegynitás ellenőrző a fv-ben

     FILE * Rendszam_keres;
     Rendszam_keres=fopen("Autok.txt","r");
     if(Rendszam_keres==NULL)
     {
        printf("\nHiba az autok.txt megnyitasnal, lehet nem letezik.\n");
        printf("\n A folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
        char valasz;
        scanf(" %c",&valasz);
        return NULL;
     }

     bool talalt = false;

          for(int i =0; i<sordarabszam;i++)
    {
            int db = 0;
            char *sor = NULL;
            char ujkarakter;
            while (fscanf(Rendszam_keres ,"%c", &ujkarakter) == 1 && ujkarakter != 10)
                {
                    char *ujtomb = (char*) malloc(sizeof(char) * (db+1));
                    if(ujtomb==NULL)
                        {
                            printf("Sikertelen memoriafoglalas");
                            return NULL;
                        }
                    for (int i = 0; i < db; i++)
                        ujtomb[i] = sor[i];
                    free(sor);
                    sor = ujtomb;
                    sor[db] = ujkarakter;
                    ++db;
            }
        sor[db-1]='\0';
        char sor2[strlen(sor)];     //Strtok miatt szükséges eltárolni egy másik változóban a beolvasott sort
        strcpy(sor2,sor);               //Addig használom az Strtok-ot amíg el nem érem a nekem kellő adatot.
        char* kiszedett_rendszam =strtok(sor," ;");
        if(strcmp(keresett,kiszedett_rendszam)==0)
            {
            printf(sor2);
            printf("\n");
            talalt=true;
            }
        free(sor);
    }

     if(!talalt)
    {
        printf("Nincs ilyen rendszamu auto a nyilvantartasban");
    }
    fclose(Rendszam_keres);
    fflush(stdin);
    char valasz;
    printf("\nA folytatashoz gepeljen be egy karakter,majd nyomjon entert.");
    scanf(" %c",&valasz);
}

