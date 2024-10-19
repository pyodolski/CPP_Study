#include <stdio.h>                                      // 표준 입출력 라이브러리
#include <stdlib.h>                                     // rand(), exit() 함수를 위한 라이브러리
#define MAX_SIZE 101                                    // 배열의 최대 크기 정의
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) // 두 변수 교환 매크로

// 선택 정렬 함수 선언
void sort(int list[], int n);

int main(void)
{
    int i, n, list[MAX_SIZE]; // 정수형 변수와 배열 선언

    // 사용자로부터 입력받기
    printf("Enter the number of numbers to generate: ");
    scanf("%d", &n);

    // 입력값이 올바른지 확인
    if (n < 1 || n > MAX_SIZE)
    {
        fprintf(stderr, "Improper value of n\n"); // 오류 메시지 출력
        exit(1);                                  // 프로그램 종료
    }

    // n개의 랜덤 정수 생성 및 출력
    printf("Generated array:\n");
    for (i = 0; i < n; i++)
    {
        list[i] = rand() % 1000; // 0~999 사이의 정수 생성
        printf("%d ", list[i]);  // 생성된 정수 출력
    }
    printf("\n");

    // 배열 정렬
    sort(list, n);

    // 정렬된 배열 출력
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0; // 정상 종료
}

// 선택 정렬 함수 구현
void sort(int list[], int n)
{
    int i, j, min, temp; // 변수 선언

    // 선택 정렬 알고리즘
    for (i = 0; i < n - 1; i++)
    {
        min = i; // 현재 구간에서 가장 작은 값의 인덱스 저장
        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[min])
            { // 더 작은 값 발견 시 갱신
                min = j;
            }
        }
        // 현재 값과 최소값을 교환
        SWAP(list[i], list[min], temp);
    }
}

//  시간 복잡도는 O(n²)입니다. //
