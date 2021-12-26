#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *previous;
} node;

void print_list(node *head);
void insert(node **head, int item);
void delete(node **head, int item);

int main(int argc, char *argv[]){
	
	node *head = NULL;

	printf("insertion started\n");

	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7);
	insert(&head, 8);

	printf("insertion ended\n");

	delete(&head, 7);

	print_list(head);

	return 0;
}

void print_list(node *head){
	while(head != NULL){
		printf("Value: %i\n", head->data);
		head = head->next;
	}
}

void insert(node **head, int item){
	if(*head == NULL){
		*head = (node *)malloc(sizeof(node));
		(*head)->data = item;
		(*head)->next = NULL;
		(*head)->previous = NULL;
	}else{
		node *current = *head;
		node *new_node = (node *)malloc(sizeof(node));
		new_node->data = item;
		new_node->next = NULL;
		while(current->next != NULL){
			current = current->next;
		}
		new_node->previous = current;
		current->next = new_node;
	}
}

void delete(node **head, int item){
	node *current = *head;
	if(current->data == item){
		*head = (*head)->next;
		(*head)->previous = NULL;
		free(current);
	}else{
		while(current->next->data != item){
			current = current->next;
		}
		node *temp = current->next;
		current->next = temp->next;	
		if(temp->next != NULL){
			current->next->previous = current;
		}		
		free(temp);
	}
}
