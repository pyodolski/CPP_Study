#include <stdio.h>
#define MAX_SIZE 15 // Magic square의 최대 크기

int main(void)
{                                   // 순차적으로 magic square 작성
    int square[MAX_SIZE][MAX_SIZE]; // 2차원 배열 선언
    int i, j, row, column, size;
    int count;

    // Magic square의 크기를 입력 받음
    printf("Enter the size of the square: ");
    scanf("%d", &size);

    // 유효성 검사: 크기는 홀수여야 하고 1 이상 MAX_SIZE 이하여야 함
    if (size < 1 || size > MAX_SIZE)
    {
        printf("Error! Size is out of range\n");
        return 1;
    }
    if (size % 2 == 0)
    {
        printf("Error! Size is even\n");
        return 1;
    }

    // 배열 초기화 (모든 원소를 0으로 설정)
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            square[i][j] = 0;
        }
    }

    // 첫 번째 숫자 1을 첫 행의 중간 열에 배치
    i = 0;
    j = size / 2;
    square[i][j] = 1;

    // 나머지 숫자들을 순서대로 배치
    for (count = 2; count <= size * size; count++)
    {
        // 현재 위치에서 대각선 위 (왼쪽 위)로 이동
        row = (i - 1 < 0) ? (size - 1) : (i - 1);    // 위쪽 행 계산
        column = (j - 1 < 0) ? (size - 1) : (j - 1); // 왼쪽 열 계산

        if (square[row][column] != 0)
        { // 이미 숫자가 있으면 아래로 이동
            i = (i + 1) % size;
        }
        else
        { // 비어 있으면 대각선 위로 이동
            i = row;
            j = column;
        }

        // 현재 위치에 숫자 배치
        square[i][j] = count;
    }

    // 생성된 magic square 출력
    printf("Magic Square of size %d:\n\n", size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%5d", square[i][j]);
        }
        printf("\n"); // 한 행 출력 후 줄 바꿈
    }
    printf("\n");

    return 0;
}
