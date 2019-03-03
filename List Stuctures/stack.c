#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node{
	int data;
	struct node * next;
} node;

node *top;

node * createNode(int x){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	return temp;
}

int isStackEmpty(){
	if(top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void push(int data){
	node * temp = createNode(data);
	temp->next = top;
	top = temp;
	printf("\nStacked!\n");
}

void pop(){
	node * temp;
	if(!isStackEmpty()){
		temp = top;
		printf("Popped: %d\n",temp->data);
		top = temp->next; 
		free(temp);	
	}
	else
		printf("\nStack is Empty\n");		
}

node* peek(){
	if(!isStackEmpty()){
		return top;
	} else {
		printf("\nStack is Empty\n");
	}
}

int main(){
	
	push(78);
	push(34);
	push(7);
	pop();
	node *temp = peek();
	printf("%d",temp->data);
	
}
