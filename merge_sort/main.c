#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

void printList(LEptr first) {
    LEptr curr = first;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    LEptr first = NULL;
    LEptr curr = NULL;

    // Creating the list
    int values[] = { 5, 3, 8, 2, 1, 9, 4, 7, 6 };
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        LEptr newNode = (LEptr)malloc(sizeof(struct _lel));
        if (newNode != NULL) {
            newNode->data = values[i];
            newNode->next = NULL;
        }

        if (first == NULL) {
            first = newNode;
            curr = newNode;
        }
        else {
            curr->next = newNode;
            curr = newNode;
        }
    }

    printf("List before sorting: ");
    printList(first);

    first = mergesort(first);

    printf("List after sorting: ");
    printList(first);

    while (first != NULL) {
        curr = first;
        first = first->next;
        free(curr);
    }

    return 0;
}