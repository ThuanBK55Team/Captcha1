#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "createTestcase.h"

using namespace std;

#define MAX 32

int N = 0;
char Answer[MAX];
char input[10001][MAX];
int Count[10001];
int endStack;
void ResetStack(){
	endStack = 0;
	int i;
	for (i = 0; i < N; i++){
		Count[i] = 0;
	}
}
int InStack(char temp[MAX]){
	int i;
	for (i = 0; i < endStack; i++){
		if (strcmp(temp, input[i]) == 0)return i;
	}
	return -1;
}
void Push(char temp[MAX]){
	strcpy(input[endStack], temp);
	Count[endStack]++;
	endStack++;
}
void main(){
	CreateInput(20);
	freopen("input.txt", "r", stdin);
	int testcase, NT;
	scanf("%d", &NT);
	for (testcase = 1; testcase <= NT; testcase++){
		scanf("%d", &N);
		int i = 0;
		ResetStack();
		for (i = 0; i < N; i++){
			char temp[MAX];
			scanf("%s", temp);
			int dirInStack = InStack(temp);
			if (dirInStack >= 0)Count[dirInStack]++;
			else Push(temp);
		}
		int max = 0;
		for (i = 0; i < N; i++){
			if (Count[i]>max){
				max = Count[i];
				strcpy(Answer, input[i]);
			}
		}
		printf("Testcase #%d %s %.0f%c\n", testcase, Answer, ((float)max / N * 100), '%');
	}
}