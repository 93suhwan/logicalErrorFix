#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int x = -1;
bool match(const char ch, const char p)
{
    if (ch == '_')
        return true;
    if (ch == 'X')
    {
        if (x == -1)
        {
            x = p;
            return true;
        }
        else
        {
            return x == p;
        }
    }
    return ch == p;
}
int myCount(const int x, bool hasX, bool fx, bool f_, int mul)
{
    int count = mul;
    if (fx)
    {
        if (x == -1)
            count *= 9;
        if (x == '0')
            count = 0;
    }
    if (!fx)
    {
        if (x == -1 && hasX)
            count *= 10;
    }
    if (f_)
    {
        count *= 9;
    }
    return count;
}
int main()
{
    int n, ans = 0;
    char s[11];
    gets_s(s, -1);
    string str(s);
    n = str.length();
    if (n == 0)
    {
        ans = 0;
    }
    else if (n == 1)
    {
        ans = match(s[0], '0');
    }
    else if (n == 2)
    {
        char a = str[n - 2], b = str[n - 1];
        x = -1;
        ans += match(a, '2') && match(b, '5');
        x = -1;
        ans += match(a, '5') && match(b, '0');
        x = -1;
        ans += match(a, '7') && match(b, '5');
    }
    else
    {
        char a = str[n - 2], b = str[n - 1];
        x = -1;
        int mul = 1;
        bool hasX = false;
        bool fx = false;
        bool f_ = false;
        for (int i = 1; i < n - 2; i++)
        {
            if (str[i] == 'X')
                hasX = true;
            if (str[i] == '_')
                mul *= 10;
        }
        if (str[0] == '_')
            f_ = true;
        if (str[0] == 'X')
            fx = true;
        x = -1;
        if (match(a, '2') && match(b, '5'))
        {
            ans += myCount(x, hasX, fx, f_, mul);
        }
        x = -1;
        if (match(a, '7') && match(b, '5'))
        {
            ans += myCount(x, hasX, fx, f_, mul);
        }
        x = -1;
        if (match(a, '5') && match(b, '0'))
        {
            ans += myCount(x, hasX, fx, f_, mul);
        }
        x = -1;
        if (match(a, '0') && match(b, '0'))
        {
            ans += myCount(x, hasX, fx, f_, mul);
        }
        if (str[0] == '0')ans = 0;
    }
    printf("%d", ans);
    return 0;
}