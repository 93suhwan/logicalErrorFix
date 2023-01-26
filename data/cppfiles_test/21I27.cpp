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

ll dp[NMAX][NMAX][NMAX];
ll p, ep;
ll fact[NMAX];
ll inv[NMAX];

ll euler(ll n){
     long long d = 2, p, prod = n;
    while ( d * d <= n ) {
        p = 0;
        while ( n % d == 0 ) {
            n /= d;
            p ++;
        }
        if ( p )
            prod = prod / d * ( d - 1 );
        d ++;
    }
    if ( n > 1 )
        prod = prod / n * ( n - 1 );
    return prod;
}
ll putere(ll a,ll n,ll m){
    ll prod = 1;
    do{
        if(n%2 != 0){
            prod = (long long)prod * a % m;
        }
        a = 1LL * a * a % m;
        n /= 2;
    }while(n != 0);
    return prod;
}

ll invers(ll a){
    return putere(a, ep - 1, p);
}

ll comb(ll n, ll k){
    return ((fact[n] * inv[k]) % p * inv[n - k]) % p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k, i, j;
    cin >> n >> m >> k >> p;
    ep = euler(p);
    fact[0] = 1;
    inv[0] = invers(1);
    for(i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= p;
        inv[i] = invers(fact[i]);
    }
    for(i = 0; i <= n; i++){
        for(j = i + 1; j <= m; j++)
            dp[i][j][0] = fact[i];
    }
    for(i = 1; i <= n; i++){
        dp[i][1][1] = fact[i];
        for(j = 2; j <= min(i, m); j++){
            for(ll t = 0; t <= k; t++){
                for(ll st = 1; st < i - 1; st++){
                    for(ll deja = 0; deja <= t; deja++){
                        dp[i][j][t] += ((dp[st][j - 1][deja] * dp[(i - st - 1)][j - 1][t - deja]) % p * comb(i - 1, st)) % p;
                        dp[i][j][t] %= p;
                    }
                }
                dp[i][j][t] += ((dp[i - 1][j - 1][t]) % p * 2) % p; /// Pentru la inceput si la sfarsit
                dp[i][j][t] %= p;
            }
        }
    }
    cout << dp[n][m][k];
    return 0;
}
