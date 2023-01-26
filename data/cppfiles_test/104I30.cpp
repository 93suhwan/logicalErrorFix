#pragma GCC optimize(3,"Ofast","inline")
#include <set>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <random>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <cxxabi.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
//#define ll int
#define ft first
#define sd second
//#define endl '\n'
#define whiel while
#define pb push_back
#define MP make_pair
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define no cout<<"NO"<<endl
#define _no cout<<"no"<<endl
#define lowbit(a) ((a)&-(a))
#define yes cout<<"YES"<<endl
#define _yes cout<<"yes"<<endl
#define ull unsigned long long
#define nps fixed<<setprecision(10)<<
#define mem(a,k) memset(a,k,sizeof(a))
#define debug(x) cout<<#x<<"="<<x<<endl
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define DEBUG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define testmode freopen("C:\\Users\\pc\\Desktop\\test.in","r",stdin)
const ll N=1e6+10;
const ll mod1=1e9+7;
const ll mod2=998244353;
const ll base1=1610612741;
const ll INF=0x3f3f3f3f3f;
const ll inf=9223372036854775807;
const ld lne=2.71828182845904523536028747;
const double T0=1e5;
const double D=1-3e-3;
const double eps=1e-9;
const double T_end=1e-4;
const double PI=3.1415926535897932384626;
const double Wythoff=(1.0+sqrt(5.0))/2.0;
using namespace std;
int ddir[2][2]={{0,1},{1,0}};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int dir3[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int dii[8][2]={{1,2},{-1,2},{2,1},{-2,1},{-1,-2},{1,-2},{-2,-1},{2,-1}};
//mt19937_64 rng(random_device{}());
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a,ll b){return __gcd(a,b);}
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
bool BashGame(ll n,ll k){if(n%(k+1)==0)return false;else return true;}
ll rnd(ll l,ll r){ll ans=uniform_int_distribution<ll>(l,r)(rng);return ans;}
ll quickpow(ll a,ll b){ll res=1;while(b>0){if(b&1)res=res*a;a=a*a;b>>=1;}return res;}
//void printname(auto x){cout<<abi::__cxa_demangle(typeid(x).name(),NULL,NULL,NULL)<<endl;}
//double rndb(double l,double r){double ans=uniform_real_distribution<double>(l,r)(rng);return ans;}
bool WythoffGame(ll n,ll m){double c=(double)(abs(m-n));ll p=(ll)(c*Wythoff);return (p!=min(m,n));}
ll quickmodpow(ll a,ll b,ll m){a%=m;ll res=1;while(b>0){if(b&1)res=res*a%m;a=a*a%m;b>>=1;}return res;}
double psqrt(double x,double y,double xx,double yy){double res=((x-xx)*(x-xx)+(y-yy)*(y-yy));return res;}
double ssqrt(double x,double y,double xx,double yy){double res=sqrt(psqrt(x,y,xx,yy));return res;}
ll t,n,m,k,tt,tp,sum,ans,res,cnt;
pll a[N];
ll b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    //IO
    cin>>t;
    while(t--)
    {
        res=0;
        cin>>n>>m;
        rep(i,1,n)
        {
            ll x,y;
            cin>>x>>y;
            ll m1=max(m-y,0ll);
            ll m2=min(m,x);
            a[i]={m1,m2};
            res+=y-m-x+m1+m2;
        }
        rep(i,1,n)
        {
            ll w=min(max(res,0ll)/2,a[i].sd-a[i].ft);
            res-=w/2;
            b[i]=a[i].sd-w;
        }
        cout<<abs(res)<<endl;
        rep(i,1,n)cout<<b[i]<<" "<<m-b[i]<<endl;
    }
}
