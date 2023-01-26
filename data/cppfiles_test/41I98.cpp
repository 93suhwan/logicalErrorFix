// Author: Vinay O. Khilwani
// Language: C++17

// Optimizations
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#pragma GCC optimize ("Os")
 
// Libraries
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// Defines
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fast ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define sz(a) int (a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
using ll = long long int;
using ld = long double;
const ll mod = (ll) (1e9) + 7LL;
const ll M = 998244353LL;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ld pi = acos(-1);

// Global Variable(s)

// Solver Function(s)
void solve()
{
    int n, k;
    cin >> n >> k;
    int curr = 1;
    int ans = 0;
    while (curr < n)
    {
        curr *= k;
        ans++;
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int ii = i - 1;
            int jj = j - 1;
            vector<int> mods_ii, mods_jj;
            while (sz(mods_ii) < ans)
            {
                mods_ii.pb(ii % k);
                ii /= k;
            }
            while (sz(mods_jj) < ans)
            {
                mods_jj.pb(jj % k);
                jj /= k;
            }
            for (int color = 0; color < ans; color++)
            {
                if (mods_jj[color] != mods_ii[color])
                {
                    cout << color + 1 << " ";
                    break;
                }
            }
        }
    }
    cout << "\n";
}
 
// Main Function
int main()
{
    fast
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
} 