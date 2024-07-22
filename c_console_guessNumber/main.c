#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lowerBound = 1, upperBound = 100;
    int targetNumber, guess, attempts = 0;

    srand(time(NULL));
    
    targetNumber = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
    
    printf("Я загадав число між %d і %d. Вгадай його!\n", lowerBound, upperBound);

    do {
        printf("Введи твоє число: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < targetNumber) {
            printf("Загадане число більше.\n");
        } else if (guess > targetNumber) {
            printf("Загадане число менше.\n");
        } else {
            printf("Вітає! Ти вгадав число %d за %d спроб.\n", targetNumber, attempts);
        }
    } while (guess != targetNumber);

    return 0;
}
