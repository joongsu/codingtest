// 백준 - 9012 괄호
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    string str;
    while (n--)
    {
        queue<char> q;
        getline(cin, str);
        int leftcnt = 0;

        for (char c : str)
            q.push(c);
        if (!q.empty() && q.front() == ')')
        {
            cout << "NO" << '\n';
            continue;
        }
        bool isValid = true;

        while (!q.empty())
        {
            if (q.front() == '(')
            {
                leftcnt++;
            }
            else
            {
                leftcnt--;

                if (leftcnt < 0)
                {
                    isValid = false;
                    break;
                }
            }
            q.pop();
        }
        if (isValid && leftcnt == 0)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
