#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1025

typedef struct List List;
struct List {
	char *item;
	List *next;
	List *prev;
};



int comp_func(const void *p1, const void *p2) {
	return strcmp((const void *)p2, (const void *)p1);
}

void list_print(List *list) {
	for ( ; list; list = list->next)
		puts(list->item);
	printf("\n");
}

List *list_add(List *head, char *item) {
	//create list item
	List *new_item = (List *) malloc(sizeof(List));
	new_item->item = item;
	new_item->next = head;
	new_item->prev = NULL;
	if (head)
		head->prev = new_item;
	//puts(new_item->item);
	return new_item;
}

List *sort(List *head) {
	int i, n;
	List *tail, *res, *list;
	//get length of list
	for (tail = head, n = 0; tail; tail = tail->next, n++);
	if (n < 2)
		return head;
	//divide list on two parts
	for (tail = head, i = 0; i < n / 2 - 1; i++)
		tail = tail->next;
	res = tail; tail = tail->next; res->next = NULL;
	head = sort(head); //recursively sort left list
	tail = sort(tail); //recursively sort right list
	//merge left and right lists into result list
	res = list = NULL;
	while (head || tail) {
		if (!tail || (head && comp_func(head->item, tail->item) >= 0)) {
			if (list) {
				list->next = head;
				list = list->next; //head;
			} else
				res = list = head;
			head = head->next;
		} else {
			if (list) {
				list->next = tail;
				list = list->next; //tail;
			} else
				res = list = tail;
			tail = tail->next;
		}
	}
	list->next = NULL;
	return res;
}

void list_destroy(List *list) {
	if (list) {
		list_destroy(list->next);
		free(list->item);
		free(list);
	}
}


int main(void)
{
	List *head = NULL, *list = NULL;
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	if (input)
	{
		int l;
		char buf[N], *text;
		while (!feof(input))
		{
			if (!fgets(buf, sizeof buf, input))
				break;
			l = strlen(buf);
			if (l > 0 && buf[l-1] == '\n')
				buf[l-1] = '\0';
			text = strdup(buf);
			head = list_add(head, text);
		}
		//list_print(head);
		head = sort(head);
		//list_print(head);
		for (list = head ; list; list = list->next)
		{
			fputs(list->item, output);
			fputs("\n", output);
		}
		list_destroy(head);
		fclose(output);
		fclose(input);
	}
	else
		perror("input.txt)");
	return 0;
}
