#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(LNode)

struct LNode
{
	char data[4];
	struct LNode *next;
};

struct LNode *createList();  // Create the list
LNode *locateElem(LNode *head, char elem[4]);  // Locate the node by its value
void insertList(LNode *head);
void printList(LNode *head);  // Print all nodes' value
void deleteList(LNode *head);  // Delete a node in the list
void deleteAll(LNode *head);  // Delete all nodes in the list

int main()
{
	struct LNode *head = (LNode*)malloc(LEN);  // The head node of the list
	char choice = '\0';  // User's choice
	char choice_1 = '\0';
	while (1)
	{
		printf("Please input which mode would you like?\n");
		printf("P.S. If you haven't built the list, please build it first!\n");
		printf("C(Create)/I(Insert)/D(Delete)/A(Delete All)/Q(Quit)");
		scanf("%s", &choice);
		
		if (choice == 'C')
		{
			printf("Please input the data that you want to input: \n");
			printf("Enter the word 'stop' if you want to stop entering! \n");
			printf("(You may not enter more than 4 words at a time!)\n");
			printf("(Please don't enter the same number more than twice!\n)");

			head = createList();  // Create the list
			printList(head);  // Print the list

			printf("The link list is already built! \n");
		}

		if (choice == 'I')
		{
			printf("Will you add a node in the list?\n");
			printf("(y/n)");
			getchar();
			scanf("%c", &choice_1);
			while (1)
			{
				if (choice_1 == 'y')		
				{
					insertList(head);
					break;
				}

				else if (choice_1 == 'n')
				{
					break;
				}

				else
				{
					printf("Please input 'y'(yes) or 'n'(no)\n");
				}
			}
		}

		if (choice == 'D')
		{
			printf("Will you delete a node in the list? \n");
			printf("(y/n)");
			getchar();  // Get rid of enter
			scanf("%c", &choice_1);
			while (1)
			{
				if (choice_1 == 'y')
				{
					deleteList(head);  // delete any nodes of the list
					break;
				}
				else if (choice_1 == 'n')
				{
					break;	
				}
				else
				{
					printf("Please input 'y'(yes) or 'n'(no)\n");
				}
			}
		}

		if (choice == 'A')
		{
			printf("Will you delete all nodes in the list? \n");
			printf("(y/n)");
			getchar();
			scanf("%c", &choice_1);
			while (1)
			{
				if (choice_1 == 'y')
				{
					deleteAll(head);  // delete all nodes of the list
					break;
				}
				else if (choice_1 == 'n')
				{
					printList(head);
					break;
				}
				else
				{
					printf("Please input 'y'(yes) or 'n'(no)\n");
				}
			}
		}

		if (choice == 'Q')
		{
			break;
		}
	}

	return 0;
}



struct LNode *createList()
{
	LNode *head;
	LNode *p;
	LNode *q;
	head = p = (LNode*)malloc(LEN);
	char new_data[4];
	while (1)
	{
		int ret;
		/*fgets(new_data, 5, stdin);*/
		/*getchar();*/
		scanf("%s", new_data);
		ret = strcmp(new_data, "stop");  // compare the data with "stop"
		
		if (ret == 0)
		{
			break;
		}
		else 
		{
			/*printf("data is: %s", data);*/
			/*printf("p -> data is: %s\n", p -> data);*/
			q = (LNode*)malloc(LEN);
			strcpy(q -> data, new_data);
			/*printf("q -> data is: %s\n", q -> data);*/
			q -> next = p -> next;
			p -> next = q;
			p = q;
			/*printf("p -> data is: %s\n", p -> data);*/
			/*printf("q -> data is: %s\n", q -> data);*/
			printf("You have entered a character: %s \n", q -> data);
		}
	}
	return head;
}// create the link list

void printList(LNode *head)
{
	LNode *p = head -> next;
	printf("These are your link list's values:  \n");
	while (p)
	{
		puts(p -> data);
		p = p -> next;
	}
}// print all elements in the link list


void deleteList(LNode *head)
{
	char choice;
	char elem[4];
	LNode *p = head;
	LNode *q = head;
	printf("Please input which value that you want to delete: \n");
	scanf("%s", elem);
	printf("elem is: %s \n", elem);
	/*p = locateElem(head, elem);*/
	while (strcmp(p -> next -> data, elem) != 0)
	{
		p = p -> next;
	}
	q = p -> next;
	p -> next = q -> next;
	free(q);

	printf("It's all done! \n");
	printList(head);
}// delete a node in the link list

void deleteAll(LNode *head)
{
	LNode *p = head;
	LNode *r;
	while (p -> next)
	{
		r = p -> next;
		free(p);
		p = r;
	}
	free(p);
	printList(head);
}// delete all nodes in the link list


void insertList(LNode *head)
{
	char elem[4];
	int num = 0;
	int i = 0;
	LNode *p = head;
	LNode *q = (LNode*)malloc(LEN);
	printf("Please input the number of the node that you want to add an element\n");
	scanf("%d", &num);
	printf("Please input the value of the element:\n");
	getchar();
	scanf("%s", elem);

	while (p && (i < num - 1))
	{
		p = p -> next;
		++i;
	}
	strcpy(q -> data, elem);
	q -> next = p -> next;
	p -> next = q;
	printf("It's all done!");
	printList(head);
}// add a node in the link list
