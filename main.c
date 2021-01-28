#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS //getch()함수 사용
#include <stdio.h>
#include <string.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "cntd.h"

//구조체
typedef struct {
	char id[20];
	//char pw[20];
	int no;
	char k[30];
	int p;
	int b;

	//현재시간
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


//회원 or 비회원 주문
void order() {
EXIT:
	printf("----------------------------------\n");
	printf("1. 로그인\n2. 비회원 주문\n");
	printf("입력> ");
	scanf("%d", &a);

	if (a == 1) {
		printf("----------------------------------\n");
		printf("아이디를 입력하세요.\n> ");
		scanf("%s", (pcnt + cnt - 1)->id);
		printf("비밀번호를 입력하세요.\n> ");
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
		printf("잘못 입력하셨습니다.\n");
		goto EXIT;
	}
}

//메뉴
void menu() {
	char menu[][10] = { "피자","치킨","한식" };
	char(*pn)[10] = menu;
	char piz[][30] = { "멜로우머쉬룸피자",  "페퍼로니피자","블랙앵거스스테이크피자", "블랙타이거피자" };
	char(*pp)[30] = piz;
	char chi[][30] = { "후라이드","반반오리지널","현미베이크","뿌링클" };
	char(*pc)[30] = chi;
	char kf[][30] = { "김치찌개","부대찌개","제육볶음","냉면" };
	char(*pk)[30] = kf;

EXIT:
	printf("----------------------------------\n");
	printf("메뉴를 선택하세요.\n");
	printf("1. %s  2. %s  3. %s\n", pn, pn + 1, pn + 2);
	printf("입력> ");
	scanf("%d", &a);


	if (a == 1) {
	PIZ:
		printf("----------------------------------\n");
		printf("메뉴를 선택하세요.\n");
		printf("1. %s  2. %s  3. %s  4. %s\n", pp, pp + 1, pp + 2, pp + 3);
		printf("입력> ");
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
			printf("잘못 입력하셨습니다.\n");
			goto PIZ;
		}
	}
	else if (a == 2) {
	CHI:
		printf("----------------------------------\n");
		printf("메뉴를 선택하세요.\n");
		printf("1. %s  2. %s  3. %s  4. %s\n", pc, pc + 1, pc + 2, pc + 3);
		printf("입력> ");
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
			printf("잘못 입력하셨습니다.\n");
			goto CHI;
		}
	}
	else if (a == 3) {
	KF:
		printf("----------------------------------\n");
		printf("메뉴를 선택하세요.\n");
		printf("1. %s  2. %s  3. %s  4. %s\n", kf, kf + 1, kf + 2, kf + 3);
		printf("입력> ");
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
			printf("잘못 입력하셨습니다,\n");
			goto KF;
		}
	}
	else {
		printf("----------------------------------\n");
		printf("잘못 입력하셨습니다.\n");
		goto EXIT;
	}
}

//현재시간
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

//출력
void ppp() {
	for (int i = 0; i < cnt; i++) {
		if ((pcnt + i)->no == i + 1) {			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("▶ 비회원: %d번님, 메뉴: %s, 가격: %d원입니다.\n", (pcnt + i)->no, (pcnt + i)->k, (pcnt + i)->p);
			//현재시간 함수호출
			//time1();
			//time2();

			printf("○ 주문시간 : %d년 %d월 %d일 %d시 %d분 %d초\n", (pcnt+i)->year, (pcnt + i)->month, (pcnt + i)->day, (pcnt + i)->hour, (pcnt + i)->min, (pcnt + i)->sec);
			printf("● 배달예정시간: %d년 %d월 %d일 %d시 %d분 %d초\n", (pcnt + i)->year, (pcnt + i)->month, (pcnt + i)->day, (pcnt + i)->hour+1, (pcnt + i)->min, (pcnt + i)->sec);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			if ((pcnt + i)->b == 0) break;
		}

		else {		
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("▶ 회원: %s님, 메뉴: %s, 가격: %d원입니다.\n", (pcnt + i)->id, (pcnt + i)->k, (pcnt + i)->p);
			//현재시간 함수호출
			//time1();
			//time2();

			printf("○ 주문시간 : %d년 %d월 %d일 %d시 %d분 %d초\n", (pcnt + i)->year, (pcnt +i)->month, (pcnt + i)->day, (pcnt + i)->hour, (pcnt + i)->min, (pcnt + i)->sec);
			printf("● 배달예정시간: %d년 %d월 %d일 %d시 %d분 %d초\n", (pcnt + i)->year, (pcnt + i)->month, (pcnt + i)->day, (pcnt + i)->hour + 1, (pcnt + i)->min, (pcnt + i)->sec);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			if ((pcnt + i)->b == 0) break;
		}
	}
}

////수량
//void sum(int* ps) {
//	if (*ps ==0)
//		printf("품절되었습니다. 다른 메뉴를 선택해 주세요.\n");
//	//*ps-=*ps;
//}


int main() {
	printf("----------------------------------\n");
	printf("        음식배달v0.1\n");
	printf("----------------------------------\n");
	while (1) {
		cnt++;
		pcnt = (Mem*)realloc(pcnt, sizeof(Mem)*cnt);
		//회원 or 비회원 주문
		order();
		//메뉴
		MENU:
		menu();

		PAY:
		printf("----------------------------------\n");
		printf("0. 결제하기  1. 메뉴\n");
		printf("입력> ");
		scanf("%d", &(pcnt + cnt - 1)->b);
		if ((pcnt + cnt - 1)->b == 0) {
			//현재시간
			time3();
			//카운트다운
			cd(3);
			
			EXIT2:
			printf("----------------------------------\n");
			printf("0.종료  1. 메인메뉴\n");
			printf("입력> ");
			scanf("%d", &(pcnt + cnt - 1)->b);
			if ((pcnt + cnt - 1)->b == 0) {
				b = (pcnt + cnt - 1)->b;
				printf("----------------------------------\n");
				printf("주문이 완료되었습니다.\n");
				break;
			}


			else if ((pcnt + cnt - 1)->b == 1) {
				continue;
			}
			else {
				printf("----------------------------------\n");
				printf("잘못 입력하셨습니다.\n");
				goto EXIT2;
			}
		}
		else if ((pcnt + cnt - 1)->b == 1) {
			goto MENU;
		}
		else if ((pcnt + cnt - 1)->b != 0 && (pcnt + cnt - 1)->b != 1) {
			printf("----------------------------------\n");
			printf("잘못 입력하셨습니다.\n");
			goto PAY;
		}
	}
	//출력함수
	ppp();




















}