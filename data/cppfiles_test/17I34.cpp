/* Author : Mitul Khatri */
#include <bits/stdc++.h>

using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
// #define ll long long
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool sortm(pair<int,int> &a,pair<int,int> &b)
{
    int x=abs(a.ff) + abs(a.ss);
    int y=abs(b.ff) + abs(b.ss);
    return x<y;
}
void init()
{
    FAST;
    #ifndef ONLINE_JUDGE    
    freopen("Error.txt", "w", stderr);
    #endif
}
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    ordered_set pos,neg;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pos.insert(x);
        neg.insert(-x);
        ans+=min(pos.order_of_key(x),neg.order_of_key(-x));
    }
    cout<<ans<<nline;
    return ;
}
int main()
{
        init();
        int t=1;
        cin>>t;
        while(t--)
           solve();
return 0;
}