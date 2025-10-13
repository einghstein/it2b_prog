#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    srand(time(NULL));
    const int RES = 1000;
    const float NUM = 100000.0;

	float x;
	float y;
    float in = 0;
    for (size_t i = 0; i < NUM; i++){
        x = rand() % RES;
        y = rand() % RES;

        if (sqrt(x*x + y*y) <= RES){
            in += 1.0;
        }
    }
    //printf("in: %f")
    float pi = (in/NUM)*4.0;
    printf("pi = %f", pi);

    return 0;
}
