#include <stdio.h>
#include <stdlib.h>

int MAXSIZE = 4;
int stack[4];
int top = -1;

int isFull(){
	//int n = sizeof(stack)/sizeof(int);
	if(top==MAXSIZE-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(int data){
	if(!isFull()){
		top = top + 1;
		stack[top] = data;
	}
	
}


void pop(){
	if(!isEmpty()){
		top -= 1;
	}
}

void printStack(){
//	if(!isEmpty){
		int i;
	//	printf("%d\n",top);
	
		while(i<=top){
			printf("%d\n",stack[i]);
			i++;
		}
	}
//}

int main(){
	
	push(78);
	push(34);
	push(7);
	pop();
	printStack();
	
	
}
