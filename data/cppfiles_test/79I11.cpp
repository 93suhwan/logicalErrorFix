#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int curr = 0, ans = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int mx = i, ind = -1;
        for (int j = 1; j <= a[i]; j++)
        {
            if (curr + j - b[curr + j] > mx)
            {
                mx = curr + j - b[curr + j];
                ind = curr + j;
            }
        }
        if (mx == i)
        {
            cout << -1 << endl;
            return;
        }
        curr = mx;
        v.push_back(max(0, n - ind));
        ans++;
        if (curr >= n)
            break;
    }
    cout << ans << endl;
    for (auto x : v)
        cout << x << " ";
}

int_fast32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout << setprecision(15);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}