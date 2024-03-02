#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char sent[100], sub[10];
int posOfOcc[20];

int findFirstOcc(char* sent, char* sub, int posOfOcc[]) {
	int count = 0, i, sentlen, sublen;
	sentlen = strlen(sent);
	sublen = strlen(sub);
	for (i = 0; i < sentlen - sublen; i++)
		if (strncmp(sent + i, sub, sublen) == 0 && (i == 0 || sent[i - 1] == ' ') && (i == sentlen - sublen || sent[i + sublen] == ' '))
			posOfOcc[count++] = i;
	return (count);
}

int deleteAllOcc(char* sent, char* sub, int posOfOcc[]) {
	int posCount = findFirstOcc(sent, sub, posOfOcc);
	if (posCount != 0)
	{
		for (int i = 0; i < posCount; i++)
		{
			strcpy(sent + posOfOcc[i], sent + posOfOcc[i] + strlen(sub));
			for (int j = i; j < posCount; j++)
				posOfOcc[j] -= strlen(sub);
		}
		return (1);
	}
	return (0);
}

int main(void)
{
	printf("Enter a sentence: ");
	scanf("%[^\n]", sent);

	printf("Enter a word: ");
	scanf("%s", sub);

	int delProcess = deleteAllOcc(sent, sub, posOfOcc);
	if (delProcess == 1)
		printf("Final format of the sentence: %s\n", sent);
	else
		printf("The word <%s> does NOT exist ithis sentence\n", sub);

	return 0;
}