#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<vector>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>
 
#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;
using namespace chrono;
typedef long long ll ;
typedef long double ld ;
 
const ll MAX=1e9;
const ll MIN=1e-9;
 
 
 
 
 
 
 
 
 
//- chori ka mall 
//--------------------------------------- 
#define ll         long long
#define lld        long double
#define pb          push_back
#define pf          push_front
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define ff          first
#define ss           second
#define nline        '\n'
#define sz(x)     (ll)(x).size()
#define ull       unsigned long long
//-------------------------------------------
 
//------------------------------------------------
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++)
#define _init(b)     memset(b,-1,sizeof(b))
#define _init0(b)     memset(b,0,sizeof(b))
#define MOD         1000000007
#define hell        998244353
#define output(x) cout << (x ? "YES" : "NO")<<endl;
#define Output(x) cout << (x ? "Yes" : "No")<<endl;

//------------------------------------------------
 
 
 
//-----------------------------------------
#define MOD2 (998244353)
#define MOD3 (1000000009)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18) 
 
 
 
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
ifstream cinn("in.txt");ofstream coutt("out.txt");
ll poww(const ll &a,ll b,const ll &m=MOD){if(b==0)return 1;ll x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;} 
 
//---------------------------------------------------------------------------------------
 
 
ll gcd(ll a, ll b) {if(a>b)swap(a,b) ;  if (a == 0)  return b; return gcd(b % a, a); }  
ll rll(ll  l , ll r){return rand()%(r-l+1) + l ;}
long long binpow(long long a, long long b) {long long res = 1; while (b > 0) { if (b & 1)res = res * a; a = a * a;b >>= 1; }return res;}
long long binpow(long long a, long long b, long long m) { a %= m;long long res = 1;while (b > 0) {if (b & 1)res = res * a % m; a = a * a % m;b >>= 1;} return res;}
//---------------------------end---------------------------------
 
 
 
 
 
 
 
 //-----------------------------------------------------------chori ka mall
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
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
 
//------------------------------------------------------------------------------------------------------------------------------------------
 
 
 
 
 
 int mulm(int a, int b, int mod){
  return (a*b)%mod;
}
 int addm (int a, int b, int mod){
  return (a+b)%mod;
 }
 
 
//  void heapPermutation(vector<int> &a, int size, int n)
// {
//     // if size becomes 1 then prints the obtained
//     // permutation
//     if (size == 1) {
//          // calling(a,n);
//       for(auto i:a)
//         cout<<i<<" ";cout<<endl;
//         return;
//     }
 
//     for (int i = 0; i < size; i++) {
//         heapPermutation(a, size - 1, n);
 
//         // if size is odd, swap 0th i.e (first) and
//         // (size-1)th i.e (last) element
//         if (size % 2 == 1)
//             swap(a[0], a[size - 1]);
 
//         // If size is even, swap ith and
//         // (size-1)th i.e (last) element
//         else
//             swap(a[i], a[size - 1]);
//     }
// }
 

 
 

 
bool comp(ll a,ll b){
  return a>b;
}
 
int check[100001];
void dfs (vector<vector<int>> arr, int n, int ind){
    if(check[ind])
        return ;
    check[ind]=1;
      for(auto a: arr[ind]){
        dfs(arr, n , a);
    }
}

bool man(pair<int,int> p1,pair<int,int> p2){

 if(p1.first != p2.first) return p1.first < p2.first;
 else return p1.second > p2.second;
}

ll solve()
{   
    //yhan par  sahi code ayega jo st pass karjaye  
    ll n,m;
    cin>>n>>m;
    ll dp[n+1]={0};
    dp[1] = 1;
    ll sum =1 ;
    for (ll i = 2; i <= n; ++i)
    {
        dp[i] = sum;
        for(ll j = 1;j*j<=i;j++){
          dp[i] += mulm(dp[j]  , i/j-i/(j+1) , m);
          dp[i]%=m;
          if(i/j != j  && j>1)
            dp[i]+= dp[i/j];
          dp[i]%=m;
        }
        sum +=dp[i];
        sum%=m;
    }
    cout<<dp[n];
    // for(ll i = 1;i<4;i++)
    //   cout<<dp[i];
       return 0;
 }
 
 
signed main(){
  fastio();
      #ifndef ONLINE_JUDGE
      // freopen("input.txt", "r", stdin);
      // freopen("output.txt", "w", stdout);
      freopen("Error.txt", "w", stderr);
      #endif
 
 
  ll test=1;
  // cin>>test ;
  // ll i=1;
  auto start1 = high_resolution_clock::now();
 while(test--){
  // cout<<"Case #"<<i++<<": "<< solve()<<"\n";
  solve();
  cout<<"\n";
 
 }
       auto stop1 = high_resolution_clock::now();
 auto duration = duration_cast<microseconds>(stop1 - start1);
      #ifndef ONLINE_JUDGE
      cerr << "Time: " << duration.count() / 1000 << endl;
      #endif
 
 return 0;
}
