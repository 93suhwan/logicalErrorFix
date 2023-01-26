#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define fastio             ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll                 long long int
#define ld                 long double
#define nl                 "\n"
#define forf(i,a,n)        for(ll i=a;i<=n;i++)
#define forb(i,b,n)        for(ll i=b;i>=n;i--)
#define trav(arr,var)      for(auto& var:arr)
#define ar(a)              trav(a,x) cout<<x<<" ";cout<<nl;
#define d(x)               cout<<#x<<" "<<x<<nl;
#define pb                 push_back
#define vll                vector<ll>
#define all(qw)            qw.begin(),qw.end()
#define pll                pair<ll,ll>
#define vpll               vector<pll>
#define ff                 first
#define ss                 second
#define mp                 make_pair
#define sll                set<ll>
#define mll                map<ll,ll>
#define go(x)              {cout<<x<<nl;return;}
#define inv(v,n)           forf(ij,1,n)    {ll qq;cin>>qq;v.pb(qq);}
#define oset               tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

ll hcf(ll a, ll b)
{
    if (b == 0)return a;
    return hcf(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a * b) / hcf(a, b);
}

bool isprime(ll n)
{
    if (n <= 1)   return false;
    if (n <= 3)   return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)  return false;
    return true;
}

const ll MOD = 998244353;
const ll N = 1000;

// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];

// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];

// array to store factorial of first N numbers
ll fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;

    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        b /= 2;
        a = (a * a) % MOD;
    }
    return ans;
}

void solve() {
    // n, x = LI()
    // dp = [[0 for j in range(x + 1)] for i in range(n + 1)]
    // for i in range(2, n + 1):
    //     for j in range(1, x + 1):
    //         if j <= i - 1:
    //             dp[i][j] = pow(j, i, MOD)
    //         else:
    //             dp[i][j] = pow(i - 1, i, MOD)
    //             for k in range(1, i + 1):
    //                 dp[i][j] = (dp[i][j] + Binomial(i, k, MOD) * dp[k][j - (i - 1)] * pow(i - 1, i - k, MOD)) % MOD
    // # print(dp)
    // print(dp[-1][-1])
    ll n, x;
    cin >> n >> x;
    ll dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    forf(i, 2, n) {
        forf(j, 1, x) {
            if (j <= i - 1) {
                dp[i][j] = binpow(j, i);
            }
            else {
                dp[i][j] = binpow(i - 1, i);
                forf(k, 1, i) {
                    dp[i][j] = (dp[i][j] + Binomial(i, k, MOD) * dp[k][j - (i - 1)] * binpow(i - 1, i - k)) % MOD;
                }
            }
        }
    }
    go(dp[n][x])
}


void onlinejudge() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}


int main() { // Change the approach
    onlinejudge();
    fastio
    InverseofNumber(MOD);
    InverseofFactorial(MOD);
    factorial(MOD);
    ll ttt; ttt = 1;
    // cin >> ttt;
    cout << fixed << setprecision(16);
    forf(i, 1, ttt) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}