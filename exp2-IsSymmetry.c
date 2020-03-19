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

void ExecPush(Stack *S, ElemType e) {
	while (e != '#') {
		getchar();
		Push(S, e);
		e = getchar();
	}
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

	printf("Please input binary number, enter # if you want to stop\n");
	printf("Initializing the Stack\n");
	InitStack(S);
	printf("Done!\n");
	c = getchar();
	ExecPush(S, c);

	ret = IsSymmetry(S);
	if (ret == 1) {
		printf("It is a symmetry string!");
	}

	else {
		printf("It is not a symmetry string!");
	}
	return 0;
}
