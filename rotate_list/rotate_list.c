#include "rotate_list.h"
#include <stdlib.h>
#include <stdio.h>

// Reversing the order
LEptr reverse(LEptr first) {
    LEptr previous = NULL;
    LEptr current = first;
    LEptr next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous; // new first element
}

LEptr rotate(LEptr first, int step) {
    if (step == 0 || first == NULL || first->next == NULL) {
        return first;  // no changes
    }

    // Length of the linked list
    int length = 1;
    LEptr current = first;
    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    step = -step;

    step = step % length;  // Number of steps to rotate the list
    if (step < 0) {
        step = length + step;
    }

    if (step == 0) {
        return first;
    }

    // The new first element after rotation
    int stepsToNewFirst = length - step - 1;
    current = first;
    for (int i = 0; i < stepsToNewFirst && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {  // Exceeded the end of the list
        return first;
    }

    // Changing pointers to achieve rotation
    LEptr newFirst = current->next;  // newFirst points to the new first element
    current->next = NULL;  // Split the list

    current = newFirst;

    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    // The next pointer of the last element of the new list points to the first element of the old list
    if (current != NULL) {
        current->next = first;
    }

    return newFirst; // new first element
}
