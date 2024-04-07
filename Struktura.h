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
    char ar[100];                   //100 számjegyû számot biztosan nem fog beírni, ebben biztos elfér a javítás ára
    char datum[13];
    char* leiras;                           //Ez lesz a dinamikusan foglalt területen lévõ dinamikusan foglalt területem.

}Javitas;

Datum datum_letrehoz(char* ev, char*honap, char* nap);

#endif // STRUKTURA_H_INCLUDED
