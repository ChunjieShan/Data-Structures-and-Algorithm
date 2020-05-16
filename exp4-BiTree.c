#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN sizeof(BiTree)
#define MAXLEN 30

typedef struct BiTree
{
    char data;
    struct BiTree *lChild;
    struct BiTree *rChild;
}BiTree;

BiTree *createTree()
{
    char c;
    scanf("%c", &c);
    BiTree *T = (BiTree*)malloc(LEN);
    if (c == ' ') {
        return NULL;
    }
    else {
        T = (BiTree *)malloc(LEN);
        T->data = c;
        T->lChild = createTree();
        T->rChild = createTree();
    }
    return T;
}// createTree

void preOrderTraverse(BiTree *T)
{
    if (T) {
        printf("%c ", T->data);
        preOrderTraverse(T->lChild);
        preOrderTraverse(T->rChild);
    }
}// preOrderTraverse


void inOrderTraverse(BiTree *T)
{
    if (T) {
        preOrderTraverse(T->lChild);
        printf("%c ", T->data);
        preOrderTraverse(T->rChild);
    }
}// inOrderTraverse

void postOrderTraverse(BiTree *T)
{
    if (T) {
        preOrderTraverse(T->lChild);
        preOrderTraverse(T->rChild);
        printf("%c ", T->data);
    }
}// postOrderTraverse

int getHeight(BiTree *T)
{
    int height = 0;
    int lHeight = 0;
    int rHeight = 0;
    if (T != NULL) {
        lHeight = getHeight(T->lChild);
        rHeight = getHeight(T->rChild);
        if (lHeight > rHeight) {
            height = lHeight + 1;
        }
        else {
            height = rHeight + 1;
        }
    }
    return height;
}// getHeight

void levelOrderTraverse(BiTree *T)
{
    int front = 0;
    int rear = 0;
    BiTree *que[MAXLEN];
    BiTree *q;
    if (T) {
        rear = (rear + 1) % MAXLEN;
        que[rear] = T;
        while (front != rear) {
            front = (front + 1) % MAXLEN;
            q = que[front];
            printf("%c ", q->data);
            if(q->lChild) {
                rear = (rear + 1) % MAXLEN;
                que[rear] = q->lChild;
            }
            if (q->rChild) {
                rear = (rear + 1) % MAXLEN;
                que[rear] = q->rChild;
            }
        }

    }
}// levelOrderTraverse

int countLeaf(BiTree *T)
{
    if (T == NULL) {
        return 0;
    }
    else {
        if (!T->lChild && !T->rChild) {
            return 1;
        }
        return countLeaf(T->lChild) + countLeaf(T->rChild);
    }
}// countLeaf


void exchangeTree(BiTree *T)
{
    if (T) {
        exchangeTree(T->lChild);
        exchangeTree(T->rChild);
        BiTree *temp = (BiTree*)malloc(LEN);
        temp = T->lChild;
        T->lChild = T->rChild;
        T->rChild = temp;
    }
}// exchangeTree

int main()
{
    BiTree *T = (BiTree*)malloc(LEN);
    int height = 0;
    int numLeaf = 0;
    int choice = 0;

    printf("Please input the elements in preorder way:\n");
    T = createTree();  // return a BiTree variable.
    printf("The tree is created!\n");
    /* preOrderTraverse(T);  // preorder traverse */

    printf("Preorder traverse results:\n");
    preOrderTraverse(T);  // preorder traverse
    printf("\n");

    printf("In order traverse results:\n");
    inOrderTraverse(T);  // in order traverse
    printf("\n");

    printf("Post order traverse results:\n");
    postOrderTraverse(T);  // post order traverse
    printf("\n");

    printf("Level order traverse results:\n");
    levelOrderTraverse(T);
    printf("\n");

    height = getHeight(T);  //  get the height of the tree.
    printf("The height of the tree is: %d\n", height);

    numLeaf = countLeaf(T);  // get the amount of the leaves.
    printf("The amount of the leaf nodes is: %d\n", numLeaf);
    printf("The result of exchanging subtree:\n");
    exchangeTree(T);
    preOrderTraverse(T);

    return 0;
}
