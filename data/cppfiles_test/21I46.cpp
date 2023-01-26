#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define debug(x) cerr << #x << " " << x << "\n"
#define debugs(x) cerr << #x << " " << x << " "

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair <ll, ll> pii;
typedef pair <long double, pii> muchie;

const ll NMAX = 101;
const ll VMAX = 21;
const ll INF = (1LL << 59);
const ll MOD = 998244353;
const ll BLOCK = 318;
const ll base = 31;
const ll nr_of_bits = 21;

int dp[NMAX][NMAX][NMAX];
int p, ep;
int fact[NMAX];
int comb[NMAX][NMAX];

int main() {
    int n, m, k, i, j;
    cin >> n >> m >> k >> p;
    fact[0] = 1;
    for(i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % p;
    }
    comb[0][0] = 1;
    for(i = 1; i <= n; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(j = 1; j < i; j++)
            comb[i][j] = (1LL * comb[i - 1][j] + comb[i - 1][j - 1]) % p;
    }
    for(i = 0; i <= n; i++) {
        for(j = i + 1; j <= m; j++)
            dp[i][j][0] = fact[i];
    }
    for(i = 1; i <= n; ++i) {
        dp[i][1][1] = fact[i];
        for(j = 2; j <= i && j <= m; ++j) {
            for(int t = 0; t <= i && t <= k; ++t) {
                for(int st = 0; st < (i + 1) / 2; ++st) {
                    ll s = 0;
                    for(int deja = max(0, t + st + 1 - i); deja <= st && deja <= t; ++deja) {
                        dp[i][j][t] += (1LL * (1LL * dp[st][j - 1][deja] * dp[(i - st - 1)][j - 1][t - deja]) % p * comb[i - 1][st]) % p;
                        if(st < i / 2){
                            s += (1LL * (1LL * dp[st][j - 1][deja] * dp[(i - st - 1)][j - 1][t - deja]) % p * comb[i - 1][st]) % p;
                            if(s >= p)
                                s -= p;
                        }
                        if(dp[i][j][t] >= p)
                            dp[i][j][t] -= p;
                    }
                    dp[i][j][t] += s;
                }
            }
        }
    }
    cout << dp[n][m][k];
    return 0;
}
