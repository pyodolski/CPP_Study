#include <stdio.h>

#define MAX_TERMS 100 // 최대 비영 요소(0이 아닌 값) 수

// 희소 행렬의 항목을 나타내는 구조체 정의
typedef struct
{
    int row;
    int col;
    int value;
} term;

// 희소 행렬의 전치 함수
void transpose(term a[], term b[])
{
    int count = a[0].value; // 비영 요소의 수
    int currentb = 1;       // 새로운 원소가 b에 저장될 위치

    // 전치된 행렬의 첫 번째 요소 (차원 정보)
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = count;

    // 만약 행렬이 비어있지 않다면(비영 요소가 있을 때)
    if (count > 0)
    {
        // 열 순서로 전치 연산을 수행
        for (int i = 0; i < a[0].col; i++)
        { // i: 열 인덱스
            for (int j = 1; j <= count; j++)
            { // j: a 배열의 비영 요소 인덱스
                // 현재 열에 해당하는 요소를 찾기
                if (a[j].col == i)
                {
                    // 해당 요소를 b에 추가 (전치)
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++; // 다음 위치로 이동
                }
            }
        }
    }
}

// 희소 행렬 출력 함수
void printSparseMatrix(term a[])
{
    printf("Row  Col  Value\n");
    for (int i = 0; i <= a[0].value; i++)
    {
        printf("%d    %d    %d\n", a[i].row, a[i].col, a[i].value);
    }
}

// 테스트 코드
int main()
{
    // 입력 희소 행렬 정의 (3x3 행렬에서 비영 요소 4개)
    term a[MAX_TERMS] = {
        {3, 3, 4}, // 행의 수, 열의 수, 비영 요소의 수
        {0, 2, 5}, // (0, 2)에 값 5
        {1, 0, 3}, // (1, 0)에 값 3
        {2, 1, 6}, // (2, 1)에 값 6
        {2, 2, 8}  // (2, 2)에 값 8
    };

    // 전치된 희소 행렬을 저장할 배열
    term b[MAX_TERMS];

    printf("원본 희소 행렬:\n");
    printSparseMatrix(a);

    // 전치 연산 수행
    transpose(a, b);

    printf("\n전치된 희소 행렬:\n");
    printSparseMatrix(b);

    return 0;
}
