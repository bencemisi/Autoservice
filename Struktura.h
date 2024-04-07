#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

typedef struct Datum
{
            int ev;
            int honap;
            int nap;
}Datum;


typedef struct Javitas{

    char rendszam[10];
    char ar[100];                   //100 sz�mjegy� sz�mot biztosan nem fog be�rni, ebben biztos elf�r a jav�t�s �ra
    char datum[13];
    char* leiras;                           //Ez lesz a dinamikusan foglalt ter�leten l�v� dinamikusan foglalt ter�letem.

}Javitas;

Datum datum_letrehoz(char* ev, char*honap, char* nap);

#endif // STRUKTURA_H_INCLUDED
