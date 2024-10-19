#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  // 스택의 최대 크기
#define MAZE_SIZE 10        // 미로의 크기 (예제용)
#define TRUE 1
#define FALSE 0

// 좌표와 방향을 나타내는 구조체
typedef struct {
    int row, col, dir;
} element;

// 스택 정의
element stack[MAX_STACK_SIZE];
int top = -1;

// 미로와 방문 여부를 저장할 배열
int maze[MAZE_SIZE][MAZE_SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int mark[MAZE_SIZE][MAZE_SIZE] = {0};  // 방문 여부 표시 배열

// 출구 위치
int EXIT_ROW = 8;
int EXIT_COL = 8;

// 8방향 이동 정의 (N, NE, E, SE, S, SW, W, NW)
typedef struct {
    int x, y;
    char *name;  // 이동 방향의 이름
} Direction;

Direction move[8] = {
    {-1, 0, "N"},   // 북쪽
    {-1, 1, "NE"},  // 북동쪽
    {0, 1, "E"},    // 동쪽
    {1, 1, "SE"},   // 남동쪽
    {1, 0, "S"},    // 남쪽
    {1, -1, "SW"},  // 남서쪽
    {0, -1, "W"},   // 서쪽
    {-1, -1, "NW"}  // 북서쪽
};

// 스택에 요소를 추가하는 함수
void push(element item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("스택이 가득 찼습니다.\n");
        exit(1);
    }
    stack[++top] = item;
}

// 스택에서 요소를 제거하는 함수
element pop() {
    if (top == -1) {
        printf("스택이 비어 있습니다.\n");
        exit(1);
    }
    return stack[top--];
}

// 미로 경로를 찾는 함수
void path(void) {
    int row, col, next_row, next_col, dir;
    int found = FALSE;
    element position;

    // 시작 위치 설정 및 스택 초기화
    mark[1][1] = 1;
    top = 0;
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 0;

    while (top > -1 && !found) {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;

        while (dir < 8 && !found) {
            next_row = row + move[dir].x;
            next_col = col + move[dir].y;

            if (next_row == EXIT_ROW && next_col == EXIT_COL) {
                found = TRUE;
                printf("출구 발견: (%d, %d) 방향: %s\n", next_row, next_col, move[dir].name);
            } else if (maze[next_row][next_col] == 0 &&
                       mark[next_row][next_col] == 0) {
                mark[next_row][next_col] = 1;
                printf("이동: (%d, %d) -> (%d, %d) 방향: %s\n",
                       row, col, next_row, next_col, move[dir].name);
                push((element){row, col, dir + 1});
                row = next_row;
                col = next_col;
                dir = 0;
            } else {
                ++dir;
            }
        }
    }

    if (found) {
        printf("경로가 발견되었습니다. 경로는 다음과 같습니다:\n");
        printf("row  col\n");
        for (int i = 0; i <= top; i++) {
            printf("%2d %5d\n", stack[i].row, stack[i].col);
        }
        printf("%2d %5d\n", row, col);
        printf("%2d %5d\n", EXIT_ROW, EXIT_COL);
    } else {
        printf("경로를 찾을 수 없습니다.\n");
    }
}

// 메인 함수
int main(void) {
    path();
    return 0;
}
