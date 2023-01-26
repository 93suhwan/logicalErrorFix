/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

/*Pragma*/
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Os")

/*Weird define*/
//#define int long long
#define ll long long
//#define endl '\n'
#define gcd __gcd
#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update>
//#define p prev
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define count1 __builtin_popcountll

/*For define*/
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define foR(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define forN(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define foRN(i,a,b,c) for(ll i=a;i>=b;i-=c)
#define fora(i, a) for (auto i : a)

/*push-pop-pair define*/
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define x first
#define y second

/*Print define*/
#define write(a, l, r) for (ll ik = l; ik <= r; ik++) cout << a[ik] << ' '; cout << endl
#define writeln(a, l, r) for (ll ik = l; ik <= r; ik++) cout << a[ik] << endl

/*Type-def*/
typedef unsigned long long  ull;
typedef vector<ll>      vi;
typedef pair<ll, ll>        ii;
typedef long double         ld;

/* Calculation with MODULO*/

ll dec(ll x, ll y, int MOD) {return (x-y+MOD)%MOD;}
ll add(ll x, ll y, int MOD) {return (x + y) % MOD;}
ll mul(ll x, ll y, int MOD) {return ((x%MOD) * (y%MOD)) % MOD;}
ll bpow(ll x, ll y, int MOD) {ll res = 1; while (y) {if (y & 1) res = mul(res, x, MOD); x = mul(x, x, MOD); y >>= 1;} return res;}
ll ModInverse(ll x, int MOD) {return bpow(x, MOD - 2, MOD);}
ll Div(ll x, ll y, int MOD) {return mul(x, ModInverse(y, MOD), MOD);}
ll GetBit(ll val, ll num) {return ((val>>num) & 1LL);}

/*Some simple checking and calculation function*/
string yn(bool k){if (k) return "YES"; else return "NO";}
__int128 binpower(__int128 base, __int128 e, __int128 mod) {__int128 result = 1;base %= mod;while (e){if (e & 1)result = (__int128)result * base % mod;base = (__int128)base * base % mod;e >>= 1;    }return result;}
bool check_composite(__int128 n, __int128 a, __int128 d, int s) {__int128 x = binpower(a, d, n); if (x == 1 or x == n - 1)return false;for (int r = 1; r < s; r++) {x = (__int128)x * x % n;if (x == n - 1)return false;}return true;};
bool checkprime(__int128 n) {if (n < 2)return false;int r = 0;__int128 d = n - 1;while ((d & 1) == 0) {d >>= 1;r++;}for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {if (n == a)return true;if (check_composite(n, a, d, r))return false;}return true;}
bool checksqr(ll k){return (trunc(sqrt(k))*trunc(sqrt(k))==k);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
//ll sum(ll n) {return n*(n+1)/2;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e3+5;
bool a[N][N];
int f[2*N][2*N], f2[2*N][2*N], cur[2*N], cur2[2*N];
vector <ii> v[N],v2[N];

int n,m;

bool valid(int x, int y){
    return (x <= n && y <= m);
}

void solve(){
    int q;
    cin >> n >> m >> q;
    //0 0 0 0
    //0 0 0 0
    //0 0 0 0
    For(i,1,n) For(j,1,m) a[i][j] = true;
    ll base = 0;
    For(i,1,m-1){
        int x = 1, y = i, state = 0, cnt = 0;
        while (valid(x,y)){
            v[i].pb({x,y});
            cnt++;
            f[i][cnt] = true;
            if (!state) y++;
            else x++;
            state = !state;
        }
        cur[i] = (v[i].size() - 1) * (v[i].size()) / 2;
        base += cur[i];
    }
    For(i,1,n-1){
        int x = i, y = 1, state = 0, cnt = 0;
        while (valid(x,y)){
            v2[i].pb({x,y});
            cnt++;
            f2[i][cnt] = true;
            if (!state) x++;
            else y++;
            state = !state;
        }
        cur2[i] = (v2[i].size()) * (v2[i].size() - 1) / 2;
        base += cur2[i];
    }
    //0 0 0
    //0 0 0
    base += n * m;
    while (q--){
        int x,y;
        cin >> x >> y;
        if (a[x][y]) base--;
        else base++;
        ii p = {x,y};
        a[x][y] = !a[x][y];
        For(i,1,m - 1){
            if (v[i].empty()) continue;
            int pos = lower_bound(v[i].begin(), v[i].end(), p) - v[i].begin();
            if (v[i][pos] == p){
                base -= cur[i];
                f[i][pos+1] = !f[i][pos+1];
                int len = v[i].size();
                int l = 1;
                cur[i] = 0;
                For(j,1,len+1){
                    if (f[i][j] == 0){
                        int le = j - l;
                        if (le > 0) cur[i] += le * (le - 1);
                        l = j + 1;
                    }
                }
                cur[i] /= 2;
                base += cur[i];
            }
        }
        For(i,1,n - 1){
            if (v2[i].empty()) continue;
            int pos = lower_bound(v2[i].begin(), v2[i].end(), p) - v2[i].begin();
            if (v2[i][pos] == p){
                base -= cur2[i];
                f2[i][pos+1] = !f2[i][pos+1];
                int len = v2[i].size();
                int l = 1;
                cur2[i] = 0;
                For(j,1,len+1){
                    if (f2[i][j] == 0){
                        int le = j - l;
                        if (le > 0) cur2[i] += le * (le - 1);
                        l = j + 1;
                    }
                }
                cur2[i] /= 2;
                base += cur2[i];
            }
        }
        cout << base << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}
/*
//Delete define endl when interactive prolem

INPUT :
2
5 4
1000
0000
0110
0000
0001
9 9
001010001
101110100
000010011
100000001
101010101
110001111
000001111
111100000
000110000

OUTPUT :

If it WA, check :
- Special case (Usually, n=1)
- WRONG FORMAT OUTPUT
- Check reading
- Change (ll) to (ull)
- lleger Overflow (The number that bigger than 2^63-1)
*/
