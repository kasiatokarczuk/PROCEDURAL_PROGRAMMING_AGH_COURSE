#include <stdio.h>
#include "rotate_list.h"

// Displaying the list
void printList(LEptr first) {
    while (first != NULL) {
        printf("%d -> ", first->data);
        first = first->next;
    }
    printf("\n");
}

int main() {
    // Creating a list [1, 2, 3, 4, 5, 6, 7]
    LEptr first = (LEptr)malloc(sizeof(struct _lel));
    if (first != NULL) {
        first->data = 1;
        first->next = NULL;
    }

    LEptr current = first;
    for (int i = 2; i <= 7; i++) {
        if (current != NULL) {
            current->next = (LEptr)malloc(sizeof(struct _lel));
            current = current->next;
            if (current != NULL) {
                current->data = i;
                current->next = NULL;
            }
        }
    }

    printf("Original list: ");
    printList(first);

    // Testing the reverse function
    LEptr reversed = reverse(first);
    printf("Reversed list: ");
    printList(reversed);

    // Testing the rotate function
    LEptr rotated = rotate(reversed, 3);
    printf("Rotated the list by 3 steps: ");
    printList(rotated);

    rotated = rotate(rotated, -2);
    printf("Rotated the list by -2 steps: ");
    printList(rotated);

    // Freeing memory
    while (rotated != NULL) {
        LEptr temp = rotated;
        rotated = rotated->next;
        free(temp);
    }

    return 0;
}
