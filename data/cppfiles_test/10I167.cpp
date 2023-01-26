//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll gcd(ll a,ll b){
    return __gcd(a,b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int di[8]={1,-1,0,0,1,1,-1,-1};
int dj[8]={0,0,1,-1,1,-1,1,-1};
const ll N=2e5+5,MOD=1e9+7,oo=1e18;
const double PI=3.141592653589793238;
ll t,i,j,n,m,a[N],ans,k,b[N];
map<pair<ll,ll>,vector<ll> >idx;
map<ll,vector<ll> >mp;
vector<pair<ll,ll> >v;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){ans=0;idx.clear();mp.clear();v.clear();
        cin>>n>>k;
        for(i=1;i<=n;i++) cin>>a[i],mp[a[i]].push_back(i),b[i]=0;
        for(auto x:mp) ans+=min(k,x.second.size()*1ll);
        for(auto x:mp) idx[{-1*x.second.size(),x.first}]=x.second;
        ans/=k;
        for(i=1;i<=k;i++){
            m=0;
            for(auto &x:idx){
                b[x.second.back()]=i;
                x.second.pop_back();
                if(x.second.empty()) v.push_back({x.first.first,x.first.second});
                m++;
                if(m==ans) break;
            }
            for(auto x:v) idx.erase({x.first,x.second});
            v.clear();
        }
        for(i=1;i<=n;i++) cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}