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

int findIndex(Wordcnt *w[100], int cnt, string word) // Wordcnt& w[100]으로 변경가능 일반 변수로써 사용이 가능해진다.
{
    for (int i = 0; i < cnt; i++)
    {
        if (w[i]->equalString(word))
            return i;
    }
    return -1;
}

#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    map<string, int> wordCount;
    string s = "c++-C++,python?Pthyon#Java!pyTYON JAva JAva";
    
    
    for (int j = 0; j < s.length(); j++)
    {
        if (!isalpha(s[j]) && s[j] != '+')
        {
            s[j] = ' ';
        }
        else
        {
            s[j] = toupper(s[j]);
        }
    }

    int startIndex = 0;
    while (true)
    {
        int findex = s.find(' ', startIndex);
        if (findex == -1)
        {
            string part = s.substr(startIndex);
            if (!part.empty())
            {
                wordCount[part]++;
            }
            break;
        }
        
        int count = findex - startIndex;
        string part = s.substr(startIndex, count);
        if (!part.empty())
        {
            wordCount[part]++;
        }
        
        startIndex = findex + 1; 
    }

    for (const auto& pair : wordCount)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
}
