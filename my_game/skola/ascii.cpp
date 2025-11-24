#include <iostream>
#include <string.h>
#include <stdio.h>

void idk (){
	  printf("retezec (pouze mala pismena): ");
    char retezec[128];
	scanf(" %s", retezec);
    printf("pocet P: ");
    int posun;
	scanf(" %d", &posun);
    int i = 0;
    while (retezec[i] != '\0'){
        retezec[i] += posun;
        if (retezec[i] > 'z')
        i++;
    }
    retezec[i] = '\0';
    printf(retezec);
}

int main (){
	char slovo[128];
	printf()

    return 0;
}