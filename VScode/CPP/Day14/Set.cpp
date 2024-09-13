#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> lotto;
    int lotoo[6];   // 로또 번호를 저장할 배열
    srand(time(0)); // 시간에 따라서 계속해서 바뀜
    for (; lotto.size() != 6;)
    {
        lotoo.insert(rand() % 45 + 1);
    }
    for (it = lotto.begin(); it != lotoo.end(); i++)
    {
        cout << *it << endl;
    }
    return 0;
}