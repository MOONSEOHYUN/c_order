#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS //getch()�Լ� ���
#include <stdio.h>
#include <string.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "cntd.h"

//����ü
typedef struct {
	char id[20];
	//char pw[20];
	int no;
	char k[30];
	int p;
	int b;

	//����ð�
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
}Mem;

int cnt = 0;
Mem* pcnt = NULL;
int a;
int b = 1;


//ȸ�� or ��ȸ�� �ֹ�
void order() {
EXIT:
	printf("----------------------------------\n");
	printf("1. �α���\n2. ��ȸ�� �ֹ�\n");
	printf("�Է�> ");
	scanf("%d", &a);

	if (a == 1) {
		printf("----------------------------------\n");
		printf("���̵� �Է��ϼ���.\n> ");
		scanf("%s", (pcnt + cnt - 1)->id);
		printf("��й�ȣ�� �Է��ϼ���.\n> ");
		//scanf("%s", (pcnt + cnt - 1)->pw);
		char pw[20];
		for (int i = 0; i < 20; i++) {
			pw[i] = getch();
			//(pcnt + cnt - 1)->pw[i] = getch();
			//strcpy((pcnt + cnt - 1)->pw[i], getch());
			if (pw[i] == 13) {
				pw[i]='\0';
				break;
			}
			else
				printf("*");
		}
		printf("\n");
	}
	else if (a == 2) {
		//strcpy((pcnt + i)->id, (char)(i + 1));
		//(pcnt + i)->id = (i + 1);
		(pcnt + cnt - 1)->no = cnt;
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		goto EXIT;
	}
}

//�޴�
void menu() {
	char menu[][10] = { "����","ġŲ","�ѽ�" };
	char(*pn)[10] = menu;
	char piz[][30] = { "��ο�ӽ�������",  "���۷δ�����","���ްŽ�������ũ����", "��Ÿ�̰�����" };
	char(*pp)[30] = piz;
	char chi[][30] = { "�Ķ��̵�","�ݹݿ�������","���̺���ũ","�Ѹ�Ŭ" };
	char(*pc)[30] = chi;
	char kf[][30] = { "��ġ�","�δ��","��������","�ø�" };
	char(*pk)[30] = kf;

EXIT:
	printf("----------------------------------\n");
	printf("�޴��� �����ϼ���.\n");
	printf("1. %s  2. %s  3. %s\n", pn, pn + 1, pn + 2);
	printf("�Է�> ");
	scanf("%d", &a);


	if (a == 1) {
	PIZ:
		printf("----------------------------------\n");
		printf("�޴��� �����ϼ���.\n");
		printf("1. %s  2. %s  3. %s  4. %s\n", pp, pp + 1, pp + 2, pp + 3);
		printf("�Է�> ");
		scanf("%d", &a);
		switch (a) {
		case 1:
			strcpy((pcnt + cnt - 1)->k, *pp);
			(pcnt + cnt - 1)->p = 27500; break;
		case 2:
			strcpy((pcnt + cnt - 1)->k, *(pp + 1));
			(pcnt + cnt - 1)->p = 23500; break;
		case 3:
			strcpy((pcnt + cnt - 1)->k, *(pp + 2));
			(pcnt + cnt - 1)->p = 34900; break;
		case 4:
			strcpy((pcnt + cnt - 1)->k, *(pp + 3));
			(pcnt + cnt - 1)->p = 34900; break;
		default:
			printf("----------------------------------\n");
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			goto PIZ;
		}
	}
	else if (a == 2) {
	CHI:
		printf("----------------------------------\n");
		printf("�޴��� �����ϼ���.\n");
		printf("1. %s  2. %s  3. %s  4. %s\n", pc, pc + 1, pc + 2, pc + 3);
		printf("�Է�> ");
		scanf("%d", &a);
		switch (a) {
		case 1:
			strcpy((pcnt + cnt - 1)->k, *pc);
			(pcnt + cnt - 1)->p = 9900;

			break;
		case 2:
			strcpy((pcnt + cnt - 1)->k, *(pc + 1));
			(pcnt + cnt - 1)->p = 16000; break;
		case 3:
			strcpy((pcnt + cnt - 1)->k, *(pc + 2));
			(pcnt + cnt - 1)->p = 9900; break;
		case 4:
			strcpy((pcnt + cnt - 1)->k, *(pc + 3));
			(pcnt + cnt - 1)->p = 17000; break;
		default:
			printf("----------------------------------\n");
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			goto CHI;
		}
	}
	else if (a == 3) {
	KF:
		printf("----------------------------------\n");
		printf("�޴��� �����ϼ���.\n");
		printf("1. %s  2. %s  3. %s  4. %s\n", kf, kf + 1, kf + 2, kf + 3);
		printf("�Է�> ");
		scanf("%d", &a);
		switch (a) {
		case 1:
			strcpy((pcnt + cnt - 1)->k, *kf);
			(pcnt + cnt - 1)->p = 6000; break;
		case 2:
			strcpy((pcnt + cnt - 1)->k, *(kf + 1));
			(pcnt + cnt - 1)->p = 8000; break;
		case 3:
			strcpy((pcnt + cnt - 1)->k, *(kf + 2));
			(pcnt + cnt - 1)->p = 8000; break;
		case 4:
			strcpy((pcnt + cnt - 1)->k, *(kf + 3));
			(pcnt + cnt - 1)->p = 7000; break;
		default:
			printf("----------------------------------\n");
			printf("�߸� �Է��ϼ̽��ϴ�,\n");
			goto KF;
		}
	}
	else {
		printf("----------------------------------\n");
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		goto EXIT;
	}
}

