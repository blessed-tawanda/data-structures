#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Struct to represent a node or 1 item in stack stores data of type integer
typedef struct node{
	int data;
	struct node * next;
} node;

// create an empty top node
node *top;

// function to create node and returns a node
node * createNode(int x){
	// first a temporary node is created and the data in the temp node is set to the passed value
	// the next point is set to null and the temp node is the return value 
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	return temp;
}

// function to test if the stack is empty by checking if the top node is empty
int isStackEmpty(){
	if(top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

// function to add a value to the stack by pushing at the top of the function
void push(int data){
	/*
		a temporary node is created using the createNode function and the next value of 
		temporary is set to point to top node and the new temporary node is set to be the top node
	*/
	node * temp = createNode(data);
	temp->next = top;
	top = temp;
	printf("\nStacked!\n");
}

//function to remove top node called pop simply sets 
//the top node to be the node below top node and delete the original top node
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

// function to see the top value on the stack
int peek(){
	if(!isStackEmpty()){
		return top->data;
	} else {
		printf("\nStack is Empty\n");
	}
}

// main function
int main(){
	printf("+++++++Stack Program+++++++\n");
	printf("Select Option n.b. used Integres as stack items \n");
	options:
	printf("1.Push (Add to stack) \n");
	printf("2.Pop (Remove top value) \n");
	printf("3.Peek (Show Top Value) \n");
	printf("4.Quit\n");
	printf(":");
	int i = 0;
	scanf("%d",&i);
	switch(i) {
		case 1:
			printf("Enter value to add to stack: ");
			int data = 0;
			scanf("%d", &data);
			push(data);
			goto options;
		case 2:
			pop();
			goto options;
		case 3:
			printf("Top Value is: ");
			printf("%d \n", peek());
			goto options;
		case 4:
			return 0;
					
	}
	
}
