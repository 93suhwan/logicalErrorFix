#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 100010

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll dp[maxn];
gp_hash_table<ll, int, custom_hash> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 1; i < maxn; i++) dp[i] = i;
    for (i = 2; i < maxn; i++) {
        dp[i] -= dp[1];
        for (j = 2; j * j <= i; j++) {
            if (i % j != 0) continue;
            dp[i] -= dp[j];
            if (j * j == i) continue;
            dp[i] -= dp[i / j];
        }
    }

    /* for (i = 1; i <= 100; i++) cout << dp[i] << ' ';
    cout << nl; */

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            if (i % j != 0) continue;
            for (k = 1; k <= a[i]; k++) {
                if (a[i] % k != 0) continue;
                // cout << "j, k, add =" _ j _ k _ dp[j] * dp[k] * mp[100001 * j + k] << nl;
                res += (dp[j] * dp[k] * mp[100001 * j + k]); mp[100001 * j + k]++;
                res %= mod;
            }
        }
    }

    res *= 2;
    for (i = 1; i <= n; i++) res += (i * a[i]);
    cout << res << nl;

    return 0;
}
