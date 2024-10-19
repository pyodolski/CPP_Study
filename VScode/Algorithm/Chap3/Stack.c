#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // 스택의 최대 크기 정의

typedef struct
{
    int key;
    // 다른 필드 추가 가능
} element;

// 스택 배열과 전역 변수 top 정의
element stack[MAX_STACK_SIZE];
int top = -1; // 스택의 최상단을 가리키는 변수

// 스택이 비었는지 확인하는 함수
int is_empty()
{
    return (top == -1);
}

// 스택이 가득 찼는지 확인하는 함수
int is_full()
{
    return (top == MAX_STACK_SIZE - 1);
}

// 스택에 요소를 추가하는 함수
void push(element item)
{
    if (is_full())
    {
        printf("스택이 가득 찼습니다. 더 이상 삽입할 수 없습니다.\n");
        exit(1); // 프로그램 종료
    }
    stack[++top] = item; // top을 증가시키고 해당 위치에 요소 삽입
}

// 스택에서 요소를 제거하고 반환하는 함수
element pop()
{
    if (is_empty())
    {
        printf("스택이 비어 있습니다. 제거할 요소가 없습니다.\n");
        exit(1); // 프로그램 종료
    }
    return stack[top--]; // 요소를 반환하고 top을 감소시킴
}

// 스택의 최상단 요소를 반환하는 함수
element peek()
{
    if (is_empty())
    {
        printf("스택이 비어 있습니다. 조회할 요소가 없습니다.\n");
        exit(1); // 프로그램 종료
    }
    return stack[top]; // top 위치의 요소를 반환
}

// 테스트를 위한 main 함수
int main()
{
    element item1 = {10}; // 첫 번째 요소 생성
    element item2 = {20}; // 두 번째 요소 생성

    push(item1); // 첫 번째 요소 삽입
    push(item2); // 두 번째 요소 삽입

    printf("스택 최상단 요소: %d\n", peek().key); // 최상단 요소 출력

    element popped_item = pop();                  // 요소 제거
    printf("제거된 요소: %d\n", popped_item.key); // 제거된 요소 출력

    return 0;
}
