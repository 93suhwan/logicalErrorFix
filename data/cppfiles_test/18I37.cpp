#include<bits/stdc++.h>
using namespace std;
#define MOD ll(1e9+7)
typedef long long ll;
ll mod_add(ll a, ll b, ll m){a=a % m; b=b%m; return (((a+b)%m) + m) % m;}
ll mod_mul(ll a, ll b, ll m){a=a%m; b=b%m; return (((a*b)% m) + m) % m;}
ll mod_sub(ll a, ll b, ll m){a=a%m; b=b%m; return (((a-b)%m) + m) % m;}

vector<ll> allfactors(ll n) {vector<ll>v; for (ll i = 2; i <= sqrt(n); i++) {if (n % i == 0) {v.push_back(i); if ((n / i) != i)v.push_back(n / i);}} 
      v.push_back(1);v.push_back(n); return v;}

void fastio()  {ios_base::sync_with_stdio(false); cin.tie(NULL); }

void solve()
{
   ll i,n,k;
   cin>>n>>k;
   ll a,b,j,vis[2*n+1]={};
   map<ll,ll> mp; 
   for(i=0;i<k;i++)
   {
       cin>>a>>b;
       vis[a]=1;
       vis[b]=1;
       mp[a]=b;
       mp[b]=a;
   }
   
   vis[0]=1;
   ll z=2*(n-k);
   
   vector<ll> v;
   for(i=1;i<2*n+1;i++)
   {
       if(!vis[i])
       v.push_back(i);
   }
   for(i=0;i<z/2;i++)
   {
       mp[v[i]]=v[i+z/2];
       mp[v[i+z/2]]=v[i];
   }
   for(i=1;i<2*z+1;i++)
   vis[i]=0;
   
   ll ans=0;
   for(i=1;i<2*n+1;i++)
   {
       if(vis[i])
       continue;
       vis[mp[i]]=1;
       vis[i]=1;
       for(j=1;j<2*n+1;j++)
       {
           if(i==j || mp[i]==j)
           continue;
           
           if( (j>i && j<mp[i])&& !(mp[j]>i && mp[j]<mp[i]) )
           ans++;
           
           if( (j<i && j>mp[i]) && !(mp[j]<i && mp[j]>mp[i]) )
           ans++;
       }
   }
   
   cout<<ans/2<<endl;
   
}
int main()
{
    fastio();
    ll _t;
   cin>>_t;
   while(_t--)
   {
       solve();
   }
    return 0;
}