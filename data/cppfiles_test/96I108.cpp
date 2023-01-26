/*
      ___           ___           ___           ___           ___           ___           ___          _____          ___           ___           ___
     /  /\         /__/\         /  /\         /__/\         /  /\         /__/\         /  /\        /  /::\        /  /\         /  /\         /  /\
    /  /::\       |  |::\       /  /::\        \  \:\       /  /::\       |  |::\       /  /::\      /  /:/\:\      /  /::\       /  /::\       /  /::\
   /  /:/\:\      |  |:|:\     /  /:/\:\        \__\:\     /  /:/\:\      |  |:|:\     /  /:/\:\    /  /:/  \:\    /  /:/\:\     /  /:/\:\     /  /:/\:\
  /  /:/  \:\   __|__|:|\:\   /  /:/  \:\   ___ /  /::\   /  /:/~/::\   __|__|:|\:\   /  /:/~/::\  /__/:/ \__\:|  /  /:/  \:\   /  /:/  \:\   /  /:/  \:\
 /__/:/ \__\:\ /__/::::| \:\ /__/:/ \__\:\ /__/\  /:/\:\ /__/:/ /:/\:\ /__/::::| \:\ /__/:/ /:/\:\ \  \:\ /  /:/ /__/:/ \__\:\ /__/:/ \__\:\ /__/:/ \__\:\
 \  \:\ /  /:/ \  \:\~~\__\/ \  \:\ /  /:/ \  \:\/:/__\/ \  \:\/:/__\/ \  \:\~~\__\/ \  \:\/:/__\/  \  \:\  /:/  \  \:\ /  /:/ \  \:\ /  /:/ \  \:\ /  /:/
  \  \:\  /:/   \  \:\        \  \:\  /:/   \  \::/       \  \::/       \  \:\        \  \::/        \  \:\/:/    \  \:\  /:/   \  \:\  /:/   \  \:\  /:/
   \  \:\/:/     \  \:\        \  \:\/:/     \  \:\        \  \:\        \  \:\        \  \:\         \  \::/      \  \:\/:/     \  \:\/:/     \  \:\/:/
    \  \::/       \  \:\        \  \::/       \  \:\        \  \:\        \  \:\        \  \:\         \__\/        \  \::/       \  \::/       \  \::/
     \__\/         \__\/         \__\/         \__\/         \__\/         \__\/         \__\/                       \__\/         \__\/         \__\/

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define endl '\n'
#define pii pair<ll,ll >
#define F first
#define S second
#define ld long double

using namespace std;
using namespace __gnu_pbds;

//typedef tree<ll , null_type , less_equal<ll> ,rb_tree_tag ,tree_order_statistics_node_update >ordered_set;

const int MOD=1e9+7;
const int  N=4e5+7;
const ll INF= 1e18+10;

long long po(ll x,ll y)
{
    ll ans=1;
    while(y){
        if(y & 1) ans=(ans*x);//%MOD;
        y/=2;
        x=(x*x);//%MOD;
    }
    return ans;
}

struct qua{ll F,S,T,Q,Z;};

ll n,m;
ll a[N];
ll seg[N];
ll pref[N],suf[N];
vector<qua>v;

void build(ll v,ll l,ll r)
{
    if(l==r){
        seg[v]=1;
        pref[v]=1;
        suf[v]=1;
        return;
    }
    ll m=(l+r)/2;
    build(v*2+1,l,m);
    build(v*2+2,m+1,r);
    if(a[m+1]>=a[m]){
        ll f=pref[v*2+2]+suf[v*2+1];
        seg[v]=seg[v*2+1]+seg[v*2+2]-((pref[v*2+2]*(pref[v*2+2]+1))/2 + (suf[v*2+1]*(suf[v*2+1]+1))/2);
        seg[v]+=(f*(f+1)/2);
        pref[v]=(pref[v*2+1]==m-l+1 ? pref[v*2+1]+pref[v*2+2] : pref[v*2+1]);
        suf[v]=(suf[v*2+2]==r-m ? suf[v*2+2]+suf[v*2+1] : suf[v*2+2]);
    }
    else{
        pref[v]=pref[v*2+1];
        suf[v]=suf[v*2+2];
        seg[v]=seg[v*2+1]+seg[v*2+2];
    }
}

void upd(ll v,ll l,ll r,ll pos)
{
    if(l==r){
        return;
    }
    ll m=(l+r)/2;
    if(m>=pos) upd(v*2+1,l,m,pos);
    else upd(v*2+2,m+1,r,pos);
    if(a[m+1]>=a[m]){
        ll f=pref[v*2+2]+suf[v*2+1];
        seg[v]=seg[v*2+1]+seg[v*2+2]-((pref[v*2+2]*(pref[v*2+2]+1))/2 + (suf[v*2+1]*(suf[v*2+1]+1))/2);
        seg[v]+=(f*(f+1)/2);
        pref[v]=(pref[v*2+1]==m-l+1 ? pref[v*2+1]+pref[v*2+2] : pref[v*2+1]);
        suf[v]=(suf[v*2+2]==r-m ? suf[v*2+2]+suf[v*2+1] : suf[v*2+2]);
    }
    else{
        pref[v]=pref[v*2+1];
        suf[v]=suf[v*2+2];
        seg[v]=seg[v*2+1]+seg[v*2+2];
    }
}

void get(ll ve,ll segl,ll segr,ll l,ll r)
{
    //cout<<ve<<endl;
    if(segl>r||segr<l) return ;
    if(segl>=l&&segr<=r){
        v.pb({seg[ve],pref[ve],suf[ve],segl,segr});
        return;
    }
    ll m=(segl+segr)/2;
    get(ve*2+1,segl,m,l,r);
    get(ve*2+2,m+1,segr,l,r);
}

void solve()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    build(0,1,n);
    while(m--){
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==1){
            a[y]=z;
            upd(0,1,n,y);
        }
        else{
            get(0,1,n,y,z);
            for(ll i=0;i<v.size();i++){
                cout<<v[i].F<<' '<<v[i].S<<' '<<v[i].T<<' '<<v[i].Q<<' '<<v[i].Z<<endl;
            }
            //cout<<endl;
            qua ans=v[0];
            for(ll i=1;i<v.size();i++){
                ll m=v[i].Q;
                m--;
                if(a[m+1]>=a[m]){
                    ll f=v[i].S+ans.T;
                    ans.F=ans.F+v[i].F-((v[i].S*(v[i].S+1))/2 + (ans.T*(ans.T+1))/2);
                    ans.F+=(f*(f+1)/2);
                    ans.S=(ans.S==(ans.Z-ans.Q+1) ? ans.S+v[i].S : ans.S);
                    ans.T=(v[i].T==(v[i].Z-v[i].Q+1) ? v[i].T+ans.T : v[i].T);
                    ans.Z=v[i].Z;
                }
                else{
                    //cout<<"shit"<<endl;
                    ans.T=v[i].T;
                    ans.F+=v[i].F;
                    ans.Z=v[i].Z;
                }
                //cout<<ans.F<<' '<<ans.S<<' '<<ans.T<<' '<<ans.Q<<' '<<ans.Z<<endl;
            }
            cout<<ans.F<<endl;
            v.clear();
        }
    }
}

int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);freopen(".out","w",stdout);
    int t=1;
    //cin>>t;
    while(t--){ solve();}
    return 0;
}
