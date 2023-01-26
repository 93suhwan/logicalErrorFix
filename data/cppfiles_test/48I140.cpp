// Problem: D. Yet Another Sorting Problem
// Contest: Codeforces - Codeforces Round #759 (Div. 2, based on Technocup 2022 Elimination Round 3)
// URL: https://codeforces.com/contest/1591/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Setsuna
// Time: 2021-12-12 23:16:18
// 
// 
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>  //hash_table
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define mp(x, y) make_pair(x, y)
const ll mod = 100000007;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> rbtree;

const ll inf = pow(2, 50) - 1;
ll mul(ll a, ll b) { return a * b % mod; }
ll powmod(ll a, ll b){ ll res = 1;a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1) res = res * a % mod; a = a * a % mod; } return res; }
ll inv(ll x) { return powmod(x, mod - 2); }

namespace binary_search {
ll lower(ll start, ll end, ll target, function< ll(ll) > func)
// for non-decreasing function func(x),
// find the first x in [l,r] that func(x)>=target
{
    ll l = start, r = end;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (func(mid) < target)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

ll upper(ll start, ll end, ll target, function< ll(ll) > func)
// for non-decreasing function func(x),
// find the first x in [l,r] that func(x)>target
{
    ll l = start, r = end;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (func(mid) <= target)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
};  // namespace binary_search

// Header

/*--------------------------------------------*/

// Code:
void solve()
{
    
    // 2 1 1 3 1
    // 2 1 3
    // 1 2 3
    // 2 1 3 ×
    // 3 2 1 ×
    // 1 3 2 ×
    // 1 2 3 √
    // 3 1 2 √
    // 2 3 1 √
    // x y z
    // ->
    // z x y 
    // y z x
    // 4 2 1 3
    // 3 1 2
    // 1 2 3
    // 
    // 2 3 1 4
    // 2 1 3 4     
    // int n; cin>>n;
    // pii a[n+1]; for(int i=1;i<=n;i++) cin>>a[i].first, a[i].second = -i;
    // sort(a+1,a+1+n);
    // int rank = 0, last = 0, cnt = 0;
    // for(int i=1;i<=n;i++)
    // {
        // if(a[i].first != last)
        // {
            // rank += cnt+1;
            // cnt = 0;
        // }
        // else cnt++;
        // last = a[i].first;
        // if(-a[i].second - rank == 1) {cout<<"NO\n";return;}
    // }
    // cout<<"YES\n";
    //int a[n+1]; for(int i=1;i<=n;i++) cin>>a[i];
    int n; cin>>n;
    int a[2*n+1]; 
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n>=4) {cout<<"YES\n";return;}
    if(n==1) {cout<<"YES\n";return;}
    if(n==2)
    {
        if(a[1] <= a[2]) cout<<"YES\n"; 
        else cout<<"NO\n";
        return;
    }
    
    for(int i=1;i<=n;i++)
    {
        swap(a[1],a[3]); swap(a[1],a[2]);
        if(a[1] <= a[2] && a[2]<= a[3]) {cout<<"YES\n";return;}
    }
    cout<<"NO\n";
    
} 
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}
