#include <bits/stdc++.h>

using namespace std;

inline void print(int64_t a[], int64_t n)
{
    for (int64_t i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t n;
        cin >> n;
        int64_t a[n];
        for (auto &i : a)
            cin >> i;

        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        if (n == 2)
        {
            if (abs(a[0] - a[1]) == 1)
                cout << 1 << "\n";
            else
                cout << 2 << "\n";
            continue;
        }

        int64_t diff[n - 1] = {0}, gcd[n - 2] = {0};
        for (int64_t i = 0; i < n - 1; ++i)
            diff[i] = abs(a[i] - a[i + 1]);

        // print(diff, n - 1);

        int64_t ans = 0, cnt = 0, k = diff[0];
        for (int64_t i = 0; i < n - 2; ++i)
        {
            if (__gcd(k, diff[i + 1]) != 1)
            {
                ++cnt;
                k = __gcd(k, diff[i + 1]);
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 0;
                k = diff[i + 1];
                // cout << k << " ";
            }
        }
        ans = max(ans, cnt);
        cnt = 0, k = diff[n - 2];
        for (int64_t i = n - 2; i >= 1; --i)
        {
            if (__gcd(k, diff[i - 1]) != 1)
            {
                ++cnt;
                k = __gcd(k, diff[i - 1]);
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 0;
                k = diff[i - 1];
                // cout << k << " ";
            }
        }
        ans = max(ans, cnt);

        cout << ans + 2 << "\n";
    }
}