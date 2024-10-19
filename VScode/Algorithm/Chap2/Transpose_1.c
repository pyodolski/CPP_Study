#include <stdio.h>

#define ROWS 3 // 행의 수
#define COLS 3 // 열의 수

// 행렬을 출력하는 함수
void printMatrix(int matrix[ROWS][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 전치 행렬을 계산하는 함수
void transpose(int a[ROWS][COLS], int b[COLS][ROWS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            b[j][i] = a[i][j]; // 행과 열의 위치를 바꿈
        }
    }
}

int main()
{
    // 테스트용 행렬 정의
    int a[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // 전치 행렬을 저장할 배열
    int b[COLS][ROWS];

    printf("원본 행렬:\n");
    printMatrix(a, ROWS, COLS);

    // 전치 연산 수행
    transpose(a, b);

    printf("\n전치 행렬:\n");
    printMatrix(b, COLS, ROWS);

    return 0;
}
// O(rows * columns)
