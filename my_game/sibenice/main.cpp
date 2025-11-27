#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <cctype>

#define MAX_TRIES 6
#define WORDS_COUNT 5

// Funkce pro výber náhodného slova
const char* getRandomWord() {
    const char* words[WORDS_COUNT] = {"program", "banan", "strom", "auto", "hory"};
    srand(time(0)); // Inicializace náhodného generátoru
    return words[rand() % WORDS_COUNT];
}

// Funkce pro zobrazení stavu slova s odhalenými písmeny
void printWord(const char* word, char* guessed) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (guessed[i] != 0) {
            printf("%c ", guessed[i]); // Zobrazí odhalené písmeno
        } else {
            printf("_ "); // Zobrazí prázdné místo pro neuhádnuté písmeno
        }
    }
    printf("\n");
}

int main() {
    const char* word = getRandomWord(); // Vybere náhodné slovo
    int wordLength = strlen(word);
    char guessed[wordLength]; // Pole pro uhodnutá písmena
    for (int i = 0; i < wordLength; i++) {
        guessed[i] = 0; // Inicializuje všechna písmena jako neuhádnutá
    }
    
    int tries = 0; // Pocet neúspešných pokusu
    char guess;
    int correctGuess;

    printf("Vitejte ve hre Sibenice!\n");

    // Hlavní herní smycka
    while (tries < MAX_TRIES) {
        correctGuess = 0;
        printf("\nSlovo: ");
        printWord(word, guessed);

        printf("Zadejte pismeno: ");
        scanf(" %c", &guess); // %c je pro zadání jednoho znaku
        guess = tolower(guess); // Ujistíme se, že je písmeno malé

        // Projdeme každé písmeno slova a zjistíme, zda je to správné
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess && guessed[i] == 0) {
                guessed[i] = word[i]; // Uhodnuté písmeno
                correctGuess = 1;
            }
        }

        if (correctGuess) {
            printf("Spravne! Pismeno '%c' je ve slove.\n", guess);
        } else {
            tries++;
            printf("Spatne! Zbyva pokusu: %d\n", MAX_TRIES - tries);
        }

        // Zkontrolujeme, zda hrác uhodl celé slovo
        int wordComplete = 1;
        for (int i = 0; i < wordLength; i++) {
            if (guessed[i] == 0) {
                wordComplete = 0;
                break;
            }
        }

        if (wordComplete) {
            printf("\nGratulujeme! Uhodli jste slovo: %s\n", word);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printf("\nProhrali jste! Slovo bylo: %s\n", word);
    }

    return 0;
}
