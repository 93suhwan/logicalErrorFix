#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5;
int a[N + 5], s[N + 5], st[N + 5][21];
int query(int l, int r)
{
    if (l > r)
        return 0;
    int k = log2(r - l + 1);
    return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
            s[i] = abs(a[i + 1] - a[i]);
        for (int i = 1; i < n; i++)
            st[i][0] = s[i];
        for (int j = 1; j <= 20; j++)
            for (int i = 1; i < n; i++)
                if (i + (1 << j - 1) < n)
                    st[i][j] = __gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        int ans = 0;
        for (int i = 1, j = 0; i < n; i++)
        {
            int k = query(i, j);
            while (j + 1 < n && __gcd(k, s[j + 1]) != 1)
            {
                k = __gcd(k, s[j + 1]);
                j++;
            }
            ans = max(ans, j - i + 1);
        }
        cout << ans + 1 << endl;
    }
    return 0;
}