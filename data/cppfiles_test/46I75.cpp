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
template <typename T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int maxi = *max_element(all(a));
    vector<int> nxt(n, -1);
    set<pair<int, int>> s;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && (*s.begin()).first <= a[i])
        {
            nxt[(*s.begin()).second] = i;
            s.erase(s.begin());
        }
        s.insert({a[i], i});
    }
    int curr = n - 1;
    while (curr != -1 && a[curr] != maxi)
    {
        ans++;
        curr = nxt[curr];
    }
    cout << ans << "\n";
}
 
// Main Function
int main()
{
    fast
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
} 