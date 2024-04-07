#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Input_ellenorzok.h"
#include"rajz_es_menu.h"
#include "Uj_adatok_felvetele.h"
#include "debugmalloc.h"
#include "Kereses-megtekintes_es_torles.h"

int main(void)
{
   while(true)
   {
        menukiiras();
        switch(menupontvalasztas())
        {

            case 1 :
                    Uj_ugyfel();break;
            case 2:
                    Ugyfelmegtek();break;
            case 3:
                    Uj_Auto();break;
            case 4:
                    if(Auto_torles())
                        {
                            //Ha sikeresen végrehajtódott a mûvelet csak akkor nyúljon hozzá a fájlokhoz
                            remove("Autok.txt");
                            rename("Autok2.txt","Autok.txt");
                        }
                    break;
            case 5:
                    Javitasok_felvetele();break;
            case 6:
                    Javitas_megtek();break;
            case 7:
                    Kozeli_lejaratu_autok_listazasa();break;
            case 8:
                    Ugyfel_kereses();break;
            case 9:
                    Rendszam_alapu_kereses();break;
            case 0:
                    printf("\nKoszonom, hogy a programomat hasznalta.\n\n");
                    return 0;
                default: break;
            }
   }
}
