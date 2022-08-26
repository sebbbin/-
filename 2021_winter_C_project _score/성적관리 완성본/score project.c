#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char name[20];
	int kor, eng, math;
	double average;

}Student;

#include "func.h"

int main()
{
	char ch = NULL;

	choice_menu();

	while (ch != 'q')
	{
		scanf("%c", &ch);
		processMenu(ch);
		fflush(stdin);
	}
	printf("프로그램 종료\n");

	return 0;
}

#include "func.h"

Student std[20];
Student std_dest[20];
Student temp;
int len = 0;

void choice_menu() //메뉴
{
	printf("          성적관리 프로그램 \n\n");
	printf("---------------M E N U---------------\n\n");
	printf("1.학생 정보 입력 \n\n");
	printf("2.학생의 해당 과목 점수 출력 \n\n");
	printf("3.n번째 학생의 정보 출력 \n\n");
	printf("4.학생의 평균 출력 \n\n");
	printf("5.총 입력된 학생 수 출력 \n\n");
	printf("6.전체 학생정보 출력 \n\n");
	printf("7.전체 학생 성적순 출력 \n\n");
	printf("8.학생 데이터 수정 \n\n");
	printf("9.학생 정보 삭제 \n\n");
	printf("메뉴를 입력하세요('q' 입력시 종료): ");
}

void menu_1() //메뉴1 정보(이름, 국어, 영어, 수학)를 입력받아 평균을 구해 저장
{
	int i;

	printf("학생정보를 입력하세요.\n");

	for (i = len; i < len + 1; i++)
	{
		printf("이름: ");
		scanf("%s", std[i].name);
		do {
			printf("국어성적(0~100점 입력): ");
			scanf("%d", &std[i].kor);
			if (std[i].kor < 0 || std[i].kor > 100)
			{
				printf("입력 오류!! 성적을 재입력하세요.\n");
			}
		} while (std[i].kor < 0 || std[i].kor > 100);

		do {
			printf("영어성적(0~100점 입력): ");
			scanf("%d", &std[i].eng);
			if (std[i].eng < 0 || std[i].eng > 100)
			{
				printf("입력 오류!! 성적을 재입력하세요.\n");
			}
		} while (std[i].eng < 0 || std[i].eng > 100);

		do {
			printf("수학성적(0~100점 입력): ");
			scanf("%d", &std[i].math);
			if (std[i].math < 0 || std[i].math > 100)
			{
				printf("입력 오류!! 성적을 재입력하세요.\n");
			}
		} while (std[i].math < 0 || std[i].math > 100);

		std[i].average = (std[i].kor + std[i].eng + std[i].math) / 3;
	}
	len++;
	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_2() //2. 이름과 과목을 입력 받아 해당 학생의 해당 과목 점수를 출력
{
	char name[20];
	char subject[20];
	int i, j;

	printf("학생이름 입력: ");
	scanf("%s", name);
	printf("과목 입력(kor, eng, math): ");
	scanf("%s", subject);

	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			if (!strcmp(subject, "kor"))
			{
				printf("[ %s ]학생의 국어 과목 성적: %d \n", name, std[i].kor);
			}
			else if (!strcmp(subject, "eng"))
			{
				printf("[ %s ]학생의 영어 과목 성적: %d \n", name, std[i].eng);
			}
			else if (!strcmp(subject, "math"))
			{
				printf("[ %s ]학생의 수학 과목 성적: %d \n", name, std[i].math);
			}
		}
	}
	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_3() //3. 입력한 순서를 입력받아 결과를 출력 ( 3을 입력하면 세번 째 학생의 정보를 출력)
{
	int num;

	printf("[ n ]번째 학생 입력: ");
	scanf("%d", &num);

	printf("[ %d ]번째 학생이름:%s  국어:%d  영어:%d  수학:%d  평균:%f \n",
		num, std[num - 1].name, std[num - 1].kor, std[num - 1].eng, std[num - 1].math, std[num - 1].average);
	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_4() //4. 이름을 입력 받으면 국어, 영어, 수학, 평균을 출력
{
	char name[20];
	int i;

	printf("학생 이름 입력:");
	scanf("%s", name);

	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			printf("[ %s ]학생 -> 국어:%d  영어:%d  수학:%d  평균:%f \n", std[i].name, std[i].kor, std[i].eng, std[i].math, std[i].average);
		}
	}
	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_5() //5. 입력된 학생이 몇명인지 학생 수 출력
{
	printf("총 입력 된 학생 수: [ %d ]명\n\n", len);

	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_6() //6. 전체 학생의 전체 저장된 값을 출력
{
	int i;

	printf("전체 학생 정보 출력\n");
	for (i = 0; i < len; i++)
	{
		printf("[ %d ]번 학생 이름:%s  국어:%d  영어:%d  수학:%d  평균:%f \n",
			i + 1, std[i].name, std[i].kor, std[i].eng, std[i].math, std[i].average);
	}
}

void menu_7() //7. 전체 학생의 전체 저장된 값을 성적순으로 출력
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

	printf("전체 학생 등수 출력\n");
	for (i = 0; i < len; i++)
	{
		printf("[ %d ]등 이름:%s  국어:%d  영어:%d  수학:%d  평균:%f \n",
			i + 1, std_dest[i].name, std_dest[i].kor, std_dest[i].eng, std_dest[i].math, std_dest[i].average);
	}

	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_8() //8. 저장된 학생의 데이터를 수정하는 기능
{
	char name[20];
	char subject[20];
	int i, j;

	printf("성적 수정할 학생 이름 입력:");
	scanf("%s", name);
	printf("수정할 과목(kor, eng, math 중 입력):");
	scanf("%s", subject);

	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			if (!strcmp(subject, "kor"))
			{
				printf("국어 성적:");
				scanf("%d", &std[i].kor);
			}
			if (!strcmp(subject, "eng"))
			{
				printf("영어 성적:");
				scanf("%d", &std[i].eng);
			}
			if (!strcmp(subject, "math"))
			{
				printf("수학 성적:");
				scanf("%d", &std[i].math);
			}
			std[i].average = (double)(std[i].kor + std[i].eng + std[i].math) / 3; //평균 변경
		}
	}
	printf("변경이 완료되었습니다.\n");
	printf("\n\n");
	printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_9() //9. 선택한 학생을 삭제하는 기능
{
	char name[20];
	int i, j;

	printf("삭제할 학생 이름 입력:");
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
	case '1': //1. 정보(이름, 국어, 영어, 수학)를 입력받아 평균을 구해 저장
		menu_1();
		break;

	case '2': //2. 이름과 과목을 입력 받아 해당 학생의 해당 과목 점수를 출력		
		menu_2();
		break;

	case '3': //3. 입력한 순서를 입력받아 결과를 출력 ( 3을 입력하면 세번 째 학생의 정보를 출력)
		menu_3();
		break;

	case '4': //4. 이름을 입력 받으면 국어, 영어, 수학, 평균을 출력
		menu_4();
		break;

	case '5': //5. 입력된 학생이 몇명인지 학생 수 출력
		menu_5();
		break;

	case '6': //6. 전체 학생의 전체 저장된 값을 출력
		menu_6();
		break;

	case '7': //7. 전체 학생의 전체 저장된 값을 성적순으로 출력
		menu_7();
		break;

	case '8': //8. 저장된 학생의 데이터를 수정하는 기능
		menu_8();
		break;

	case '9': //9. 선택한 학생을 삭제하는 기능
		menu_9();
		break;

	}
}