#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include <string.h>

int main(int argc, char *argv[]){
    plansza *A;
    A = wyzeruj_plansze();

    system("@cls||clear");
    printf(ANSI_COLOR_RED);
    printf("zaczyna czerwony\n");
    printf(ANSI_COLOR_RESET);

    while(A->wolne != 0){
        if(A->max_czerwone < wygrywa && A->max_zolte < wygrywa && A->wolne > 0)
        {
            if(A->czyj_ruch == 'c'){
                if(gracz(A) == -1)
                    break;
            }
            else{
                bot(A);
            }
            print_info(A);
        }
        else if(A->max_czerwone >= wygrywa)
        {
            printf(ANSI_COLOR_RED);
            animacja_tekstu("czerwony wygrywa!"); //niech miga na bialo czerwono to miejsce gdzie są 4 w linii
            printf(ANSI_COLOR_RESET);
            wyswietl(A);
            break;
        }
        else if(A->max_zolte >= wygrywa)
        {
            printf(ANSI_COLOR_YELLOW);
            animacja_tekstu("zolty wygrywa!"); //niech miga na bialo zolto to miejsce gdzie sa 4 w linii
            printf(ANSI_COLOR_RESET);
            wyswietl(A);
            break;
        }
        else if (A->wolne < 1)
        {
            printf("remis\n");
            wyswietl(A);
            break;
        }
    }

    free(A);

    return 0;
}