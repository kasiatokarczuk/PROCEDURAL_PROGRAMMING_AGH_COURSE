#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"



LEptr mergesort(LEptr first) {
    if (first == NULL || first->next == NULL) {
        return first;
    }

    LEptr left = first;
    LEptr right = strip_monoprefix(first);

    while (right != NULL) {
        left = merge_monotonic(left, right);
        right = strip_monoprefix(left);
    }

    return left;
}



LEptr strip_monoprefix(LEptr first) {
    if (first == NULL || first->next == NULL) {
        return NULL;  // the list is empty or contains a single element
    }

    LEptr prev_element = first;   // Pointer to the previous element
    LEptr current_element = first->next;  // Pointer to the current element

    while (current_element != NULL && prev_element->data <= current_element->data) {
        prev_element = current_element;
        current_element = current_element->next;
    }

    if (current_element == NULL) {
        return NULL;
    }
    else {
        prev_element->next = NULL;
        return current_element;
    }
}

LEptr merge_monotonic(LEptr L, LEptr R) {
    LEptr temp = (LEptr)malloc(sizeof(struct _lel));  // temporary node
    if (temp == NULL) {
        return;
    }

    LEptr current = temp;
    while (L != NULL && R != NULL) {
        if (L->data <= R->data) {
            current->next = L;
            L = L->next;
        }
        else {
            current->next = R;
            R = R->next;
        }
        current = current->next;
    }


    if (L != NULL) {
        current->next = L;
    }
    else if (R != NULL) {
        current->next = R;
    }

    LEptr result = temp->next; // first element of the merged list
    free(temp);

    return result;
}