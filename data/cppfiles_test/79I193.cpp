#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define REP(i, a, b) for (long long int i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<ii>
#define li long int
#define ll long long int
#define vll vector<ll>
#define vl vector<long>
#define ld long double
#define ull unsigned long long int
#define set_bits __builtin_popcountll

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
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

template <class T> void op_vector(vector <T> v) {for (T i : v) cout << i << " "; cout << "\n";}
template <class T, class V> void ip_vector(vector <T> &v, V n) {v.resize(n); T tmp; for (V i = 0; i < n; i++) {cin >> v[i];}}

bool isPrime(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

void solve() {
    ll n; cin>>n;
    string s; cin>>s;
    vi a(n);
    REP(i, 0, n) {
        string tmp = "";
        tmp.pb(s[i]);
        a[i] = stoi(tmp);
    }
    bool flag = false;
    ll res = 0, nRes;
    map<ll, ll> mp;
    REP(i, 0, n)
        mp[a[i]]++;
    REP(i, 1, 10) {
        if(mp[i] >= 2) {
            flag = true;
            nRes = 2;
            res = i * 10 + i;
            break;
        }
    }
    if(!flag) {
        REP(i, 0, n) {
            string tmp = "";
            REP(j, i, n) {
                tmp.pb(s[j]);
                ll cur = stoi(tmp);
                if(!isPrime(cur)) {
                    nRes = tmp.size();
                    res = cur;
                    break;
                }
            }
        }
    }
    cout<<nRes<<"\n"<<res<<"\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    
    fastio();
    ll t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}