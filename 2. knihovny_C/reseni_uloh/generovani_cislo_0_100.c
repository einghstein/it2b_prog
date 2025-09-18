#include <stdio.h>
#include <stdlib.h>   
#include <time.h>    

int rand_in_range(int min, int max){
    srand(time(NULL));
    int cislo = rand() % (max);
    return cislo + min;
}

void kostka(){
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
}

void hadej(){
    int my = rand_in_range(1,100);
    bool run = true;
    int guess;
    int hadal = 0;
    while (run){
        printf("hadej: ");
        scanf("%d", &guess);
        hadal++;
        if (guess < my){
            printf("malo\n");
        }
        else if(guess == my){
            run = false;
            printf("ano zpravne, trvalo ti to %d pokusu\n", hadal);
        }
        else {
            printf("moc\n");
        }
    }
}

int main() {
    printf("%d\n\n",rand_in_range(1,2));
    
    hadej();

    return 0;
}
