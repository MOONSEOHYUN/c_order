#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


//ī��Ʈ�ٿ�
void cd(int ls) {
	for (int i = 1; i <= ls; i++) {
		printf("... ");
		Sleep(1000);
	}
	printf("\n");
	printf("----------------------------------\n");
	printf("�����Ǿ����ϴ�.\n");

}
