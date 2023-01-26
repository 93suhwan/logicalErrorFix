#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define scan(a,n) for(long long int index=0;index<n;index++) cin>>a[index];
#define print(a,n) for(long long int index=0;index<n;index++) cout<<a[index]<<" ";cout<<endl;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define vi vector<int>
#define vli vector<long long int>
#define vlli vector<pair<long long int,long long int>>
#define all(n) n.begin(),n.end()
#define rall(n) n.rbegin(),n.rend()


ll sub(ll x,ll y){  ll z=(x-y)%mod;if(z<0) z+=mod; return z;}
ll add(ll x,ll y){  return (x+y)%mod;}
ll mul(ll x,ll y){  return (x*y)%mod;}
ll power(ll x, ll y) {ll res = 1; x %= mod;
 while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}

 
int main() {
  fast;
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll t=1;
  cin>>t;
  while(t--){  
    ll n;
    cin>>n;
    ll a[n],b[n],i;
    scan(a,n);
    scan(b,n);
    if(n==1){
      cout<<1<<endl;
      continue;
    }
    string ans="";
    for(i=0;i<n;i++) ans+='0';
      // cout<<ans<<endl;
    vlli v,vv;
    for(i=0;i<n;i++){
      v.pb(mp(a[i],i));
      vv.pb(mp(b[i],i));
    }
    sort(rall(v));
    sort(rall(vv));
    bool vs[n]={},vss[n]={};
    ll c[n]={},d[n]={};
    for(i=0;i<n;i++){
      c[v[i].ss]=i;
      d[vv[i].ss]=i;
    }
    // print(c,n);
    // print(d,n);
    ans[v[0].ss]='1';
    ans[vv[0].ss]='1';
    ll j=0,k=0;
    j=d[v[0].ss];
    k=c[vv[0].ss];
    while(1){
      ll jj=j,kk=k;
      for(i=0;i<=j;i++){
        k=max(k,c[vv[0].ss]);
      }
      for(i=0;i<=k;i++){
        j=max(j,d[v[0].ss]);
      }
      // cout<<j<<" "<<k<<endl;
      if(jj==j && kk==k) break;
    }
    for(i=0;i<=j;i++){
      ans[v[i].ss]='1';
    }
    for(i=0;i<=k;i++){
      ans[vv[i].ss]='1';

    }
    cout<<ans<<endl;

    

    
    
  }
return 0;    
 }    