// #include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cstring>
#include <random>
#include <bitset>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
typedef long long ll ;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define CS custom_hash
#define vt vector 
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define stoi stoll
#define all(v) (v).begin(),(v).end() 
#define rall(v) (v).rbegin(),(v).rend()                                           
#define mems(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)(x).size()
#define ar array
#define endl "\n" 
#define PI acos(-1) 
#define umap unordered_map
#define gmap gp_hash_table
#define ld long double 
#define seb(n) __builtin_popcountll(n) 
#define acc(v) accumulate(v.begin(),v.end(),0LL) 
#define LB lower_bound  
#define UB upper_bound 
// debugger credits: https://codeforces.com/blog/entry/68809 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
void adebug(int a[],int l,int r){
  for(int i=l;i<=r;i++){
    cerr << a[i] << " " ;
  }
  cerr << '\n' ;
}
template <typename T, typename V>
void mdebug(map<T,vector<V>>m){
  for(auto x:m){
    cerr << x.first << " : [ " ;
    for(auto c:x.second)
      cerr << c << " ";
    cerr << "]"<<'\n' ;
  }
}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//#pragma GCC optimize "trapv"
//template credits :William Lin(tmwilliamlin168)
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
template<class T> bool umin(T& a, const T& b) {
  return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
  return a<b?a=b, 1:0;
}
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d=stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template<class A> void read(vt<A>& x) {
  EACH(a, x)
    read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
  EACH(a, x)
    read(a);
}
string to_string(char c) {
  return string(1, c);
}
string to_string(bool b) {
  return b?"true":"false";
}
string to_string(const char* s) {
  return string(s);
}
string to_string(string s) {
  return s;
}
string to_string(vt<bool> v) {
  string res;
  FOR(sz(v))
    res+=char('0'+v[i]);
  return res;
}

template<size_t S> string to_string(bitset<S> b) {
  string res;
  FOR(S)
    res+=char('0'+b[i]);
  return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
    if(!f)
      res+=' ';
    f=0;
    res+=to_string(x);
  }
    return res;
}

template<class A> void write(A x) {
  cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
  write(h);
  write(t...);
}
void print() {
  write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
  write(h);
  if(sizeof...(t))
    write(' ');
  print(t...);
}
struct PH{
  size_t operator()(const pair<int,int>&x)const{
    size_t ans=0;
    for(int i=0;i<x.first;i++)
      ans+=x.second;
    return ans;
  }
};
// struct custom_hash {
//   static uint64_t splitmix64(uint64_t x) {
//     // http://xorshift.di.unimi.it/splitmix64.c
//     x += 0x9e3779b97f4a7c15;
//     x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//     x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//     return x ^ (x >> 31);
//   }
//   size_t operator()(uint64_t x) const {
//     static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//     return splitmix64(x + FIXED_RANDOM);
//   }
// };
// void DBG() {
//   cerr << "]" << endl;
// }
// template<class H, class... T> void DBG(H h, T... t) {
//   cerr << to_string(h);
//   if(sizeof...(t))
//     cerr << ", ";
//   DBG(t...);
// }
// // #ifdef _DEBUG
// #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
// // #else
// // #define dbg(...) 0
// // #endif

template<class T> void offset(ll o, T& x) {
  x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
  EACH(a, x)
    offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
  EACH(a, x)
    offset(o, a);
}
template<class T> void fk(T a) { 
  print(a) ;
  exit(0) ;
}
#define pf(n) return print(n)
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
//Syntax to create a min heap for priority queue
// priority_queue <T, vector<T>, greater<T>>pq ;

//make sure to clear the adjacency list for every test case 
// check mxN size 
//check if numbers are big use powl,sqrtl,builtin_popcountll()...... 
#define int ll 
long const M=1e9+7;
const ll INF =1e18;
const int mxN=1e6,di[4]={1,0,-1,0},dj[4]={0,-1,0,1};
void solve(){    
  int n,m;read(n,m) ;
  string s ;read(s) ;
  int mxx=0,mnx=0,mny=0,mxy=0 ;
  ar<int,2>ans={1,1} ;
  int x=0,y=0 ;
  EACH(c,s){
    if(c=='R') x++ ;
    if(c=='L') x-- ;
    if(c=='U') y++; 
    if(c=='D') y-- ;
    umax(mxx,x) ;
    umin(mnx,x) ;
    umax(mxy,y) ;
    umin(mny,y) ;
    int cx = 1+abs(mnx) ;
    int cy = 1+mxy  ;
    if(mxx-mnx+1>m){
      print(ans);
      return  ;
    }
    if(mxy-mny>n){
      print(ans) ;
      return ;
    }
    ans={cy,cx} ;
  }
  print(ans) ;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //cout << setprecision(20) << fixed ;
  int T=1;
  read(T);
  FOR(_,T){
    // write("Case #", _+1, ": ");
    solve();
  }
  return 0;
}

