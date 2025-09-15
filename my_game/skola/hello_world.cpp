#include <iostream>
#include <stdio.h>


void letadlo (){
    int hodiny;
    int minuty;
    int S;
    int V;
    int plus;
    bool overflow = false;

    printf("hodiny: ");
    scanf("%d", &hodiny);

    printf("minuty: ");
    scanf("%d", &minuty);

    printf("S: ");
    scanf("%d", &S);

    printf("V: ");
    scanf("%d", &V);

    plus = S/V;
    hodiny += plus;

    double result = (double)S / V;   // 3.5
    double frac   = result - (int)result; // 3.5 - 3 = 0.5

    minuty += frac * 60;
    if (minuty >= 60){
    	minuty -= 60;
    	hodiny += 1;
	}
    if (hodiny >= 24){
        hodiny -= 24;
        overflow = true;
    }
    printf("%d:%d, o %d dni pozdeji", hodiny, minuty, overflow);
}

int main () {
    //std::cout << "Hello world";
    letadlo();
    return 0;
}