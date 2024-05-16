#include <iostream>
#include "Account.h"
#include <map>
using namespace std;

int main()
{

    map<string, Account *> acc;
    acc["1234-1234"] = new Account("1234-1234", "jang", 10000, "1234");
    acc["4321-4321"] = new Account("4321-4321", "kim", 20000, "4321");
    acc["1111-1111"] = new Account("1111-1111", "hwang", 30000, "1111");

    while (1)
    {
        string no;
        cout << "계좌번호입력 : ";
        cin >> no;
        // int userIDX = findIndex(acc, cnt, no);

        if (acc.find(no) == acc.end())
        {
            cout << "잘못된 계좌번호" << endl;
        }
        else
        {
            int sel = 0, amnt;
            string pw;
            cout << acc[no]->getOwner() << "님 환영합니다" << endl;
            while (sel != 5)
            {
                cout << "1.입금  2.출금  3.송금  4.조회  5.종료  : ";
                cin >> sel;
                switch (sel)
                {
                case 1:
                    cout << "입금액 : ";
                    cin >> amnt;
                    acc[no]->deposit(amnt);
                    cout << "입금되었습니다" << endl;
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    cout << "비밀번호 : ";
                    cin >> pw;
                    acc[no]->show(pw);
                    break;
                case 5:
                    cout << "안녕히 가세요" << endl;
                    break;
                default:;
                }
            }
        }
    }
}
