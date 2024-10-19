#include <stdio.h>
// #define compare(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1) // 

// 이진 탐색 함수 선언
int binsearch(int list[], int key, int left, int right);

// 비교 함수 선언
int compare(int x, int y);

int main() {
    int list[] = {1, 3, 5, 7, 9, 11}; // 정렬된 배열 예시
    int n = sizeof(list) / sizeof(list[0]); // 배열 크기 계산
    int key = 7; // 찾고자 하는 값
    int result = binsearch(list, key, 0, n - 1); // 이진 탐색 수행

    if (result != -1)
        printf("Key %d found at index %d\n", key, result);
    else
        printf("Key %d not found\n", key);

    return 0;
}

// 이진 탐색 함수 구현
int binsearch(int list[], int key, int left, int right) {
    int middle;

    // left <= right일 동안 반복
    while (left <= right) {
        middle = (left + right) / 2; // 중간 인덱스 계산

        int cmp_result = compare(key, list[middle]); // 키와 중간값 비교

        if (cmp_result == 0) // key == list[middle]
            return middle;   // 값이 일치하면 위치 반환
        else if (cmp_result < 0) // key < list[middle]
            right = middle - 1;  // 왼쪽 절반 탐색
        else // key > list[middle]
            left = middle + 1;   // 오른쪽 절반 탐색
    }
    return -1; // 값을 찾지 못한 경우 -1 반환
}

// 비교 함수 구현
int compare(int x, int y) {
    if (x < y) return -1;
    else if (x == y) return 0;
    else return 1;
}

// 시간 복잡도는 O(log n)입니다.
