#include <stdio.h>
#include <stdlib.h>

void addToList(int number, int *list, int *elementCount) {
    if (number == -1) {
        return;
    }

    if (number % 2 == 0) {
        list[*elementCount] = number;
    } else {
        for (int i = *elementCount; i > 0; i--) {
            list[i] = list[i - 1];
        }
        list[0] = number;
    }

    (*elementCount)++;
}

int main() {
    int list[100];
    int elementCount = 0;

    while (1) {
        int enteredNumber;
        printf("Enter a number (Enter -1 to exit): ");
        scanf("%d", &enteredNumber);

        if (enteredNumber == -1) {
            break;
        }

        addToList(enteredNumber, list, &elementCount);
    }

    printf("Modified List:\n");
    for (int i = 0; i < elementCount; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}

