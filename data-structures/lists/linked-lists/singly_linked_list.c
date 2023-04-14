#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} node;

void print_list(node *head);
void insert(node **head, int item);
void delete(node **head, int item);

int main(int argc, char *argv[]){
	
	node *head = NULL;

	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7);
	insert(&head, 8);

	print_list(head);

	delete(&head, 5);

	print_list(head);

	return 0;
}

void print_list(node *head){
	printf("---List start---\n");
	while(head != NULL){
		printf("Value : %i\n", (head)->data);
		head = (head)->next;
	}
	printf("---List end---\n");
}

void insert(node **head, int item){
	if(*head == NULL){
		*head = (node *)malloc(sizeof(node));
		(*head)->data = item;
		(*head)->next = NULL;
	}else{
		node *current = *head;
		node *new_node = (node *)malloc(sizeof(node));
		new_node->data = item;
		new_node->next = NULL;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = new_node;
	}
}

void delete(node **head, int item){
	node *current = *head;
	if(current->data == item){
		*head = (*head)->next;
		free(current);
	}else{
		while(current->next->data != item){
			current = current->next;
		}
		node *temp = current->next;
		current->next = temp->next;
		free(temp);
	}
}
