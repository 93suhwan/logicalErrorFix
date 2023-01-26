#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll md = 1e9+7;
ll inf=1e16;
#define pb push_back
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int>> vii;
typedef vector<pair<ll, ll>> vll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unsigned long long ull;
#define mp make_pair
#define ull unsigned long long
#define pqs priority_queue<int,vi,greater<int> >
#define setbits(x) __builtin_popcountll(x)
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int> ,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
ll powmod(ll a,ll n){ll r=1;while(n>0) {if(n&1LL) r=(r * a) % md;a =( a * a) % md; n >>= 1LL;}return r;}
ll __lcm(ll a,ll b){return a/__gcd(a,b)*b;}
ll nCr(ll n,ll r){if(n<r)return 0;if(r>n-r)r=n-r;ll ans=1;ll i;for(i=1;i<=r;i++) {ans*= n-r+i;ans/=i;}return ans;}
int k;
ll dis(vi& v){
ll sum=0;
int pos=0;
int n=v.size();
if(n<k){
    return v[n-1];
}

int pick=(n-1)%k;
sum+=2*v[pick];
pos=pick;
while(pos<n-1){
    pos+=k;
    if(pos>=n-1)sum+=v[n-1];
    else sum+=1LL*v[pos]*2LL;
}
return sum;
}


int main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t;cin>>t;
while(t--){
int n;cin>>n>>k;
int arr[n];
for(int i=0;i<n;i++)cin>>arr[i];
sort(arr,arr+n);
vi v,vv;
v.pb(0);
vv.pb(0);
for(int i=0;i<n;i++){
    if(arr[i]<0)v.pb(-arr[i]);
    if(arr[i]>0)vv.pb(arr[i]);
}
sort(v.begin(),v.end());
int n1=v.size();
int n2=vv.size();
cout<<dis(v)+dis(vv)+min(v[n1-1],vv[n2-1])<<"\n";

}
return 0;    
}








