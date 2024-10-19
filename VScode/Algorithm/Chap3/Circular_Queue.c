#include <stdio.h>
#include <stdlib.h>
// rear = (rear + 1) % MAX_Q_SIZE;
#define MAX_Q_SIZE 100  // 큐의 최대 크기 정의

typedef struct {
    int key;
    // 다른 필드 추가 가능
} element;

// 큐 배열과 front, rear 인덱스 정의
element queue[MAX_Q_SIZE];
int front = 0, rear = 0;  // 초기값 설정

// 큐가 비었는지 확인하는 함수
int is_empty() {
    return (front == rear);
}

// 큐가 가득 찼는지 확인하는 함수
int is_full() {
    return ((rear + 1) % MAX_Q_SIZE == front);
}

// 큐가 가득 찼을 때 처리하는 함수
void queue_full() {
    printf("큐가 가득 찼습니다. 더 이상 삽입할 수 없습니다.\n");
    exit(1);  // 프로그램 종료
}

// 큐가 비었을 때 처리하는 함수
element queue_empty() {
    printf("큐가 비어 있습니다. 제거할 요소가 없습니다.\n");
    exit(1);  // 프로그램 종료
}

// 원형 큐에 요소를 추가하는 함수
void addq(element item) {
    if (is_full()) {
        queue_full();  // 큐가 가득 찼을 경우 처리
        return;
    }
    rear = (rear + 1) % MAX_Q_SIZE;  // rear 인덱스 조정
    queue[rear] = item;  // 요소 삽입
}

// 원형 큐에서 요소를 제거하고 반환하는 함수
element deleteq() {
    if (is_empty()) {
        return queue_empty();  // 큐가 비어 있을 경우 처리
    }
    front = (front + 1) % MAX_Q_SIZE;  // front 인덱스 조정
    return queue[front];  // 요소 반환
}

// 테스트를 위한 main 함수
int main() {
    element item1 = {10};  // 첫 번째 요소 생성
    element item2 = {20};  // 두 번째 요소 생성
    element item3 = {30};  // 세 번째 요소 생성

    addq(item1);  // 첫 번째 요소 삽입
    addq(item2);  // 두 번째 요소 삽입
    addq(item3);  // 세 번째 요소 삽입

    printf("제거된 요소: %d\n", deleteq().key);  // 첫 번째 요소 제거 및 출력
    printf("제거된 요소: %d\n", deleteq().key);  // 두 번째 요소 제거 및 출력

    return 0;
}
