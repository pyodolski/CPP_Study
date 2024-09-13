#include "Account.h"
#include <iostream>

Account::Account(string an, string on, int bal, string pw) // 생성자 오버로딩
{
    accountNum = an;
    ownerName = on;
    balance = bal;
    passWord = pw;
}

void Account::deposit(int amount)
{
    if (amount <= 0)
        return;
    balance += amount;

    // cout << amount << "가 입금되었습니다.";
    // cout << "현재 통잔잔고 : " << balance << endl;
}

int Account::withdraw(int amount, string password)
{
    if (amount <= 0)
        return 0;
    if (passWord != password)
        return 0;
    if (balance < amount)
        return 0;
    balance -= amount;
    return 1;
}

int Account::transfer(int amount, string psssword, Account *account)
{
    if (!withdraw(amount, psssword)) // == 0
        return 0;
    account->deposit(amount);
    return 1;
}

void Account::show(string pw)
{
    if (passWord == pw)
    {
        cout << "owner: " << ownerName << endl;
        cout << "balance: " << balance << endl;
    }
}

int Account::equalAccount(string accountNum)
{
    return this->accountNum == accountNum;
}

string Account::getOwner()
{
    return ownerName;
}
string Account::getpassWord()
{
    return passWord;
}
