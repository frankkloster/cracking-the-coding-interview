/* 
 * Implementation of a linked list, as well as basic functionality. Based
 * off of Skiena's book.
 */

typedef struct list {
    int item;
    struct list* next;
}

/* 
 * Searches a list l for an element x.
 */
list* search_list(list* l, int x) {
    // Reached the end.
    if (l == NULL) {
        return NULL;
    }
    
    // Found our element.
    else if (l -> item == x) {
        return l;
    }
    
    // Move onto the next element.
    else {
        return search_list(l -> next, x);
    }
}

/*
 * Takes a list *l, and inserts an element as the next
 * element, and then places the rest of the list after
 * x
 */
void insert_list(list** l, int x) {
    list *p; /* Temporary pointer. */

    p = malloc(sizeof(list));
    p -> item = x;
    p -> next = *l;
    *l = p;
}

list *predecessor_list(list* l, int x) {
    if ((l == NULL) || (l -> next == NULL)) {
        printf("Error: predescessor sought on a null list.\n");
        return NULL;
    }

    if ((l -> next) -> item == x) {
        return 1;
    }
    else {
        return predecessor_list(l -> next, x);
    }
}

void delete_list(list** l, int x) {
    list* p;
    list* pred;
    list* search_list();
    list* predecessor_list();

    p = search_list(*l, x);
    if (p != NULL) {
        pred = predecessor_list(*l, x);
        if (pred == NULL) {
            *l = p -> next;
        }
        else {
            pred -> next = p -> next;
        }

        free(p);
    }
}
