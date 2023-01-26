#include <iostream>
#include <sstream>
using namespace std;
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <math.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Ordered Set Tree
typedef tree<int, null_type, less_equal<int>,
             rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fs first
#define ss second
#define loop(i, k, n) for (ll i = k; i < n; i++)
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define vvpi vector<vector<pair<ll, ll>>>
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<vi> vii;
#define vpi vector<pi>
#define MOD 998244353
#define MAX 10000001
#define dim 200005                                  // CHANGE THIS WHILE SUBMITTING
#define Z 11
#define PRIME 998244353
#define ld long double
#define PI (ld)3.141592653589793
#define all(v) v.begin(),v.end()
#define INF 1000000000000000000

ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}
ll MOD_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}

int C[5001][5001];

void binomialCoeff(int n){
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    binomialCoeff(5000);
    int n,k; cin>>n>>k;
    string s; cin>>s;
    vi one;
    loop(i,0,n) {
        if(s[i]=='1') one.pb(i);
    }
    vpi p;
    int r=k; int l=-1; int start=0;
    int no_ones = one.size();
    if(k==0 || k > no_ones) {
        cout<<1<<"\n";
        return 0;
    }
    one.pb(n);
    loop(i,0,no_ones-k+1) {
        p.pb({l+1,one[r++]-1});
        l=one[start++];
    }
    for(auto it : p) cout<<it.fs<<" "<<it.ss<<'\n';

    ll ans=0; start=0;
    for(auto it : p) {
        if(!it.fs) { ans=C[it.ss-it.fs+1][k]; start++;}
        else ans = (ans+C[it.ss-it.fs+1][k]-C[one[start+++k-1]-1-it.fs+1][k-1]+MOD)%MOD;
    }
    cout<<ans<<"\n";
}
