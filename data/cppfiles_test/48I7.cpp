#pragma GCC optimise("0fast")

#include <bits/stdc++.h>  
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> omset;

#define fi(i,a,b) for(ll i = (a); i < (b); i++)
#define fr(i,a,b) for(ll i = (a); i >=(b); i--)
#ifndef ONLINE_JUDGE    
#define dbg(x) cerr<<#x<<" "; _print(x); cerr<<endl
#else
#define dbg(x);  
#endif    
#define pb push_back
#define inf 2e15
#define inp(arr,z) for(int i=0; i<z; i++)cin>>arr[i]
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()

void _print(ll x){cerr<<x;}  
void _print(string x){cerr<<x;}
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";}
ll M= 1e9 +7;

ll sum(v64 * a){ll s=0; for (auto x : *a){s+=x;} return s;}
ll power(ll a , ll b ){ll r=1;ll o=a;if(b<=0)return 1;
  while(b!=0){if(b%2)r=(r*o)%M,b--; else {b/=2; o=(o*o)%M;}}
   return r;}

//-----------------------------------------------------------------------------------
void solve();

int main(){

fast_cin();
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif

ll t=1;
cin >> t;
while (t--)
{solve();cout<<"\n";}
// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
return 0;
}

//---------------------------------------------------------------------------------------






void solve(){
ll n; cin>>n;
omset a;
ll tot=0;ll ans=0;
bool f=0;

while(n--){

  ll x; cin>>x;
  if(a.find(x)!= a.end())f=1;
ans+= a.size()- a.order_of_key(x+1);
a.insert(x);
}
// dbg(ans);
if(ans%2==0 ||f)cout<<"YES";
else cout<<"NO"; 

}
