/******************************************
* AUTHOR : RATHOD DHAVAL  *
* INSTITUTION : NIT SURAT *
******************************************/

#include <bits/stdc++.h>
#define int long long
#define N 100005
#define mod 1000000007
#define dd double
#define rep(i,a, n) for(int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define sortall(c) c.begin(),c.end()
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define PI 3.141592653589793238
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

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

void solve()
{
  int n;cin>>n;
  int b[n+1],a[n+1];
  rep(i,0,n)cin>>b[i];
  int sum= 0;
  rep(i,0,n)sum+=b[i];
  int z = (n*(n+1))/2;
   if(sum%z!=0){
    cout<<"NO\n";
    return;
   }
sum/=z;
  for(int i=0;i<n;i++){
    int x=  - b[(i+1)%n] + b[i];
    a[i] = sum - x;
    a[i]/=n;
    if(a[i]<=0){
        cout<<"NO\n";
        return;
    }
  }
  cout<<"YES\n";
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
 cout<<"\n";
}
 
main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--)
solve();
 
return 0;
}