#include "Account.h"
#include "Account.cpp"
#include <iostream>
using namespace std;

int findIndex(Account *acc, int cnt, string no)
{
    for (int i = 0; i < cnt; i++)
    {
        if (acc[i].equalAccount(no))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Account acc[] = {
        Account("1234-1234", "jang", 10000, "1234"),
        Account("4321-4321", "pyo", 10000, "4321"),
        Account("1111-1111", "kavin", 10000, "1111")};
    int cnt = 3;

    while (1)
    {
        string no;
        cout << "계좌번호 입력 : ";
        cin >> no;
        int userIDX = findIndex(acc, cnt, no);
        if (userIDX < 0)
        {
            cout << "잘못된 계좌번호" << endl;
        }
        else
        {
            int amount;
            int sel = 0;
            string pw;
            int uidx;
            cout << acc[userIDX].getOwner() << "님";
            bool open = true;
            while (open)
            {
                cout << "1.입금 2.출금 3.송금, 4.조회, 5.종료";
                cin >> sel;
                switch (sel)
                {
                case 1: // 입금
                    cout << "입금액 : ";
                    cin >> amount;
                    acc[userIDX].deposit(amount);
                    cout << "입금되었습니다" << endl;
                    break;
                case 2: // 출금
                    cout << "비밀번호 : ";
                    cin >> pw;
                    if (acc[userIDX].getpassWord() == pw)
                    {
                        cout << "출금액 : ";
                        cin >> amount;
                        acc[userIDX].withdraw(amount, pw);
                        cout << "출금되었습니다." << endl;
                        break;
                    }
                    else
                    {
                        cout << "잘못된 비밀번호 입니다." << endl;
                        break;
                    }
                case 3: // 송금
                    cout << "송금할 계좌를 선택하세요(1 : jang, 2: pyo, 3: kavin) : ";
                    cin >> uidx;

                    if (userIDX == uidx - 1)
                    {
                        cout << "본인에게 송금할 수 없습니다" << endl;
                        break;
                    }
                    else
                    {
                        cout << "비밀번호 : ";
                        cin >> pw;
                        if (acc[userIDX].getpassWord() == pw)
                        {
                            cout << "송금할 금액 : ";
                            cin >> amount;
                            acc[userIDX].transfer(amount, pw, &acc[uidx - 1]);
                            break;
                        }
                        else
                        {
                            cout << "잘못된 비밀번호 입니다" << endl;
                            break;
                        }
                    }
                case 4: // 조회
                    cout << "비밀번호 : ";
                    cin >> pw;
                    if (acc[userIDX].getpassWord() == pw)
                    {
                        acc[userIDX].show(pw);
                        break;
                    }
                    else
                    {
                        cout << "잘못된 비밀번호입니다." << endl;
                        break;
                    }
                case 5: // 종료
                    cout << "안녕히 가세요" << endl;
                    open = false;
                    break;
                }
            }
        }
    }
}
