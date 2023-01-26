#include<iostream>
#include<algorithm>
#include<cstring>
#include<algorithm>

using namespace std;
void solve()
{
    long long x, y;
    scanf("%lld%lld", &x, &y);
    long long n = 0;
    if(x <= y)
    {
        if(y % x == 0)
        {
            n = x;
        }
        else if((y - x) % 2 == 0)
        {
            n = (y - x) / 2 + x;
        }
        else
        {
            for(int i = x + 1; i < y && n == 0; i++)
            {
                if(i % x == y % i)
                {
                    n = i;
                }
            }
        }
    }
    else
    {
        n = x * y / (__gcd(x, y)) + y;
    }
    cout << n << endl;
    return ;
}
int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
    return 0;
}
