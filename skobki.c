#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
struct List {
	char item;
	List *next;
};

List *list_add(List *head, char item) {
	//create list item
	List *new_item = (List *) malloc(sizeof(List));
	new_item->item = item;
	new_item->next = head;
	return new_item;
}

List *list_del(List *head) {
	List *list = head;
	if (!head)
		return head;
	//special case: head removed
	head = head->next;
	free(list);
	return head;
}

unsigned list_size(List *list) {
	if (!list)
		return 0;
	else
		return list_size(list->next) + 1;
}

void list_print(List *list) {
	for ( ; list; list = list->next)
		printf("%c->", list->item);
	printf("\n");
}

void list_destroy(List *list) {
	if (list) {
		list_destroy(list->next);
		free(list);
	}
}

int main(void) {
	List *head = NULL;
	char c = '\0';
	do
	{
		scanf("%c", &c);
		if (c != '\n') {
			//list_print(head);
			if (c == '{' || c == '[' || c == '(' || c == '<')
				head = list_add(head, c);
			else if ((!head) && (c == '}' || c == ']' || c == ')' || c == '>'))
			{
				c = 'y';
				break;
			}
			else if (head->item == '{' && c == '}'
			|| head->item == '[' && c == ']'
			|| head->item == '<' && c == '>'
			|| head->item == '(' && c == ')') {
				head = list_del(head);
			}
			else
			{
				c = 'y';
				break;
			}
		}
	} while (c != '\n');
	if (head != NULL || c == 'y')
		printf("NO");
	else
		printf("YES");
	list_destroy(head);
	//list_print(head);
	//head = list_del(head);
	return 0;
}
