#include <stdlib.h>
#include <stdio.h>
#include "list.h"


list* new_list(int size) {
    list *l = (list*) malloc(sizeof(list));
    l->items = (int*) malloc(size * sizeof(int));
    l->count = 0;
    l->first = -1;
    l->last = -1;
    l->max = size;
    return l;
}

int is_null(list *l) {
    return l == NULL;
}

void clear(list *l) {
    if (is_null(l)) return;
    l->count = 0;
    l->first = -1;
    l->last = -1;
}

void insert(int x, list *l){
    if (is_null(l) || is_full(l)) return;
    if(is_empty(l))
        l->first = 0;
    if((l->last == l->max) && (l->first > 0)) {
        l->last = -1;
    }
    l->last++;
    l->items[l->last] = x;
    l->count++;
}

int remove_at(int i, list *l){
    int j, x = l->items[i];
    if(is_null(l) || is_empty(l) || (i < 0 || i > l->last)) {
        return -1;
    }
    if(l->first < l->last) {
        for(j = i; j < l->last; j++) {
            l->items[j] = l->items[j+1];
        }
        l->last--;
    }
    else if(l->first > l->last){
            for(j = i; j > l->first; j--) {
                l->items[j] = l->items[j-1];
            }
            l->first++;
        }
        else {
            return;
        }
    if(l->first == l->max-1)
        l->first = 0;
    l->count--;

    if (is_empty(l)) {
        l->first = -1;
    }
    return x;
}

int is_empty(list *l){
    return is_null(l) || l->count == 0;
}

int is_full(list *l){
    return l->count == l->max;
}

void print(list *l){
    int i;
    if(l->first < l->last){
        for (i = 0; i < l->count; i++){
            printf("Item[%d] = %d\n", i, l->items[i]);
        }
    }
    else{
        for (i = l->first; i < l->max; i++){
            printf("Item[%d] = %d\n", i, l->items[i]);
        }
        for (i = 0; i <= l->last; i++){
            printf("Item[%d] = %d\n", i, l->items[i]);
        }
    }
}

void destroy_list(list **l){
    free((*l)->items);
    free(*l);
    *l = NULL;
}

int remove_last(list *l){
    if(is_null(l) || is_empty(l)){
        return -1;
    }
    int x = l->items[l->last];
    if (l->last == 0){
        l->last = l->max-1;
    }
    else{
        l->last--;
    }
    l->count--;
    return x;
}

int remove_first(list *l) {
    if(is_null(l) || is_empty(l)) {
        return -1;
    }
    int i, x = l->items[l->first];
    for (i = 0; i < l->count; i++){
        l->items[i] = l->items[i+1];
    }
    l->last--;
    l->count--;
    if(is_empty(l)){
        l->first = -1;
    }
    return x;
}

void insert_first(int x, list *l) {
	if(is_null(l) || is_full(l)) {
		return;
	}
    if(l->first != -1) {
        l->first = l->max;
    }
    l->first--;
    l->items[l->first] = x;
    l->count++;
}

int searchL(int x, list *l) {
	if(is_null(l) || is_empty(l)) {
		return -1;
	}

	int i, y = -1;

	for(i = 0; i < l->max-1; i++) {
		if((l->items[i]) == x) {
			y = i;
		}
	}

	if(y >= 0) {
        return y;
	}
	else {
        return -1;
	}
}
