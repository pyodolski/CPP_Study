#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100 // 최대 비영 요소 수

// 희소 행렬의 항목을 나타내는 구조체
typedef struct
{
    int row;
    int col;
    int value;
} term;

// fast_transpose 함수 선언 (이전 코드 참조)
void fast_transpose(term b[], term new_b[]);

// storesum 함수: 계산된 값이 0이 아닐 때 d 배열에 저장
void storesum(term d[], int *totald, int row, int column, int *sum)
{
    if (*sum != 0)
    {
        if (*totald < MAX_TERMS)
        {
            d[++(*totald)].row = row;
            d[*totald].col = column;
            d[*totald].value = *sum;
            *sum = 0;
        }
        else
        {
            fprintf(stderr, "Number of terms in product exceeds %d\n", MAX_TERMS);
            exit(1);
        }
    }
}

// 행렬 곱셈 함수
void mmult(term a[], term b[], term d[])
{
    int i, j, column, totald = 0;
    int totala = a[0].value, totalb = b[0].value;
    int row_begin = 1, row = a[1].row, sum = 0;
    term new_b[MAX_TERMS];

    // 입력 행렬의 열의 수와 행렬 B의 행의 수가 일치하는지 확인
    if (a[0].col != b[0].row)
    {
        fprintf(stderr, "Incompatible matrices\n");
        exit(1);
    }

    // 행렬 B를 전치하여 new_b에 저장
    fast_transpose(b, new_b);

    // 경계 조건 설정
    a[totala + 1].row = a[0].row;
    new_b[totalb + 1].row = b[0].col;

    // 행렬 A의 모든 행을 순회
    for (i = 1; i <= totala;)
    {
        column = new_b[1].row; // B의 현재 열 선택

        // 행렬 A의 현재 행과 B의 현재 열에 대해 곱셈 수행
        for (j = 1; j <= totalb + 1;)
        {
            if (a[i].row != row)
            {                                            // 행 A의 경계를 벗어난 경우
                storesum(d, &totald, row, column, &sum); // 누적된 합 저장
                i = row_begin;                           // A는 처음 위치로
                for (; new_b[j].row == column; j++)
                    ; // 다음 열로 이동
                column = new_b[j].row;
            }
            else if (new_b[j].row != column)
            {                                            // B의 열을 벗어난 경우
                storesum(d, &totald, row, column, &sum); // 누적된 합 저장
                i = row_begin;                           // A는 처음 위치로
                column = new_b[j].row;                   // B의 다음 열 선택
            }
            else
            {
                // A와 B의 열이 동일한 경우 값 곱셈 수행
                switch (COMPARE(a[i].col, new_b[j].col))
                {
                case -1: // A의 열 인덱스가 더 작은 경우
                    i++;
                    break;
                case 0: // 열 인덱스가 같은 경우 곱셈 수행
                    sum += (a[i++].value * new_b[j++].value);
                    break;
                case 1: // B의 열 인덱스가 더 작은 경우
                    j++;
                    break;
                }
            }
        }

        // 행 A의 모든 원소 처리 후 다음 행으로 이동
        for (; a[i].row == row; i++)
            ;
        row_begin = i;
        row = a[i].row;
    }

    // 행렬 D의 정보 저장 (결과 행렬)
    d[0].row = a[0].row;
    d[0].col = b[0].col;
    d[0].value = totald;
}
