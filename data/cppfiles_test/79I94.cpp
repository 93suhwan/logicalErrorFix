//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
  
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Общий файл. 
//#include <ext/pb_ds/tree_policy.hpp> // Содержит класс tree_order_statistics_node_updat
  
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define repb(i, r, l) for (int i = r; i >= l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define ret(a) {cout << a; exit(0);}
  
using namespace std;
  
mt19937 mrand(random_device{}()); 
const int mod = 1e9 + 7;
int rnd(int x) { return mrand() % x;}
 
ld powmod(ld a,ll b) {ld res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}                  
  
typedef pair < int , int > pii ;                                            
typedef pair < long long  , long long > pll ;
  
const int N = 3e5 + 5, shift = 2e5+1;                               
int n, m, k;
int a[N], b[N];
int cnt[35];
string s;
pii t[N << 2];
int dp[N];
pii nx[N];
vector < int > poss[N];
void upd(int v, int tl, int tr , int pos, int val){
    if(tl == tr){
        t[v] = {val, pos};
        return;
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm)
        upd(v << 1, tl, tm, pos, val);
    else upd(v << 1|1, tm + 1, tr , pos , val);
    if(dp[t[v << 1].fi] < dp[t[v << 1|1].fi])
        t[v] = t[v << 1];
    else t[v] = t[v << 1|1];
}
pii get(int v, int tl, int tr , int l, int r){
    if(l > r || tl > r|| l > tr)
        return {n + 1,n + 1};
    if(l <= tl and tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    pii a = get(v << 1, tl, tm ,l , r);
    pii b=  get(v << 1|1, tm + 1, tr , l, r);
    if(dp[a.fi] < dp[b.fi])
        return a;
    return b;
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }          
    for(int i = 1; i < n; i++){
        cin >> b[i];
            poss[i + b[i]].pb(i);
    }
    for(int i = 1; i <= (3e5 + 1)* 4; i++)t[i] = {n + 1, n + 1};
    dp[n + 1] = 1e9;
    upd(1,0,n,0,0);
    for(int i = 1; i <= n; i++){
        nx[i] = get(1,0,n, i - a[i], i);            
        dp[i] = dp[nx[i].fi] + 1;
        for(int to: poss[i])
            upd(1,0,n, to, i);
    }
    if(dp[n] >= 1e9){
        cout << "-1";return;
    }
    cout << dp[n] << '\n';
    for(int i = n; ; ){
        cout << nx[i].se << ' ';
        if(nx[i].se == 0)return;
        i = nx[i].fi;
    }
        
}
main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--)solve();

}
