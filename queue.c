#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct queueNode{
	int data;
	struct queueNode *next;
} queueNode;

queueNode *top;
queueNode *bottom;

queueNode * createNode(int x){
	queueNode * temp = (queueNode*)malloc(sizeof(queueNode));
	temp->data = x;
	temp->next = NULL;
	return temp;
}

int isQueueEmpty(){
	if(top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void addToQueue(int data){
	queueNode * temp = createNode(data);
	if(top==NULL){
		top = bottom = temp;
	}
	bottom->next = temp;
	bottom = temp;
} //enqueue function

void removeFromQueue(){
	queueNode * temp;
	if(!isQueueEmpty()){
		temp = top;
		printf("Dequeued: %d\n",temp->data);
		top = temp->next; 
		free(temp);	
	}
	else
		printf("\nQueue is Empty\n");
		
}

int queueSize(){
	queueNode * temp = top;
	int size = 0;
	while(temp!=NULL){
		size++;
		temp = temp->next;
	}
	return size;
}


int main(){
	addToQueue(67);
	addToQueue(45);
	addToQueue(50);
	removeFromQueue();
	removeFromQueue();
	removeFromQueue();
	removeFromQueue();
	printf("\nSize of Queue is: %d", queueSize());
	return 0;
}









