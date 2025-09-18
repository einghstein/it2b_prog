#include <stdio.h>
#include <stdlib.h>   
#include <time.h>    
#include <math.h>

int rand_in_range(int min, int max){
    int cislo = rand() % (max);
    return cislo + min;
}

float rand_in_float(float min, int max){
    
    float cislo = rand() % max;
    return (float)cislo + min;
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

void monte_carlo(){
    const float presnost = 1000.0;
    const float N = 20000000.0;
    
    float a, b, x, y;
    float c;
    float in = 0.0;
    for (int i = 0; i < N; i++){
        x = rand_in_float(0,(int)presnost);
        y = rand_in_float(0,(int)presnost);

        a = abs(x - (presnost/2));
        b = abs(y - (presnost/2));
        //printf("x %f\ny %f\na %f\nb %f\n", x, y, a, b);

        c = sqrt(a*a + b*b);
        //printf("c %f\n", c, (in/N));

        if (c < presnost/2){
            in++;
        }
    }
    printf("in %f\n/ %f\n", in, (in/N));
    float pi = 4.0 * (in/N);
    printf("pi = %f\n", pi);
}

int main() {
	srand(time(NULL));
    printf("%d\n\n",rand_in_range(1,2));
    
    //hadej();
    monte_carlo();

    return 0;
}
