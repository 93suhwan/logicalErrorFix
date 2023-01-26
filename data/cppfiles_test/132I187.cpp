#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    vector<int> v(6);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[1] << " " << v.back() - (v[0] + v[1]) << "\n";
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
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}