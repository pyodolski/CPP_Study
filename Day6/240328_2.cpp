#include <iostream>
using namespace std;
#include <string>

int main()
{
    string s;
    cout << "덧셈 문자열을 입력하세요" << endl;
    getline(cin, s, '\n');
    int sum = 0;
    int s_idx = 0;
    while (true)
    {
        int f_idx = s.find('+', s_idx);
        if (f_idx == -1) // 해당 구분자가 없는 경우
        {
            string part = s.substr(s_idx);
            if (part == "")
                break;
            cout << part << endl;
            sum += stoi(part);
            break;
        }
        int cnt = f_idx - s_idx;
        string part = s.substr(s_idx, cnt);
        cout << part << endl;
        sum += stoi(part);
        s_idx = f_idx + 1;
    }
    cout << "숫자들의 합은" << sum;
}