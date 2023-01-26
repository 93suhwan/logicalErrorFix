#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define endl "\n"
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    else if(b==1)return a;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        multiset<ll>st;
        vector<pair<ll,pair<ll,ll>>>v;
        for(ll i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            st.insert(x);
            st.insert(y);
            v.pb({abs(x-y),{x,y}});
        }
        sort(v.begin(),v.end());
        for(ll i=v.size()-1;i>=0;i--)
        {
            ll x=v[i].second.first;
            ll y=v[i].second.second;
            auto it1=st.find(x);
            st.erase(it1);
            auto it2=st.find(y);
            st.erase(it2);
            if(x==y)
            {
                cout<<x<<in<<y<<in<<x<<endl;
                continue;
            }
            for(ll j=x;j<=y;j++)
            {
                if(st.find(j)==st.end())
                {
                    cout<<x<<in<<y<<in<<j<<endl;
                }
            }
        }
    }
    return 0;
}

