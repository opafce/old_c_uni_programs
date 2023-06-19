#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
struct List {
	int item;
	List *next;
	List *prev;
};

unsigned list_size(List *list);

List *list_add(List *head, int item) {
	//create list item
	List *new_item = (List *) malloc(sizeof(List));
	new_item->item = item;
	new_item->next = head;
	new_item->prev = NULL;
	if (head)
		head->prev = new_item;
	return new_item;
}

List *list_append(List *head, int item) {
	//create list item
	List *new_item = (List *) malloc(sizeof(List));
	new_item->item = item;
	new_item->next = NULL;
	new_item->prev = NULL;
	if (head) {
		List *list;
		//go to the end
		for (list = head; list->next; list = list->next);
		list->next = new_item; //append
		new_item->prev = list;
	} else {
		head = new_item; //init (create) list
	}
	return head;
}

List *list_delete_first(List *head) {
	List *list = head;
	if (!head)
		return head;
	if (!head->next) {
		head = NULL;
	}
	else {
		head = head->next;
		head->prev = NULL;
	}
	free(list);
	return head;
}


List *list_delete_last(List *head) {
    List *list = head;
    if (!head)
        return head;
    if (!head->next) {
        head = NULL;
        free(list);
        return head;
    }
    for (list = head; list->next; list = list->next);
    list->prev->next = NULL;
    free(list);
    return head;
}

List *list_insert(List *head, unsigned index, int item) {

    if (index == 0)
        return list_add(head, item);
    //0st item
    if (head) {
        unsigned i;
        List *list = head;
        for (i = 0; i < index - 1; i++) {
            if (!list->next)
                return head;
            list = list->next;
        }
        if (list->next == NULL)
        {
            List *new_item = (List *) malloc(sizeof(List));
            new_item->item = item;
            list->next = new_item;
            new_item->prev = list;
            new_item->next = NULL;
        }
        else
        {
            List *new_item = (List *) malloc(sizeof(List));
            new_item->item = item;
            list = list->next;
            new_item->prev = list->prev;
            new_item->next = list;
            list->prev->next = new_item;
            list->prev = new_item;
        }
    }
    return head;
}

List *list_delete(List *head, unsigned index) {
    if (index == 0)
        return list_delete_first(head);
    if (head)
    {
        List *old_item;
        unsigned  i;
        for (i = 0, old_item = head; old_item->next && i < index; old_item = old_item->next, i++);
        if (i < index)
            return head;
        else
        {
            old_item->prev->next = old_item->next;
            if (old_item->next)
                old_item->next->prev = old_item->prev;
            free(old_item);
        }
    }
    return head;
}

int list_get(List *list, unsigned index) {
	unsigned i;
	for (i = 0; list; list = list->next, i++)
		if (i == index)
			return list->item;
	return -1;
}

void list_set(List *list, unsigned index, int item) {
	unsigned i;
	for (i = 0; list; list = list->next, i++)
		if (i == index) {
			list->item = item;
			return;
		}
}

int list_find(List *list, int item) {
    unsigned i = 0;
    while (list) {
        if (list->item == item)
            return i;
        list = list->next;
        i++;
    }
    return -1;
}

unsigned list_size(List *list) {
	if (!list)
		return 0;
	else
		return list_size(list->next) + 1;
}

void list_print(List *list) {
	for ( ; list; list = list->next)
		printf("%d ", list->item);
	printf("\n");
}

void list_reverse_print(List *list) {
    if (list)
        for ( ; list->next; list = list->next);
    for ( ; list; list = list->prev)
        printf("%d ", list->item);
    printf("\n");
}

void list_destroy(List *list) {
	if (list) {
		list_destroy(list->next);
		free(list);
	}
}
