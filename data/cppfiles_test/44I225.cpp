#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define    ll    long long int
#define pi              2*acos(0.0)
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a*b)/gcd(a,b)
#define mem(a,val)  memset(a, val, sizeof(a))
#define  fast()      ios :: sync_with_stdio(false); cin.tie(0);
map<ll,ll>mp,mk;
//map<string,ll>mp;
set<ll> s1,s2;
vector<ll> v,w;
//vector<char> w;[vector<pair<int,string>>v[100005];v[a].push_back({-b,s});]
string qq="",ss="",pp="",p,q,s;
char ch,ck;
ll m,n,i,j,l,r,x,t,y,u,g,h,mn,mx,d,z,c,f,e,k;
ll mod = (ll)pow(10,9)+7;

int main ()
{
    fast()
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        d=abs(n-m);
        if(n+m==0)
            cout<<0;
        else if(d==1)
            cout<<-1;
        else if(d==0)
            cout<<1;
        else
            cout<<2;
        cout<<"\n";
    }
}
