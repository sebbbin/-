#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct student
{
	char name[20];
	double A, B, C, D, E, F, a, b, c, d, e, f;
	double average;

}Student;

void choice_menu();
void menu_1();
void menu_2();
void menu_3();
void menu_4();
void menu_5();
double cal(int score);
void processMenu(char choice);
void myflush();

int main()
{
	char ch = NULL;

	choice_menu();
	while (ch != 'q')
	{
		scanf("%c", &ch);
		if ('1' <= ch && ch <= '6') {
			processMenu(ch);
		}
		else if (ch == 'q') {
			break;
		}

	}
	printf("프로그램 종료\n");

	return 0;
}

Student std[20];
Student std_dest[20];
Student temp;
int len = 0;

void choice_menu() //메뉴
{
	printf("          성적관리 프로그램 \n\n");
	printf("---------------M E N U---------------\n\n");
	printf("1.과목 정보 입력 \n\n");
	printf("2.학생의 과목 점수 출력 \n\n");
	printf("3.학생 과목 성적순 출력 \n\n");
	printf("4.학생 데이터 수정 \n\n");
	printf("5.학생 정보 삭제 \n\n");
	printf("메뉴를 입력하세요('q' 입력시 종료): ");
}

void menu_1() // 과목명과 각 성적입력 
{
	int i;

	printf("과목 정보를 입력하세요.\n");

	for (i = len; i < len + 1; i++)
	{
		printf("과목 : ");
		scanf("%s", std[i].name);
		do {
			printf("첫번째 성적 입력(0~100점 입력): ");
			scanf("%d", &std[i].A);
			if (std[i].A < 0 || std[i].A > 100)
			{
				printf("입력 오류!! 성적을 재입력하세요.\n");
			}
		} while (std[i].A < 0 || std[i].A > 100);
		std[i].a = cal(std[i].A);

		do {
			printf("두번째 성적 입력(0~100점 입력): ");
			scanf("%d", &std[i].B);
			if (std[i].B< 0 || std[i].B > 100)
			{
				printf("입력 오류!! 성적을 재입력하세요.\n");
			}
		} while (std[i].B < 0 || std[i].B> 100);
		std[i].b = cal(std[i].B);

		do {
			printf("세번째 성적 입력(0~100점 입력): ");
			scanf("%d", &std[i].ectN);
			if (std[i].C < 0 || std[i].C > 100)
			{
				printf("입력 오류!! 성적을 재입력하세요.\n");
			}
		} while (std[i].C < 0 || std[i].C > 100);
		std[i].c = cal(std[i].C);

		do {
			printf("네번째 성적 입력(0~100점 입력): ");
			scanf("%d", &std[i].D);
			if (std[i].D < 0 || std[i].D > 100)
			{
				printf("입력 오류!! 성적을 재입력하세요.\n");
			}
		} while (std[i].D < 0 || std[i].D > 100);
		std[i].d = cal(std[i].D);

		do {
			printf("다섯번째 성적 입력(0~100점 입력): ");
			scanf("%d", &std[i].E);
			if (std[i].E< 0 || std[i].E > 100)
			{
				printf("입력 오류!! 성적을 재입력하세요.\n");
			}
		} while (std[i].E < 0 || std[i].E > 100);
		std[i].e = cal(std[i].E);

		do {
			printf("여섯번째 성적 입력(0~100점 입력): ");
			scanf("%d", &std[i].F);
			if (std[i].F < 0 || std[i].F > 100)
			{
				printf("입력 오류!! 성적을 재입력하세요.\n");
			}
		} while (std[i].F< 0 || std[i].F > 100);
		std[i].f = cal(std[i].F);


		std[i].average = (std[i].a + std[i].b + std[i].c + std[i].d + std[i].e + std[i].f) / 6;
	}
	len++;
	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_2() //2. 이름과 과목을 입력 받아 해당 학생의 해당 과목 점수를 출력
{
	char name[20];
	char subject[20];
	int i;
	int ok = 0;
	printf("과목 입력: ");
	scanf("%s", name);
here:
	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			printf("[ %s ]과목의 성적입니다. \n", name);
			printf("첫번째 과목 성적: %d \n", std[i].A);
			printf("두번째 과목 성적: %d \n", std[i].B);
			printf("세번째 과목 성적: %d \n", std[i].C);
			printf("네번째 과목 성적: %d \n", std[i].D);
			printf("다섯번째 과목 성적: %d \n", std[i].E);
			printf("여섯번째 과목 성적: %d \n", std[i].F);
			printf("평균 점수 : %.1f", std[i].average);
			ok = 1;
			break;
		}
	}
	if (ok != 1) {
		i = 0;
		printf("과목명 다시 입력해 주세요 : ");
		scanf("%s", name);
		goto here;
	}
	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_3() //성적순으로 출력
{
	int i, j;

	for (i = 0; i < len; i++)
	{
		std_dest[i] = std[i];
	}

	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (std[i].average < std[j].average)
			{
				temp = std_dest[j];
				std_dest[j] = std_dest[i];
				std_dest[i] = temp;
			}
		}
	}

	printf("전체 과목 등수 출력\n");
	for (i = 0; i < len; i++)
	{
		printf("[ %d ]등 과목:%s  A:%.lf  B:%.lf  C:%.lf  D:%.lf E:%.lf F%.lf 평균점수:%.lf\n",
			i + 1, std_dest[i].name, std_dest[i].a, std_dest[i].b, std_dest[i].c, std_dest[i].d, std_dest[i].e, std_dest[i].f, std_dest[i].average);
	}

	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_4() //4. 저장된 과목의 데이터를 수정하는 기능
{
	char name[20];
	char subject[20];
	int i, j;

	printf("성적 수정할 과목 입력:");
	scanf("%s", name);
	printf("수정할 과목(A~F 중 입력):");
	scanf("%s", subject);

	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			if (!strcmp(subject, "A"))
			{
				printf("첫번째 성적:");
				scanf("%d", &std[i].a);
			}
			if (!strcmp(subject, "B"))
			{
				printf("두번째 성적:");
				scanf("%d", &std[i].b);
			}
			if (!strcmp(subject, "C"))
			{
				printf("세번째 성적:");
				scanf("%d", &std[i].c);
			}
			if (!strcmp(subject, "D"))
			{
				printf("네번째 성적:");
				scanf("%d", &std[i].d);
			}
			if (!strcmp(subject, "E"))
			{
				printf("다섯번째 성적:");
				scanf("%d", &std[i].e);
			}
			if (!strcmp(subject, "e"))
			{
				printf("여섯번째 성적:");
				scanf("%d", &std[i].f);
			}
			std[i].average = (double)(std[i].a + std[i].b + std[i].c + std[i].d + std[i].e + std[i].f) / 6; //평균 변경
		}
	}
	printf("변경이 완료되었습니다.\n");
	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_5() //과목 삭제하는 기능
{
	char name[20];
	int i, j;

	printf("삭제할 과목 이름 입력:");
	scanf("%s", name);

	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			for (j = i + 1; j < len; j++) {
				std[j] = std[j + 1];
			}
		}
	}
	len--;
	printf("삭제가 완료되었습니다.\n");
	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void processMenu(char choice)
{
	switch (choice)
	{
	case '1': //정보받기
		menu_1();
		break;

	case '2': //점수출력
		menu_2();
		break;

	case '3': //성적순출력
		menu_3();
		break;

	case '4': //수정
		menu_4();
		break;

	case '5': //삭제
		menu_5();
		break;


	}
}