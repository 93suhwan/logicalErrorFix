#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'         //Comment out if interactive
#define int long long int //Comment out if memory exceeds

using namespace std;

//const int MOD=1000000007;

void solve()
{
    string str;
    cin >> str;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'A')
            a++;
        if (str[i] == 'B')
            b++;
        if (str[i] == 'C')
            c++;
    }
    if (a + c == b + c)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start_timer = chrono::high_resolution_clock::now();
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

#ifdef LOCAL
    auto stop_timer = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop_timer - start_timer);
    cerr << "Time taken : " << ((long double)duration.count()) / ((long double)1e9) << "s " << endl;
#endif
    return 0;
}