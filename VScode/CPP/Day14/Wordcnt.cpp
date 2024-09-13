// 단어카운팅 프로그램

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <regex>
using namespace std;
void myupper(string *str)
{
    for (int i = 0; i < str->length(); i++)
        (*str)[i] = toupper((*str)[i]);
}
vector<string> split(string str, string delimiter)
{
    vector<string> v;
    int sidx = 0;
    while (true)
    {
        int fidx = str.find(delimiter, sidx);
        if (fidx == -1)
        {
            v.push_back(str.substr(sidx));
            break;
        }
        v.push_back(str.substr(sidx, fidx - sidx));
        sidx = fidx + delimiter.length();
    }
    return v;
}

int main()
{
    string str = "c++^C++/c++?java,javA-Python";
    myupper(&str);
    regex pattern("[!@#$%^&*()_'`=?,.<>\\-/]"); // 정규표현식
    // [\\-\\\\\[\\]\\-] -> / -, \, [, ], -, " 를 패턴으로 지정
    // [\"] -> "를 패턴으로 지정
    // [a-z] -> a부터 z까지
    // [0-9] -> 0부터 9까지
    // [a-z0-9] ->  a부터 z까지 + 0부터 9까지
    str = regex_replace(str, pattern, " "); // 정규표현식을 이용한 스트링 치환
    vector<string> words = split(str, " ");
    map<string, int> wordcnt;
    map<string, int>::iterator it;
    for (int i = 0; i < words.size(); i++)
    {
        if (wordcnt.find(words[i]) == wordcnt.end())
        {
            wordcnt[words[i]] = 1;
        }
        else
        {
            wordcnt[words[i]] += 1;
        }
    }
    for (it = wordcnt.begin(); it != wordcnt.end(); it++)
    {
        cout << it->first << ":" << it->second << endl;
    }
}