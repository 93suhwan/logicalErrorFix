#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define F first
#define S second
#define all(c) (c).begin(), (c).end()

int right_most_set_bit(int x)
{
    return x & (-x);
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (auto &x : a)
            cin >> x;

        vi cntr(30);
        for (int i = 0; i < 30; i++)
        {
            int mask = 1 << i;
            for (auto xy : a)
                cntr[i] += ((xy & mask) != 0);
        }

        int num = INT_MAX;
        for (int i = 0; i < 30; i++)
            if (cntr[i])
                num = min(num, right_most_set_bit(cntr[i]));

        if (num == INT_MAX)
        {
            for (int i = 0; i < n; i++)
                cout << i + 1 << ' ';
            cout << '\n';
        }
        else
        {
            int g = 0;
            for (auto xy : cntr)
                g = __gcd(g, xy);

            vi res;
            res.push_back(g);

            for (int i = 2; i <= g; i++)
                while (g % i == 0)
                {
                    res.push_back(g / i);
                    g /= i;
                }

            if (g != 1)
                res.push_back(1);

            reverse(all(res));
            for (auto xy : res)
                cout << xy << ' ';
            cout << '\n';
        }
    }

    return 0;
}