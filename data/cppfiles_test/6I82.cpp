#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
mt19937_64 rnd;

const ll maxn=1e5+50;
const ll mod =1e9+7 ;
const ll base=1e13;
const ll magic=700;
/// you will be the best but now you just are trash
/// goal 1/7
vector<ll> adj[maxn];
ll p[maxn];
ll mo[maxn];
ll cnt[maxn];

void dosth()
{
    for (int i=1;i<maxn;i++)
    {
        for (int j=i;j<maxn;j+=i)
        {
            adj[j].pb(i);
        }
    }
    for (int i=2; i<maxn; i++)
    {
        if (p[i])
            continue;
        for (int j=i; j<maxn; j+=i)
        {
            p[j]=i;
        }
    }
    for (ll i=2; i<maxn; i++)
    {
        ll h=sqrt(i);
        if (h*h==i)
        {
            for (int j=i; j<maxn; j+=i)
            {
                cnt[j]-=base;
            }
        }
        else if (p[i]==i)
        {
            for (int j=i; j<maxn; j+=i)
            {
               cnt[j]++;
            }
        }
    }
    for (int i=1;i<maxn;i++)
    {
        if (cnt[i]<0)
        {

        }
        else
        {
            mo[i]=(cnt[i]%2?-1:1);
        }
        //if (i<20) cout <<mo[i]<<endl;
    }
}
ll val[maxn];
ll a[maxn];
vector<ll> gr[maxn];
ll sl[maxn];

ll dosth1(vector<ll> vt)
{
    memset(sl,0,sizeof(sl));
    for (auto to:vt)
    {
       for (auto h:adj[to]) sl[h]++;
    }
    ll h=1e5;
    for (int i=1;i<=h;i++)
    {
        sl[i]=(sl[i]*sl[i]);
    }
    ll ans=0;
    for (ll i=1;i<=h;i++)
    {
        ll nw=0;
        for (int j=i;j<=h;j+=i)
        {
            nw=(nw+mo[j/i]*sl[j]);
        }
        ans=ans+nw*i;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    dosth();
    ll n;
    cin>> n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        for (auto to:adj[a[i]])
        {
            gr[to].pb(i);
        }
    }
    ll h=1e5;
    for (int i=1;i<=h;i++)
    {
        if (gr[i].size()>=magic)
        {
           val[i]=dosth1(gr[i]);
        }
        else
        {
            for (auto to:gr[i]) for (auto to1:gr[i]) val[i]+=__gcd(to,to1);
          /*  if (gr[i].size())
            {
                 cout <<val[i]<<" "<<i<<" chk"<<endl;
            }*/
        }
    }
    ll ans=0;
    for (ll i=1;i<=h;i++)
    {
        ll nw=0;
        for (ll j=i;j<=h;j+=i)
        {
            nw=(nw+mo[j/i]*val[j]);
        }
       /* if(nw)
        {
            cout <<nw<<" "<<i<<" chk1"<<endl;
        }*/
       // if (i==6) cout <<val[i]<<" "<<val[12]<<" "<<val[18]<<" "<<p[1]<<endl;
        ans=ans+nw*i;
    }
    cout <<ans<<endl;
}
