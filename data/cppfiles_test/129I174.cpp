#include<bits/stdc++.h>
using namespace std;
 
#define ll            long long int
#define di(x)         ll x;cin>>x
#define dia           di(a)
#define din           di(n)
#define dim           di(m)
#define dik           di(k)
#define dit           di(t)
#define dix           di(x)
#define diy           di(y)
#define diz           di(z)
#define veci          vector<int>
#define vecll         vector<ll>
#define pb            push_back
#define po            pop_back
#define all(x)        x.begin(),x.end()
#define forl(i,l,u,m)   for(ll i=l; i<u; i+=m)
#define for1(i,l,u)    forl(i,l,u,1)
#define fors(n)       forl(i,0,n,1)
#define el            <<"\n"
#define PI            3.14159265359
#define MOD             int(1e9+7)
typedef pair<ll,ll> pairs;
/*****************************/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);                                                    
    dit;
    while(t--)
    {  din;
    ll a[n];  bool b[n+1]={false}; vecll v,v1;
     fors(n) {cin>>a[i]; if(a[i]<=n && a[i]>0) b[a[i]]=true; else v.pb(a[i]);}
     sort(all(v));
     for1(i,1,n+1) { if(b[i]==false) v1.pb(i);}
     if(v1.size()!=v.size()) cout<<"-1" el;
     else{ ll c=0;
         fors(v.size())
         {  
             if(v[i]<=2*v1[i]) { c=1; break;}
            
         }
          if(c==1) cout<<"-1" el;
             else cout<<v.size() el;
     }
    }
}