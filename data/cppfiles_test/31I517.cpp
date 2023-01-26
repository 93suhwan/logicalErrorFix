/**
 *    Author : pradumn
**/
#include<bits/stdc++.h>
using namespace std;
#define Fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define M 1000000007
#define M2 998244353
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define pqueue priority_queue
#define all(v) v.begin(),v.end()
#define ft first
#define sc second
#define nl "\n"
#define mxe  *max_element
#define mne  *min_element
#define sz(x) (int)(x.size())
#define rev(x) reverse(all(x))
#define itr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define srt(x) sort(all(x))
#define bs(x,v) binary_search(all(x),v)
#define lb(x,v) lower_bound(all(x),v)
#define ub(x,v) upper_bound(all(x),v)
#define prt(x) cout<<x<<nl;
#define inf INT_MAX
#define ninf INT_MIN
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<vi> vvi;
typedef map<int,int> mi;
typedef vector<pi> vpi;
typedef set<int> si;


#ifndef ONLINE_JUDGE
#define deb(c) cerr << #c <<" : "; _print(c); cerr << endl;
#else
#define deb(c)
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ft); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void init_code()
{
  Fast_io;
  #ifndef ONLINE_JUDGE
    // freopen("Input.txt","r",stdin);
    // freopen("Output.txt","w",stdout);
    freopen("error.txt","w",stderr);
  #endif
}

// ll fac[100000001];ll fact(int n){fac[0]=1;fac[1]=1;for (int i = 2; i <=n; i++){fac[i]=i*fac[i-1];}return fac[n];}
// ll c(int n,int r){ fact(n);return fac[n]/(fac[r]*fac[n-r]);}
// void func();void kcst(){int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";func();}}
// bool isprime(int n){if(n==2){return 1;}else if(n%2==0){return 0;}else{for(int i=3;i*i<=n;i+=2){if(n%i==0){return 0;}}return 1;}}
// ll modularExponentiation(ll x,ll n,int m){if(n==0)return 1;else if(n%2 == 0) return modularExponentiation((x*x)%m,n/2,m);
// else return (x*modularExponentiation((x*x)%m,(n-1)/2,m))%m;}


/**************************Code starts from here**********************************/




// int dp[200001];
 
void func()
{
 int n;
 cin>>n;
 vi a(n);
 vi b(n);
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 b=a;
 rev(b);
 for(int i=0;i<n/2;i++)
{
b[i]=(-1*b[i]);
 
}
 if(n%2==1)
 {
  int l=lcm(a[0],a[n/2]);

  b[n/2]=(b[n/2]>0?l/abs(a[n/2]):-1*(l/abs(a[n/2])));
  b[0]=(b[0]>0?b[0]+l/abs(a[0]):b[0]-(l/abs(a[0])));
}

for(int i=0;i<n;i++)
{
  cout<<b[i]<<" ";
}
cout<<nl;
}


int main()
{
init_code();
double start1 = (double)clock();
int t=1;
cin>>t;
while(t--)
func();
double stop1 =(double)clock();
double duration = (stop1-start1)/CLOCKS_PER_SEC;
#ifndef ONLINE_JUDGE
cerr << "Time: " << duration << endl;
#endif
}