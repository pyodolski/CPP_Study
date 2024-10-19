#include <stdio.h>
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y) = (temp))

// 순열 생성 함수
void perm(char *list, int i, int n) {
    int j, temp;

    if (i == n) {  // 기저 조건: 하나의 순열 완성
        for (j = 0; j <= n; j++) {
            printf("%c", list[j]);  // 순열 출력
        }
        printf("\n");
    } else {  // 재귀적으로 순열 생성
        for (j = i; j <= n; j++) {
            SWAP(list[i], list[j], temp);  // 현재 요소와 다른 요소 교환
            perm(list, i + 1, n);  // 다음 위치에서 순열 생성
            SWAP(list[i], list[j], temp);  // 원래 상태로 되돌리기 (백트래킹)
        }
    }
}

// main 함수에서 예제 실행
int main() {
    char list[] = {'a', 'b', 'c', 'd'};
    int n = sizeof(list) / sizeof(list[0]) - 1;  // 배열 크기 계산

    // 순열 생성 시작
    perm(list, 0, n);

    return 0;
}

// 전체 시간 복잡도: O(n × n!)
