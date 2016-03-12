#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "create.h"

using namespace std;

int N = 0;
char Answer[32];
char input[10000][32];
int Count[10000];
int endStack;
void ResetStack(){
	endStack = 0;
	int i;
	for (i = 0; i < N; i++){
		Count[i] = 0;
	}
}
int InStack(char temp[]){
	int i;
	for (i = 0; i < endStack; i++){
		if (strcmp(temp, input[i]) == 0)return i;
	}
	return -1;
}
void Push(char temp[]){
	strcpy(input[endStack], temp);
	Count[endStack]++;
	endStack++;
}
void main(){
	//CreateInput(2);
	freopen("input.txt", "r", stdin);
	int testcase, NT;
	scanf("%d", &NT);
	for (testcase = 1; testcase <= NT; testcase++){
		scanf("%d", &N);
		int i = 0;
		ResetStack();
		for (i = 0; i < N; i++){
			char temp[32];
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
		printf("Testcase #%d %s %.0f%c", testcase, Answer, ((float)max / N * 100), '%');
	}
}