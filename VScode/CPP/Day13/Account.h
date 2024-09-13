#ifndef Account_h
#define Account_h

#include <string>
#include <iostream>
using namespace std;

class Account // 생성자 정의
{
    string accountNum; // 계좌번호
    string ownerName;  // 예금주
    int balance;       // 잔액
    string passWord;   // 비밀면호

public:
    Account(string a, string o, int b, string p);
    void deposit(int amount);
    int withdraw(int amount, string password);
    int transfer(int amount, string psssword, Account *account);
    void show(string password);
    int equalAccount(string accountNum);
    string getOwner();
    string getpassWord();
};

#endif /* Account_h */