#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pb push_back 
#define mk make_pair

ll m=1000000007; 
ll fact(ll n); 

int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        int q = a / m; 
        int t = m; 
  
        m = a % m, a = t; 
        t = y; 
  
        y = x - q * y; 
        x = t; 
    } 
  
    if (x < 0) 
       x += m0; 
  
    return x; 
} 


ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res%m * i%m)%m; 
    return res; 
} 
 vector<bool> mark;
  vector<bool> pmark;
  ll c;
 
void dfs(vector<vector<ll>> &v, ll node) {
    if (pmark[node]) {
      return;
    }
    if (mark[node]) {
      c++;
      return;
    }
    mark[node] = true;
 
    // Try all outgoing edges.
    for (ll i=0;i<v[node].size();i++) {
      dfs(v,v[node][i]);
    }
 
    pmark[node] = true;
    mark[node] = false;
  }


int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll t;
        cin>>t;
        while(t--){
            ll n,an=0,m;
            string s;
            cin>>n>>m;
            ll a[n];
             vector<ll>vv;
            ll b[n]={0};
            for(ll i=0;i<n;i++){
                cin>>a[i];
                ll x;
                if(a[i]-1<=i){
                    x=i-(a[i]-1);
                    b[x]++;
                }else{
                    x=n-(a[i]-1-i);
                    b[x]++;
                }
            }
            
            // for(ll i=0;i<n;i++)cout<<b[i]<<" ";
            
            for(ll i=0;i<n;i++){
                ll x=n-b[i];
                ll y=x/2,z=x-1;
                if(x%2==1)y++;
                if(m>=z){
                    vv.pb(i);
                    continue;
                }
                if(m>=y){
                    vector<vector<ll>>v(n+1);
            
                    for(ll j=0;j<n;j++){
                    ll x=(a[j]+i)%n;
                    
                    ll xx;
                if(a[j]-1<=j){
                    xx=n-(a[j]-1);
                   
                }else{
                    xx=n-(a[j]-1-j);
                  // b[x]++;
                }
                //cout<<x<<" ";
                    if(xx!=i)    
                    v[a[j]].pb(a[x]);
                    }
                    
                    mark = vector<bool>(v.size(), false);
                    pmark = vector<bool>(v.size(), false);
                    c=0;
                    for(ll ii=0;ii<v.size();ii++){
                        dfs(v,ii);
                    }
                    ll z=x-c;
                    if(m>=z){
                        vv.pb(i);
                    }
                }
            }
            cout<<vv.size()<<" ";
            for(ll i=0;i<vv.size();i++)cout<<vv[i]<<" ";
            cout<<endl;
        }
    return 0;
}