
#include <iostream>
using namespace std;

class Rectangle
{
public:
    Rectangle() {}
    int width;
    int height;
    int getArea()
    {
        return width * height;
    }
};

int main()
{
    Rectangle rect;
    rect.width = 3;
    rect.height = 5;
    cout << "사각형의 면적은 " << rect.getArea() << endl;
}

/* 먼소린지 이해안됨 질문하기
class Rectangle {
    int width;
    int height;

public:
    Rectangle() : Rectangle(1,1) {}
    Rectangle(int len) : Rectangle(len, len) {}
    Rectangle(int w, int h) (width = w, height = h)

}; 

int Rectangle :: getArea() {
        return width * height;
    }

int main() {
    Rectangle rect(3,5), rect2;
    cout << "사각형의 면적은 " <<  rect.getArea() << endl;
}
*/