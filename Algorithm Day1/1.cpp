// *********[ 학번 : 22213489, 이름 : 표주원 ]********* //
#include <iostream>
#include <string>
#include <set> // 중복인 소수를 제외하기 위해 set(집합)을 사용하였습니다.
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false; // 1보다 작거나 같은 수는 소수가 아닙니다.
    if (num == 2)
        return true; // 2는 소수입니다.
    if (num % 2 == 0)
        return false;                       // 짝수는 소수가 아닙니다.
    for (int i = 3; i <= sqrt(num); i += 2) // 3이상의 홀수만 소수 여부를 검사합니다.
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// 재귀적으로 순열을 생성하는 함수입니다.(9월 9일 자료구조 2주차 개념)
void perm(string str, int l, int r, set<int> &primes)
{
    if (l == r)
    {
        for (int len = 1; len <= str.length(); ++len)
        {
            int num = stoi(str.substr(0, len)); // 부분 문자열을 정수로 변환하였습니다.
            if (isPrime(num))
            {
                primes.insert(num); // 소수일 경우 set에 추가하였습니다.
            }
        }
    }
    else
    {
        // 순열을 재귀적으로 생성
        for (int i = l; i <= r; i++)
        {
            swap(str[l], str[i]);        // 문자를 교체
            perm(str, l + 1, r, primes); // 재귀 호출
            swap(str[l], str[i]);        // 원래 상태로 복원
        }
    }
}

int main()
{
    string numbers;

    cout << "숫자로 구성된 문자열을 입력하세요 (1자리 이상 7자리 이하): ";
    cin >> numbers;

    // 문자열 길이를 확인합니다. (1 이상 7 이하)
    if (numbers.length() < 1 || numbers.length() > 7)
    {
        cout << "문자열 길이는 1 이상 7 이하이어야 합니다." << endl;
        return 1;
    }

    // 문자열이 숫자로만 이루어졌는지 확인합니다.
    for (size_t i = 0; i < numbers.length(); ++i)
    {
        if (!isdigit(numbers[i]))
        {
            cout << "문자열은 숫자로만 구성되어야 합니다." << endl;
            return 1;
        }
    }

    set<int> primes; // 중복된 소수를 저장하기 위한 set을 정의합니다.

    // 재귀적으로 순열 생성하고 소수 여부를 판별합니다.
    perm(numbers, 0, numbers.size() - 1, primes);

    // 소수를 출력합니다.
    if (primes.empty())
    {
        cout << "생성된 순열 중 소수가 없습니다." << endl;
    }
    else
    {
        cout << "생성된 순열에서 찾은 소수: ";
        for (int prime : primes)
        // (set<int>::iterator it = primes.begin(); it != primes.end(); ++it)이 길어서 대체 하였습니다.
        {
            cout << prime << " ";
        }
        cout << endl;
    }

    return 0;
}