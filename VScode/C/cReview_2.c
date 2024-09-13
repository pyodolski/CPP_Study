#include <stdio.h>
#include <math.h>

// struct point
// {
//     int xpos;
//     int ypos;
// };

// int main(void)
// {
//     struct point pos1={1,2};
//     struct point pos2={100,200};
//     struct point pos3={1000,2000};
//     struct point * pptr=&pos1;

//     (*pptr).xpos += 4;
//     (*pptr).ypos += 5;
//     printf("[%d,%d] \n", pptr->xpos, pptr->ypos);
//     pptr = &pos2;
//     pptr->xpos += 1;
//     pptr->ypos += 2;
//     printf("[%d,%d] \n", (*pptr).xpos, (*pptr).ypos);

//     pptr = &pos3;
//     pptr->xpos += 1;
//     pptr->ypos += 2;
//     printf("[%d,%d] \n", (*pptr).xpos, (*pptr).ypos);
    // double distance;
    // printf("point1 pos: ", stdout);
    // scanf("%d %d", &pos1.xpos, &pos1.ypos);

    // printf("point2 pos: ", stdout);
    // scanf("%d %d", &pos2.xpos, &pos2.ypos);

    // distance = sqrt((double)((pos1.xpos-pos2.xpos) * (pos1.xpos-pos2.xpos)+(pos1.ypos-pos2.ypos) * (pos1.ypos-pos2.ypos)));
    // printf("두 점의 거리는 %g 입니다. \n", distance);
    // return 0;
    
//}

// struct  person
// {
//     char name[20];
//     char phoneNum[20];
//     int age;
// };

// int main(void)
// {
//     struct person man1, man2;
//     strcpy(man1.name, "안성준");
//     strcpy(man1.phoneNum, "010-8011-0366");
//     man1.age=23;

//     printf("이름입력: "); scanf("%s", man2.name);
//     printf("번호입력: "); scanf("%s", man2.phoneNum);
//     printf("나이입력: "); scanf("%s", man2.age);
    
    
// }

#include <stdio.h>

typedef struct student
{
    char name[20];
    char code[10];
    int kor, eng, math;
} STU;

char Grade(int kor, int eng, int math)
{
    double average = (kor + eng + math) / 3.0; // 평균 계산 시 정수 나눗셈 방지
    char grade;

    if (average >= 90)
    {
        grade = 'A';
    }
    else if (average >= 80)
    {
        grade = 'B';
    }
    else if (average >= 70)
    {
        grade = 'C';
    }
    else
    {
        grade = 'F';
    }
    return grade;
}

int main()
{
    STU s[100]; // 백명의 학생 정보를 저장할 수 있다.
    int cnt = 0; // 입력 된 학생 수 카운트
    int sel = 0; // sel 변수 초기화
    
    while (sel != 3) // 종료가 입력될 때까지 실행
    {
        printf("1.입력, 2.출력, 3.종료 : ");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            printf("이름 입력 : ");
            scanf("%s", s[cnt].name);
            
            printf("학번 입력 : ");
            scanf("%s", s[cnt].code);

            printf("국어 점수 입력 : ");
            scanf("%d", &s[cnt].kor);

            printf("영어 점수 입력 : ");
            scanf("%d", &s[cnt].eng);

            printf("수학 점수 입력 : ");
            scanf("%d", &s[cnt].math);
            printf("등록되었습니다.\n");
            cnt++;
            break;
        case 2:
            for (int i = 0; i < cnt; i++)
            {
                printf("이름 : %s, 학번 : %s, 국어 : %d, 영어 : %d, 수학 : %d, 등급 : %c\n", s[i].name, s[i].code, s[i].kor, s[i].eng, s[i].math, Grade(s[i].kor, s[i].eng, s[i].math));
            }
            break;
        case 3:
            break;
        default:
            break;
        }
    }
    return 0;
}
