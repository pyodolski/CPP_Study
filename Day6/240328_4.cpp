#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "여러 줄의 문자열을 입력 하세요" << endl;
    getline(cin, s, '\n'); // string 입력받고 s에 저장
    int s_idx;

    s_idx = 0; // start index = 0;
    while (true)
    {
        int f_idx = s.find(" ", s_idx); // 공백
        if (f_idx == -1)
        {
            string part = s.substr(s_idx);
            if (part == "")
                break;
            cout << part << endl;
            break;
        }
        int len = f_idx - s_idx;
        string part = s.substr(s_idx, len); // 공백 전까지의 문자를 따로 저장
        cout << part << endl;
        s_idx = f_idx + 1;
        Wordcnt(part);
    }
}
class Wordcnt
{
    Wordcnt *w[10];
    string word;
    int cnt = 0;

public:
    Wordcnt(string word)
    {
        for(int = 0; i < 10; i++) {
            if (w[i] == word)
            
        }
        this->word = word;
    //    this->cnt = cnt;
        w[cnt] = word;
        cnt++;
    }
    void increase() { cnt++; }
    int equalString(string word) {return this -> word == word;}
    void show() { cout << word << ":" << cnt << endl;}
};

/*
idx = findIndex(w, cnt, str);
if (idx < 0)

Wordcnt *w[100]
int cnt = 3;
w[0] = new Wordcnt("C++", 1);
cnt++;
if(첫등장)]{
    w[cnt++] = new Word(str, 1);
else
    idx = str의 위치
    w[idx] -> intcrease();
}


1. 단어들을 순서대로 잘라서 출력하는 반복문을 작성
2. 배열속에 str이 있는지 찾는 findindex(Wordcnt * w[100], int cnt);를 작성한다
3. 조건문을 작성한다
4. 배열의 내용을 출력한다.
*/