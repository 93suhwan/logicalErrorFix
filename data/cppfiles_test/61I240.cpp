#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")

typedef long long int ll;
typedef long long unsigned int ull;
typedef pair<ll, ll> llpair;
//Refer https://codeforces.com/blog/entry/11080
typedef tree<
    ll,
    null_type,
    less<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
typedef std::numeric_limits<double> dbl;

#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
#define _MATH_DEFINES_DEFINED
#define M_E 2.71828182845904523536
#define M_LOG2E 1.44269504088896340736
#define M_LOG10E 0.434294481903251827651
#define M_LN2 0.693147180559945309417
#define M_LN10 2.30258509299404568402
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.785398163397448309616
#define M_1_PI 0.318309886183790671538
#define M_2_PI 0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2 1.41421356237309504880
#define M_SQRT1_2 0.707106781186547524401
#endif

void prepareIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(dbl::max_digits10);
}

//void increaseStackDepth()
//{
//	rlimit R;
//	getrlimit(RLIMIT_STACK, &R);
//	R.rlim_cur = R.rlim_max;
//	setrlimit(RLIMIT_STACK, &R);
//}
/*
unordered_map<int,int>mp;
mp.reserve(1024);
mp.max_load_factor(0.25);
*/

struct HASH
{
    size_t operator()(const llpair& x) const
    {
        return hash<long long>()(x.first ^ (x.second) << 32);
    }
};

const ll MOD = 1e9 + 7;

const ll N = 1e5 + 5;

ll solve(vector<ll>& a) {
    ll n = a.size();

    vector<vector<ll>> dp(n, vector<ll>(3, 0));

    dp[n - 1][0] = a[n - 1];

    vector<ll> tmp(3);
    for (ll i = n - 2; i >= 0; i--) {
        tmp[0] = a[i];
        tmp[1] = dp[i + 1][0] * a[i];
        tmp[2] = dp[i + 1][1] * a[i];

        dp[i][0] = dp[i + 1][0] + tmp[0];
        dp[i][1] = dp[i + 1][1] + tmp[1];
        dp[i][2] = dp[i + 1][2] + tmp[2];
    }
    return dp[0][2];
}

ll nC2(ll n) {
    return (n * (n - 1)) / 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    prepareIO();

    ll t = 1;
    cin >> t;

    for (ll Case = 1; Case <= t; Case++)
    {
        ll n;
        cin >> n;

        vector<ll> a(n, 0), b(n, 0);
        vector<llpair> arr(n);
        map<llpair, ll> mp;
        for (ll i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            arr[i] = { x - 1,y - 1 };
            mp[{x - 1, y - 1}]++;
            a[x - 1]++;
            b[y - 1]++;
        }

        ll total = (n * (n - 1) * (n - 2)) / 6, toSub = 0;

        for (ll i = 0; i < n; i++) {
            ll x = arr[i].first, y = arr[i].second;
            a[x]--;
            b[y]--;

            toSub += (a[x] * b[y]);
        }

        ll ans = total - toSub;

        cout << ans << "\n";
    }
    return 0;
}