//����ð�
void time3() {
	time_t x;
	struct tm* y;
	x = time(NULL);
	y = localtime(&x);

	(pcnt + cnt - 1)->year = y->tm_year + 1900;
	(pcnt + cnt - 1)->month = y->tm_mon + 1;
	(pcnt + cnt - 1)->day = y->tm_mday;
	(pcnt + cnt - 1)->hour = y->tm_hour;
	(pcnt + cnt - 1)->min = y->tm_min;
	(pcnt + cnt - 1)->sec = y->tm_sec;
}

//���
void ppp() {
	for (int i = 0; i < cnt; i++) {
		if ((pcnt + i)->no == i + 1) {			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("�� ��ȸ��: %d����, �޴�: %s, ����: %d���Դϴ�.\n", (pcnt + i)->no, (pcnt + i)->k, (pcnt + i)->p);
			//����ð� �Լ�ȣ��
			//time1();
			//time2();

			printf("�� �ֹ��ð� : %d�� %d�� %d�� %d�� %d�� %d��\n", (pcnt+i)->year, (pcnt + i)->month, (pcnt + i)->day, (pcnt + i)->hour, (pcnt + i)->min, (pcnt + i)->sec);
			printf("�� ��޿����ð�: %d�� %d�� %d�� %d�� %d�� %d��\n", (pcnt + i)->year, (pcnt + i)->month, (pcnt + i)->day, (pcnt + i)->hour+1, (pcnt + i)->min, (pcnt + i)->sec);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			if ((pcnt + i)->b == 0) break;
		}

		else {		
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("�� ȸ��: %s��, �޴�: %s, ����: %d���Դϴ�.\n", (pcnt + i)->id, (pcnt + i)->k, (pcnt + i)->p);
			//����ð� �Լ�ȣ��
			//time1();
			//time2();

			printf("�� �ֹ��ð� : %d�� %d�� %d�� %d�� %d�� %d��\n", (pcnt + i)->year, (pcnt +i)->month, (pcnt + i)->day, (pcnt + i)->hour, (pcnt + i)->min, (pcnt + i)->sec);
			printf("�� ��޿����ð�: %d�� %d�� %d�� %d�� %d�� %d��\n", (pcnt + i)->year, (pcnt + i)->month, (pcnt + i)->day, (pcnt + i)->hour + 1, (pcnt + i)->min, (pcnt + i)->sec);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			if ((pcnt + i)->b == 0) break;
		}
	}
}

////����
//void sum(int* ps) {
//	if (*ps ==0)
//		printf("ǰ���Ǿ����ϴ�. �ٸ� �޴��� ������ �ּ���.\n");
//	//*ps-=*ps;
//}


int main() {
	printf("----------------------------------\n");
	printf("        ���Ĺ��v0.1\n");
	printf("----------------------------------\n");
	while (1) {
		cnt++;
		pcnt = (Mem*)realloc(pcnt, sizeof(Mem)*cnt);
		//ȸ�� or ��ȸ�� �ֹ�
		order();
		//�޴�
		MENU:
		menu();

		PAY:
		printf("----------------------------------\n");
		printf("0. �����ϱ�  1. �޴�\n");
		printf("�Է�> ");
		scanf("%d", &(pcnt + cnt - 1)->b);
		if ((pcnt + cnt - 1)->b == 0) {
			//����ð�
			time3();
			//ī��Ʈ�ٿ�
			cd(3);
			
			EXIT2:
			printf("----------------------------------\n");
			printf("0.����  1. ���θ޴�\n");
			printf("�Է�> ");
			scanf("%d", &(pcnt + cnt - 1)->b);
			if ((pcnt + cnt - 1)->b == 0) {
				b = (pcnt + cnt - 1)->b;
				printf("----------------------------------\n");
				printf("�ֹ��� �Ϸ�Ǿ����ϴ�.\n");
				break;
			}


			else if ((pcnt + cnt - 1)->b == 1) {
				continue;
			}
			else {
				printf("----------------------------------\n");
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
				goto EXIT2;
			}
		}
		else if ((pcnt + cnt - 1)->b == 1) {
			goto MENU;
		}
		else if ((pcnt + cnt - 1)->b != 0 && (pcnt + cnt - 1)->b != 1) {
			printf("----------------------------------\n");
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			goto PAY;
		}
	}
	//����Լ�
	ppp();




















}