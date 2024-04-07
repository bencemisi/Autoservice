#include <stdio.h>
#include <stdlib.h>
#include "Struktura.h"


Datum datum_letrehoz(char* ev, char*honap, char* nap)
{
    Datum uj;
    uj.ev=atoi(ev);
    uj.honap=atoi(honap);
    uj.nap=atoi(nap);

    return uj;
}
