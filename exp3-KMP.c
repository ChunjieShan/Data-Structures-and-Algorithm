#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char *ch;
	int length;
} Str;

void getNext(Str T, int next[])
{
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (i < T.length) {
		if (j == -1 || T.ch[i] == T.ch[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

int indexKmp(Str S, Str T, int next[])
{
	// printf("Starting executing KMP algorithm\n");
	int i = 0;
	int j = 1;
	while(i < S.length && j < T.length) {
		if (j == -1 || S.ch[i] == T.ch[j]) {
			++i;
			++j;
			/* printf("i = %d, j = %d\n", i, j); */
		}
		else {
			j = next[j];
		}
	}

	if (j >= T.length) {
        /* printf("j is now: %d\n", j); */
		return i - T.length;
	}
	else {
        /* printf("Not success!\n"); */
		return -1;
	}
}

int strAssign(Str string, char *ch)
{
	if (string.ch) {
		free(string.ch);
	}

	int len = 0;
	char *c = ch;
	// puts(ch);

	while (*c) {
		++len;
		++c;
	}
	// printf("%d\n", len);

	if (len == 0) {
		string.ch = NULL;
		string.length = 0;
		return -1;
	}

	else {
		string.ch = (char *)malloc(sizeof(char) * (len + 1));
		if (string.ch == NULL) {
			return 0;
		}
		else {
			c = ch;
			for (int i = 0; i <= len; ++i, ++c) {
				string.ch[i] = *c;
			}
			string.length = len;
			return -1;
		}
	}

}

int main()
{
	int next[5] = {0};
	int res;
	Str S;
	S.ch = (char *)malloc(sizeof(char));
	S.length = 10;
	Str T;
	T.ch = (char *)malloc(sizeof(char));
	T.length = 5;

    /* fgets(S.ch, 11, stdin); */
    /* fgets(T.ch, 6, stdin); */
    printf("Please enter the main string with your keyboard!\n");
    scanf("%s", S.ch);

    printf("Please enter the sub string with your keyboard!\n");
    scanf("%s", T.ch);

	/* puts(S.ch); */
	/* puts(T.ch); */

	getNext(T, next);
	/* for (int i = 0; i < 5; i++) { */
	/* 	printf("%d\n", next[i]); */
	/* } */

	res = indexKmp(S, T, next);
    printf("res = %d\n", res);
	if (res == -1) {
		printf(" \nThe substring is not match to the main string!\n");
	}

	else {
		printf(" \nThe substring is match to the main string at the position of character %d\n", res);
	}

	return 0;
}
