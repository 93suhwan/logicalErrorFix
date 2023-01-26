#include<bits/stdc++.h>
using namespace std;
 

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

 

#define pll pair<ll,ll> 
#define vll vector<ll> 
#define mll map<ll,ll>
#define MP        make_pair
#define ff        first
#define ss        second

 

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fr(i,a) rep(i,0,a)
#define per(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) per(i,0,a)

 

#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define all1(x) bg(x)+1,end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define sor1(x) sort(all1(x))
#define pb push_back
#define ins insert
#define EL cout<<"\n";
#define REV(x) reverse(all(x))
 

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define ppb pop_back
#define PI 3.141592653589793238462

 

 

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

 

 

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

 

void printvector(vector<ll> V){
    for(auto i:V){
        cout<<i<<" ";
    }
    cout<<endl;
}
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


ll testcase;
/*-----------------------S P O I D E R M O N-------------------------------*/

 

 bool compare(pair<string,ll> p1,pair<string,ll> p2)
 {
    return p1.ss<p2.ss;
 }

ll fact(ll n)
{
    return (n*(n-1))/2;
} 
// //ll n,m;
// vector<vector<ll>> g;
// vector<ll> comp;

// void dfs(ll node,ll cnt)
// {
//     comp[node]=cnt;
//     for(auto v:g[node])
//     {
//         if(!comp[v])
//         {
//             dfs(v,cnt);
//         }
//     }
// }


void solve()
{
  vll v(7);
  fr(i,7)
  {
    cin>>v[i];
  }
  ll a,b,c;
  ll tot=v[6]; //a+b+c
  ll ab=v[3];
  ll ac=v[4];
  ll bc=v[5];
  a=tot-bc;
  b=tot-ac;
  c=tot-ab;
  cout<<a<<" "<<b<<" "<<c<<endl;
} 


int main(){

 

#ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll T;
    cin>>T;
    //T=1;
    testcase=1;
    while(T--){
        solve();
        testcase++;
    }
    return 0;
}
