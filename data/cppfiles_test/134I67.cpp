//HARE KRISHNA

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double lld;
#define ull unsigned long long
#define int ll
#define rep(i, m, n) for (int i = m; i < n; i++)
#define rev(i, n, m) for(int i=n-1; i>=m; i--)
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define SET(n) cout << fixed << setprecision(n)
#define pii pair<int, int>
#define vi vector<int> 
#define vpii vector<pii> 
#define clr(x) memset(x, 0, sizeof(x))
#define mset(x, a) memset(x, a, sizeof(x))
#define M 1000000007
#define MM 998244353
#define INF 1e18
#define PI 3.141592653589793238462

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void print(const T *const arr, int count) {for (int i = 0; i < count; ++i) {_print(arr[i]); cerr<<" ";} cerr<<endl;}

void Solve(){
    int n;
    cin>>n;
    vi a(n);
    vi v1, v2;
    rep(i, 0, n){
        cin>>a[i];
        if(i%2==0) v1.pb(a[i]);
        else v2.pb(a[i]);
    }

    int g1, g2;
    if(n==1){
        cout<<a[0];
        return;
    }

    g1=v1[0], g2=v2[0];

    rep(i, 1, v1.size()){
        g1=__gcd(g1, v1[i]);
    }
    rep(i, 1, v2.size()){
        g2=__gcd(g2, v2[i]);
    }

    if(g1==g2){
        cout<<0;
        return;
    }
    int x=max(g1, g2);
    bool f1=0, f2=0;

    rep(i, 0, n){
        if(a[i]%x==0){
            if(i%2==1) f1=1;
            else f2=1;
        }
    }

    if(f1 && f2) cout<<0;
    else cout<<x;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;
    rep(i, 1, T+1)
    {
        //cout<<"Case #"<<i<<": ";
        Solve();
        cout << endl;
    }

    return 0;
}