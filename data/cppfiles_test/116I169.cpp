#include <bits/stdc++.h>

using namespace std;

#define RG register
#define IL __inline__ __attribute__((always_inline))
#define For(i, a, b) for(RG int i = a, ___u = b; i <= ___u; ++i)
#define Dor(i, a, b) for(RG int i = b, ___d = a; i >= ___d; --i)
#define Rep(i, a, b) for(RG int i = a, ___u = b; i != ___u; ++i)
#define dmin(a, b) ((a) < (b) ? (a) : (b))
#define dmax(a, b) ((a) > (b) ? (a) : (b))
#define cmin(a, b) ((a) > (b) ? (a) = (b) : 1)
#define cmax(a, b) ((a) < (b) ? (a) = (b) : 1)
#define ddel(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
#define dabs(i) ((i) > 0 ? (i) : -(i))
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 500000 + 50;
// const int maxn = 20;
const ll mod = 998244353ll;

ll n, a[maxn], dp[maxn], sum[maxn], cnt[maxn], mi[maxn];
vector<ll> vec[maxn];

ll calc(ll i, ll x)
{
    ll pos = lower_bound(vec[x].begin(), vec[x].end(), i) - vec[x].begin();
    if (pos == vec[x].size())
        return n;
    else
        return vec[x][pos];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    mi[0] = 1;
    For (i, 1, maxn - 1)
        mi[i] = mi[i - 1] * 2 % mod;
    while (T--)
    {
        scanf("%lld", &n);
        
        For (i, 0, n + 10)
            vec[i].clear(), sum[i] = 0, dp[i] = 0, cnt[i] = 0;
        // sum[n] = 1;
        For (i, 0, n - 1)
            scanf("%lld", &a[i]), vec[a[i]].push_back(i);
        Dor (i, 0, n - 1)
        {
            if (a[i] <= 1)
            {
                ++cnt[a[i]];
                continue;
            }
            ll x = a[i], y = a[i] - 2;
            ll tot = cnt[x] + cnt[y];
            sum[i] = mi[tot];
            ++cnt[a[i]];
        }
        For (i, 2, n)
        {
            if (vec[i].size() <= 1)
                continue;
            
            for (int j = vec[i].size() - 2; j >= 0; --j)
                (sum[vec[i][j]] += sum[vec[i][j + 1]]) %= mod;
        }
        
        // For (i, 0, n)
        //     printf("%lld\n", cnt[i]);

        ll ans = 0;
        For (i, 0, n - 1)
        {
            if (a[i] == 0)
            {
                ll pos = calc(i, 2);
                (ans += ((dp[0] + 1) % mod) * (sum[pos] + 1) % mod) %= mod;
                if (sum[pos] > 1)
                    (ans += dp[0]) %= mod;
                dp[0] = 2 * dp[0] + 1;
                dp[0] %= mod;
            }
            else
            {
                ll pos = calc(i, a[i] + 2);
                (ans += ((dp[a[i]] + dp[a[i] - 1]) % mod) * (sum[pos] + 1) % mod) %= mod;
                (dp[a[i]] *= 2) %= mod;
                (dp[a[i]] += dp[a[i] - 1]) %= mod;
            }
        }
        (ans += mi[cnt[1]] - 1) %= mod;
        printf("%lld\n", ans % mod);
    }
    return 0;
}