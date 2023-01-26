#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long int
#define double long double
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pi pair<int,int>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pf push_front
#define deb(x) cerr<<#x<<" : "<<x<<endl;
#define fi first
#define se second
#define mi map<int,int>
#define PI   3.141592653589
#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define f(i,x,n,z) for(int i=x;i<n;i+=z)
#define rf(i,x,n,z) for(int i=n;i>=x;i-=z)
#define check(x)   cerr<<#x<<" : "<<x<<endl;
#define ordered_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define fbo find_by_order
#define ook order_of_key
#define baar exit(0)
const int INF = 1e9 + 5;
using namespace __gnu_pbds;
using namespace std;
int powmod(int base, int exponent, int mod)
{
    int ans = 1;
    while (exponent) {
        if (exponent & 1)ans = (ans * base) % mod;
        base = (base * base) % mod;
        exponent /= 2;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vii v(n);
    f(i, 0, n, 1) cin >> v[i].first >> v[i].second;
    int ans = 0;
    mi mp1, mp2;
    rf(i, 0, n - 1, 1)
    {
        int ttl = n - i - 1;
        if (ttl >= 2) ans += ((ttl) * (ttl - 1) / 2);
        ans -= (mp1[v[i].first] * mp2[v[i].second]);
        mp1[v[i].first]++;
        mp2[v[i].second]++;
    }
    cout << ans << endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast
    int t;
    cin >> t;
    //t = 1;
    while (t--) solve();
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
