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
int mod = 998244353;
vi fact(5005);
void init()
{
    fact[0] = fact[1] = 1;
    f(i, 2, 5001, 1)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
}
void solve()
{
    init();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0)
    {
        cout << 1 << endl;
        return;
    }
    int ans = 0;
    vi one, prefix(n + 5);
    f(i, 0, n, 1) if (s[i] == '1') one.pb(i);
    f(i, 0, n, 1) if (s[i] == '1') prefix[i + 1]++;
    f(i, 1, n + 1, 1)prefix[i] += prefix[i - 1];
    f(i, 0, one.size() - k + 1, 1)
    {
        int dif = 0;
        if (i + k < one.size())
        {
            dif = one[i + k] - i;
        }
        else
        {
            dif = n - i;
        }
        int val = fact[dif];
        int val1 = fact[dif - k];
        val1 *= fact[k];
        val1 %= mod;
        ans += (val * (powmod(val1, mod - 2, mod)));
        ans %= mod;
    }
    int ans1 = 0;
    f(i, 0, one.size() , 1)
    {
        int dif = 0, one1 = 0;
        if (i + k < one.size())
        {
            dif = one[i + k] - i - 1;
            one1 = prefix[one[i + k] + 1] - prefix[i + 1] - 1;
        }
        else
        {
            break;
        }
        int val = fact[dif];
        int val1 = fact[dif - one1];
        val1 *= fact[one1];
        val1 %= mod;
        ans1 += (val * (powmod(val1, mod - 2, mod)));
        ans1 %= mod;
    }
    if (ans == 0 && ans1 == 0)
    {
        cout << 1;
        return;
    }
    cout << (ans - ans1 + mod) % mod << endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast
    int t;
    t = 1;
    //cin >> t;
    while (t--) solve();
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}