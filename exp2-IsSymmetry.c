#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef char ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
	int stackSize;
}Stack;

void InitStack(Stack *S) {
	S -> base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S -> base) {
		exit(0);
	}
	S -> top = S -> base;
	S -> stackSize = STACK_INIT_SIZE;
}

void Push(Stack *S, ElemType e) {
	if (S -> top - S -> base >= S -> stackSize) {
		S -> base = (ElemType *)realloc(S -> base, (S -> stackSize + STACK_INCREMENT) * sizeof(ElemType));
		if (!S -> base) {
			exit(0);
		}
	}
	printf("Element %c is accepted\n", e);
	*(S -> top) = e;
	S -> top++;
}


char Pop(Stack *S) {
	ElemType e;
	if (S -> top == S -> base) {
		exit(0);
	}

	e = *--(S -> top);
	return e;
}

int StackLen(Stack *S) {
	printf("The length of this stack is %ld\n", S -> top - S -> base);
	return (S -> top - S -> base);
}

int IsSymmetry(Stack *S) {
	ElemType arr[10] = {0};
	int len = 0;
	int i   = 0;
	int ret = 0;

	len = StackLen(S);
	for (i = 0; i < len; i++) {
		arr[i] = Pop(S);
	}

	i = 0;

	while (i < len / 2) {
		if (arr[i] != arr[len - 1 - i]) {
			ret = 0;
		}

		else {
			ret = 1;
			i++;
		}
	}
	return ret;
}

int main() {
	ElemType c = '\0';
	Stack *S;
	int ret = 0;
	S = (Stack *)malloc(sizeof(Stack));

	printf("Please input the string, enter # if you want to stop\n");
	printf("Your string may not contain more than 10 characters\n");
	printf("Initializing the Stack\n");
	InitStack(S);
	printf("Done!\n");
	c = getchar();

	while (c != '#') {
		getchar();
		Push(S, c);
		c = getchar();
	}
	getchar();

	ret = IsSymmetry(S);
	if (ret == 1) {
		printf("It is a symmetry string!");
	}

	else {
		printf("It is not a symmetry string!");
	}
	return 0;
}
