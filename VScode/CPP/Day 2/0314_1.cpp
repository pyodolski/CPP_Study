// C++ 1일차
#include <iostream>

double area(int r) { // 함수 구현
    return 3.14*r*r; // 반지름 r의 원면적 리턴
}

int main() {
    int n=3;
    char c='#';
    std::cout << c << 5.5 << '-' << n << "hello" << true << std::endl; // endl == '\n'
    // true 참 : 1 -> int type(4byte)가 아까워서 true 사용(boolean type(1byte))
    std::cout << "n + 5 = " << n + 5 << '\n';
    std::cout << "면적은 " << area(n); // 함수 area()의 리턴 값 출력
}