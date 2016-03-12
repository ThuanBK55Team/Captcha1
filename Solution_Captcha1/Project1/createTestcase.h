#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
#define MAX 32

void CreateInput(int NT){
	int i, j, k;
	ofstream fileinput, fileanswer;
	fileinput.open("input.txt");
	fileanswer.open("answer.txt");

	int testcase;
	int N = 0;
	char Answer[MAX];
	char input[10001][MAX];
	int Count[10001];
	int endStack;
	int CountAnswer;

	fileinput << NT << endl;
	for (testcase = 1; testcase <= NT; testcase++){
		N = (rand() % 5 + 1) * testcase * 100;
		fileinput << N << endl;
		// Create Answer
		int length = (rand() % (MAX - 1)) + 1;
		for (i = 0; i < length; i++){
			Answer[i] = rand() % 26 + 97;
		}
		Answer[i] = '\0';
		CountAnswer = rand() % N + 1;

		// Create testcase
		for (i = 0; i < N; i++){
			char temp[MAX];
			int length = (rand() % (MAX - 1)) + 1;
			for (j = 0; j < length; j++){
				temp[j] = rand() % 26 + 97;
			}
			temp[j] = '\0';
			strcpy(input[i], temp);
		}
		// Replace by Answer Array
		int temp = 0;
		for (i = 0; i < N; i++){
			if (strcmp(input[i], Answer) == 0)temp++;
		}
		while (temp < CountAnswer){
			i = rand() % N;
			if (strcmp(input[i], Answer) != 0){
				strcpy(input[i], Answer);
				temp++;
			}
		}
		CountAnswer = temp;
		for (i = 0; i < N; i++){
			fileinput << input[i] << endl;
		}
		fileanswer << "Testcase #" << testcase << " " << N << " " << Answer << " " << (float)CountAnswer / N * 100 << endl;
	}
	fileinput.close();
	fileanswer.close();
}