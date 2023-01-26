#include<iostream>
#include<string>
using ll=long long;
#include <utility>
using namespace std;
#include<sstream>
#include<numeric>
ll mod=1e9+7;
#define filein freopen("input.txt","r",stdin)
#define fileout  freopen("output.txt","w",stdout)
#include<bits/stdc++.h>
#define ya  cout<<"YES"<<endl;
#define no  cout<<"NO"<<endl;
#define pb push_back
#define lst bi.back()
#define fast_cin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(bi) bi.begin(),bi.end()
#define printv(bi) for(i=0;i<bi.size();i++)cout<<bi[i]<<' ';cout<<endl;
#define see(x) cout<<x<<endl;
ll inf=1e10;
inline ll lcm(ll a,ll b)
{
    ll    y=(a*b)/__gcd(a,b);
    return y;
}
//iterateinaset for(auto it:s){cout<<it<<endl;}
//for searching a key:
//[auto it=mp.find(x);if(it!=mp.end())]
//for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
//*____________________________*
//bool cmp(pair<ll, ll>& a,
//         pair<ll, ll>& b)
//{
//    return a.second > b.second;
//}
//*______________________________*
ll myXOR(ll x, ll y)
{
    return (x | y) & (~x | ~y);
}
int main()
{
    fast_cin;
    ll x,i,k,y,j=0,t,m=1,n;
    vector<ll>vc,bi,b;
    map<ll,ll>mp,mp1;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0; i<n; i++)
        {
            cin>>x;
            bi.pb(x);
            mp[x]=i;
            vc.pb(x);
        }
        sort(all(vc));
        ll sum=0;
        for(i=0; i<n; i++)
        {
            if(mp1[vc[i]]==0)
            {
                mp[vc[i]]=1;
                x=mp[vc[i]];
                ll cnt=i+1;
                if(x+1==n)
                {
                    if(i!=n-1)
                    {
                        sum++;
                    }
                }
                else
                {
                    for(j=x+1; j<n; j++)
                    {
                        if(bi[j]==vc[cnt])
                        {
                            mp1[bi[j]]=1;
                            mp1[vc[cnt]]=1;
                            cnt++;
                        }
                        else
                        {
                            mp1[bi[j]]=1;
                            sum++;
                            break;
                        }
                    }
                }
            }
        }
        if(sum<=k)
            ya
            else
                no
                //see(sum)
                vc.clear();
        bi.clear();
        mp.clear();
        mp1.clear();
    }
}

