#include <iostream>
#include <stack>
using namespace std;

int priority(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    string infix = "A+B*C";
    stack<char> s;
    string postfix = "";

    for(int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z'))
        {
            postfix += ch;
        }
        else if(ch == '(')
        {
            s.push(ch);
        }
        else if(ch == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if(!s.empty())
                s.pop();
        }
        else
        {
            while(!s.empty() && s.top() != '(' &&
                  priority(s.top()) >= priority(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix Expression: " << postfix;

    return 0;
}
