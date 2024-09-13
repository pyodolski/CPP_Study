#include <iostream>
#include <stack>
using namespace std;

int evaluation(string postfix)
{
    stack<int> s;
    for (int i = 0; i < postfix.size(); i++)
    {
        char tok postfix[i];
        if ('0' <= tok && tok <= '9')

            if (isdigit(tok))
            {
                s.push(tok - '0');
            }
            else
            {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                switch (tok)
                {
                case '+':
                    s.push(op2 + op1);
                    break;
                case '-':
                    s.push(op2 - op1);
                    break;
                case '*':
                    s.push(op2 * op1);
                    break;
                case '/':
                    s.push(op2 / op1);
                    break;
                }
            }
    }
    int result = s.top();
    s.pop();
    return result;
}
int main
{
}