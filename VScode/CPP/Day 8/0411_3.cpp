#include <iostream>
using namespace std;

// 원형 선언
void f(char c = ' ', int line = 1);

// 함수 구현
void f(char c, int line)
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << c;
        cout << endl;
    }
}

int main()
{
    f();       // 한줄에 빈칸을 10개 출력한다.
    f('%');    // 한 줄에 '%'를 10개 출력한다.
    f('@', 5); // 5 줄에 '@' 문자를 10개 출력한다.
}
// 메모리
// 1. 데이타 : 전역, static -> 프로그래실행과 동시에 메모리에 할당, 프로그램 종료시 해제
// 2. 스택 : ㄴ