#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//Node for linked list with next pointer
typedef struct node{
	int data;
	struct node * next;
} node;
//Intialising the head and tail pointers to NULL since they are pointing to nothing
node *head=NULL;
node *tail=NULL;
//Function to create a node
node * createNode(int x){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	return temp;
}
//Function to add on top of the linked list
void addOnTopOfList(int data){
	node * temp = createNode(data);
	temp->next = head;
	head = temp;
	printf("\nAdded!\n");
}
//Function to add at the end of the linked list
void addToTheEndOfList(int data){
	node * temp = createNode(data);
	tail->next = temp;
	tail = temp;
	printf("\nAdded!\n");
}
//Function to create a list with specified number of nodes n
void createList(int n){
	node *temp = NULL;
	int i;
	for(i=0;i<n;i++){
		temp = (node*)malloc(sizeof(node));
		printf("Enter data for node number %d: ",i+1);
		scanf("%d",&temp->data);
		if(head==NULL){
			temp->next = NULL;
			head = tail = temp;
		}
		else{
			temp->next=NULL;
			tail->next = temp;
			tail = temp;
			
		}
	}
}
//Function to insert a node after a specified node elementBefore
void insertAfter(int elementBefore, int elementToInsert){
	node *nodeBefore = head;
	while(nodeBefore!=NULL){
		if(nodeBefore->data==elementBefore){
			node *newNode = createNode(elementToInsert);
			newNode->next = nodeBefore->next;
			nodeBefore->next = newNode;
			break;
		}
		nodeBefore = nodeBefore->next;
	}
}

// function to count the number of elements in list
int countList(){
	node *temp = head;
	int n = 0;
	while(temp!=NULL){
		temp = temp->next;
		n++;
	}
	return n;
}


// function to print list from the front of list
void printList(){
	node *temp = head;
	int n = 1;
	while(temp!=NULL){
		printf("Data for %d: %d \n", n ,temp->data);
		temp = temp->next;
		n++;
	}
}
// function to search for a specific node searchVal
void search(int searchVal){
	node *temp = head;
	int n = 1;
	int flag = 0;
	while(temp!=NULL && flag==0){
		if(temp->data==searchVal){
			printf("Found %d at %d \n", temp->data , n);
			flag = 1;
		}
		temp = temp->next;
		n++;
	}
	printf("\nData Not Found, Not in list\n");
}
// function to remove specific element itemToRemove
void removeItem(int itemToRemove){
	node *temp = head;
	if(itemToRemove==head->data){
		if(head==tail){
			head=tail=NULL;
		}
		else{
			head = head->next;
		}
	}
	while(temp != NULL && temp->data != itemToRemove){
		temp = temp->next;
	}
	if(temp->next != NULL){
		if(temp->next == tail){
			tail = temp;
		}		
		temp->next=(temp->next)->next;
	}
}

// driver function to use all the other functions
int main(){
	int command;
	int data;
	int numberOfNodes;
	printf("======== Program Impementing A list (Stores a List of Numbers) ========== \n");
	options:
	printf("\n==============================================================================\n");
	printf("\nAvailable Options:\n");
	printf(">1. CREATE_LIST \n>2. INSERT \n>3. SEARCH \n>4. VIEW\n>5. Add To The Top Of List\n>6. Add to The End Of List\n>7. Count Elements\n>8. Remove Item\nSelect Option:");
	scanf("%d",&command);
	switch (command){
		case 1:
			printf("Enter Number of Nodes to Add: ");
			int n;
			scanf("%d",&n);
			createList(n);
			goto options;
		case 2:
			printf("Enter the Value of the element you want to insert after: ");
			int elementBefore;
			scanf("%d",&elementBefore);
			printf("Enter the Value of element to insert: ");
			int elementToInsert;
			scanf("%d",&elementToInsert);
			insertAfter(elementBefore,elementToInsert);
			goto options;
		case 3:
			printf("\n");
			printf("Enter Value you would like to search: ");
			int searchvalue;
			scanf("%d",&searchvalue);
			search(searchvalue);
			goto options;
		case 4: 
			printf("\n");
			printList();
			goto options;
		case 5:
			if(head==NULL){
				printf("\nPlease Create List First!\n");
				goto options;
			}
			printf("\nEnter The Value You Want to Add: ");
			scanf("%d",&data);
			addOnTopOfList(data);
			goto options;
		case 6:
			if(head==NULL){
				printf("\nPlease Create List First!\n");
				goto options;
			}
			printf("\nEnter The Value You Want to Add: ");
			scanf("%d",&data);
			addToTheEndOfList(data);
			goto options;
		case 7:
			numberOfNodes = countList();
			printf("\nThere are %d items in List\n",numberOfNodes);
			goto options;
		case 8:
			if(head==NULL){
				printf("\nPlease Create List First!\n");
				goto options;
			}
			printf("\nEnter The Value To Remove: ");
			scanf("%d",&data);
			removeItem(data);
			goto options;
		default:
			break;
	}
//	printf("Enter Number of Nodes to Add: ");
//			int n;
//			scanf("%d",&n);
//			createList(n);
//	insertAfter(34,56);
//	printList();		
		
	return 0;
}
