#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int sumofdigits(int a)
{
    int sum = 0;
    while (a > 0)
    {
        int l = a % 10;
        sum += l;
        a /= 10;
    }
    return sum;
}
main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        while (__gcd(n, sumofdigits(n)) <= 1)
        {
            n++;
        }
        cout << n << endl;
    }
}