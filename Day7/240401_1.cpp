#include <iostream>
#include <string>
using namespace std;

class Wordcnt
{
    string word;
    int cnt;

public:
    Wordcnt(string word, int cnt)
    {
        this->word = word;
        this->cnt = cnt;
    }
    void increase()
    {
        cnt++;
    }
    int equalString(string word)
    {
        return this->word == word;
    }
    void show()
    {
        cout << word << " : " << cnt << endl;
    }
};

int findIndex(Wordcnt *w[100], int cnt, string word)
{
    for (int i = 0; i < cnt; i++)
    {
        if (w[i]->equalString(word))
            return i;
    }
    return -1;
}

int main()
{
    Wordcnt *w[100];
    int cnt = 0;
    string s = "I,love-c++ I'Hate[Python Hell/C++ C++"; // 알고리즘 상에는 문제가없지만 전처리 과정이 무조건 필요함
    // 대문자나 소문자로 통일시켜야함.
    for (int j = 0; j < s.length(); j++)
    {
        if (!isalpha(s[j]) && s[j] != '+')
        {               // 알파벳이나 '+'가 아닌 문자일 경우
            s[j] = ' '; // 공백으로 대체
        }
        else
        {
            s[j] = toupper(s[j]); // 대문자로 변환
        }
    }

    int startIndex = 0;

    while (true)
    {
        int findex = s.find(' ', startIndex);
        if (findex == -1)
        {
            string part = s.substr(startIndex);
            int idx = findIndex(w, cnt, part);
            if (idx < 0)
                w[cnt++] = new Wordcnt(part, 1);
            else
                w[idx]->increase();
            break;
        }
        int count = findex - startIndex;
        string part = s.substr(startIndex, count);
        int idx = findIndex(w, cnt, part); // w배열에 part가 어디에 있는지?
        if (idx < 0)
            w[cnt++] = new Wordcnt(part, 1); // idx가 음수이므로 part는 처음 등장
        else
            w[idx]->increase(); // part는 idx에 존재하고 idx위치에 있는 단어를 증가

        startIndex = findex + 1; // 검색을 시작할 인덱스 전진시킴
    }
    for (int i = 0; i < cnt; i++)
    {
        w[i]->show();
    }
}