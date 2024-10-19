#include <stdio.h>
#include <stdlib.h>

// 배열 구조체 정의
typedef struct
{
    int *data;      // 1차원 배열 포인터
    int rows, cols; // 배열의 행과 열 크기 (2차원 배열)
} Array;

// 배열 생성 함수 (1차원 또는 2차원 배열 생성)
Array Create(int rows, int cols)
{
    Array A;
    A.rows = rows;
    A.cols = cols;
    A.data = (int *)malloc(rows * cols * sizeof(int)); // 메모리 동적 할당

    // 초기화: 모든 배열 원소를 0으로 설정
    for (int i = 0; i < rows * cols; i++)
    {
        A.data[i] = 0;
    }

    return A;
}

// 배열의 특정 위치(i, j)의 원소 값을 반환하는 함수 (Retrieve)
int Retrieve(Array A, int i, int j)
{
    // 인덱스가 범위 안에 있는지 확인
    if (i >= 0 && i < A.rows && j >= 0 && j < A.cols)
    {
        return A.data[i * A.cols + j]; // 2차원 배열을 1차원 메모리로 접근
    }
    else
    {
        printf("Error: Index out of range\n");
        exit(1); // 오류 발생 시 프로그램 종료
    }
}

// 배열의 특정 위치(i, j)에 값 x를 저장하는 함수 (Store)
void Store(Array *A, int i, int j, int x)
{
    // 인덱스가 범위 안에 있는지 확인
    if (i >= 0 && i < A->rows && j >= 0 && j < A->cols)
    {
        A->data[i * A->cols + j] = x; // 2차원 배열에 값 저장
    }
    else
    {
        printf("Error: Index out of range\n");
        exit(1); // 오류 발생 시 프로그램 종료
    }
}

// 배열의 모든 원소를 출력하는 함수
void PrintArray(Array A)
{
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            printf("%d ", Retrieve(A, i, j)); // 각 원소 출력
        }
        printf("\n");
    }
}

int main()
{
    // 3x3 배열 생성
    Array A = Create(3, 3);

    // 배열에 값 저장
    Store(&A, 0, 0, 1);
    Store(&A, 0, 1, 2);
    Store(&A, 0, 2, 3);
    Store(&A, 1, 0, 4);
    Store(&A, 1, 1, 5);
    Store(&A, 1, 2, 6);
    Store(&A, 2, 0, 7);
    Store(&A, 2, 1, 8);
    Store(&A, 2, 2, 9);

    // 배열 출력
    printf("Array A:\n");
    PrintArray(A);

    // 메모리 해제
    free(A.data);

    return 0;
}
