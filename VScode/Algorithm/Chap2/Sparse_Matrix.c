#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100 // 최대 비영(0이 아닌) 항목 수

// 희소 행렬 항목을 저장하는 구조체
typedef struct
{
    int row;   // 행 인덱스
    int col;   // 열 인덱스
    int value; // 값
} Element;

typedef struct
{
    int rows;                // 행의 수
    int cols;                // 열의 수
    int numTerms;            // 비영 요소(0이 아닌 값)의 수
    Element data[MAX_TERMS]; // 비영 요소 배열
} SparseMatrix;

// 희소 행렬 생성 함수
SparseMatrix Create(int rows, int cols)
{
    SparseMatrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.numTerms = 0;
    return mat;
}

// 희소 행렬의 전치 함수
SparseMatrix Transpose(SparseMatrix a)
{
    SparseMatrix c = Create(a.cols, a.rows); // 전치된 행렬은 행과 열이 바뀜

    for (int i = 0; i < a.numTerms; i++)
    {
        c.data[i].row = a.data[i].col;
        c.data[i].col = a.data[i].row;
        c.data[i].value = a.data[i].value;
    }

    c.numTerms = a.numTerms;
    return c;
}

// 두 희소 행렬의 합 함수
SparseMatrix Add(SparseMatrix a, SparseMatrix b)
{
    if (a.rows != b.rows || a.cols != b.cols)
    {
        printf("Error: 행렬 크기가 다릅니다.\n");
        exit(1);
    }

    SparseMatrix c = Create(a.rows, a.cols);
    int i = 0, j = 0, k = 0;

    // 두 행렬의 데이터를 하나씩 비교하며 합산
    while (i < a.numTerms && j < b.numTerms)
    {
        if (a.data[i].row == b.data[j].row && a.data[i].col == b.data[j].col)
        {
            c.data[k].row = a.data[i].row;
            c.data[k].col = a.data[i].col;
            c.data[k].value = a.data[i].value + b.data[j].value;
            i++;
            j++;
            k++;
        }
        else if (a.data[i].row < b.data[j].row ||
                 (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col))
        {
            c.data[k++] = a.data[i++];
        }
        else
        {
            c.data[k++] = b.data[j++];
        }
    }

    // 남은 요소들을 추가
    while (i < a.numTerms)
        c.data[k++] = a.data[i++];
    while (j < b.numTerms)
        c.data[k++] = b.data[j++];

    c.numTerms = k;
    return c;
}

// 두 희소 행렬의 곱 함수
SparseMatrix Multiply(SparseMatrix a, SparseMatrix b)
{
    if (a.cols != b.rows)
    {
        printf("Error: 곱셈 불가능한 행렬 크기입니다.\n");
        exit(1);
    }

    SparseMatrix c = Create(a.rows, b.cols);

    // 단순한 행렬 곱셈 구현 (효율적인 방법은 아님)
    for (int i = 0; i < a.numTerms; i++)
    {
        for (int j = 0; j < b.numTerms; j++)
        {
            if (a.data[i].col == b.data[j].row)
            {
                int row = a.data[i].row;
                int col = b.data[j].col;
                int value = a.data[i].value * b.data[j].value;

                // 기존에 같은 위치에 값이 있으면 더함
                int found = 0;
                for (int k = 0; k < c.numTerms; k++)
                {
                    if (c.data[k].row == row && c.data[k].col == col)
                    {
                        c.data[k].value += value;
                        found = 1;
                        break;
                    }
                }

                // 새로 추가해야 하는 경우
                if (!found)
                {
                    c.data[c.numTerms].row = row;
                    c.data[c.numTerms].col = col;
                    c.data[c.numTerms].value = value;
                    c.numTerms++;
                }
            }
        }
    }

    return c;
}

// 희소 행렬 출력 함수
void PrintMatrix(SparseMatrix mat)
{
    printf("Rows: %d, Cols: %d, Terms: %d\n", mat.rows, mat.cols, mat.numTerms);
    for (int i = 0; i < mat.numTerms; i++)
    {
        printf("(%d, %d, %d)\n", mat.data[i].row, mat.data[i].col, mat.data[i].value);
    }
}

int main()
{
    SparseMatrix a = Create(3, 3);
    a.data[0] = (Element){0, 2, 3};
    a.data[1] = (Element){1, 1, 2};
    a.data[2] = (Element){2, 0, 1};
    a.numTerms = 3;

    SparseMatrix b = Create(3, 3);
    b.data[0] = (Element){0, 2, 4};
    b.data[1] = (Element){1, 1, 3};
    b.numTerms = 2;

    printf("Matrix A:\n");
    PrintMatrix(a);

    printf("\nMatrix B:\n");
    PrintMatrix(b);

    printf("\nA + B:\n");
    SparseMatrix sum = Add(a, b);
    PrintMatrix(sum);

    printf("\nA Transposed:\n");
    SparseMatrix transposed = Transpose(a);
    PrintMatrix(transposed);

    return 0;
}
