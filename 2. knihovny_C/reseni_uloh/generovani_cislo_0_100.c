#include <stdio.h>
#include <stdlib.h>   
#include <time.h>    

int rand_in_range(int min, int max){
    srand(time(NULL));
    int cislo = rand() % (max);
    return cislo + min;
}

int main() {
    printf("%d\n\n",rand_in_range(1,2));
    
    int pocet_kostek;
    int pocet_sten;

    printf("Zadejte pocet kostek: ");
    scanf("%d", &pocet_kostek);

    printf("Zadejte pocet sten: ");
    scanf("%d", &pocet_sten);

    int v = 0;
    for (int i = 0; i < pocet_kostek; i++){
        v += rand_in_range(1,pocet_sten);
    }
    
    printf("hod: %d\n", v);

    return 0;
}
