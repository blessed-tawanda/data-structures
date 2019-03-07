#include <stdio.h>
#include <stdlib.h>

/*
Tower of Hanoi consists of three pegs or towers with n disks placed one over the other. 
The objective of the puzzle is to move the stack to another peg following these simple rules.
    1.Only one disk can be moved at a time.
    2.No disk can be placed on top of the smaller disk.
Using recursion this can be done create a function that gets the number of discs to be moved
the from peg
the aux peg
the to peg
if the number of disks is 1 move it to the last peg
if there are more disks 
*/

void tower(int a, char from, char aux, char to) {
	if(a==1) {
		printf("Move disc 1 from %c to %c \n", from, to);
		return;
	} else {
		tower(a-1,from,to,aux);
		printf("Move disc %d from %c to %c \n",a,from,to);
		tower(a-1,aux,from,to);
	}
}

void main() {
	int n;
	printf("+++++++ Tower Of Hanoi +++++++\n");
	printf("Enter number of discs: ");
	scanf("%d",&n);
	tower(n,'A','B','C');
	scanf("%d");
}
