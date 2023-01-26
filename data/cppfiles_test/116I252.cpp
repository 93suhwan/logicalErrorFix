#include <bits/stdc++.h>
#include <vector>
#include<iomanip>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include<cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include<cstdio>

using namespace std;
const int maxn= 5e5+100;
const long long mod=1e9+7;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int>pii;

#define INF 1e18
#define rep(i, a, n) for(ll i = a; i <= n; i ++)
#define pre(i, n, a) for(ll i = n; i >= a; i --)
#define IOS ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define mem(a,t) memset(a,t,sizeof(a))
#define debug(a) cout<<#a<<"="<<a<<endl;
#define pb(a)  push_back(a)
#define lson root<< 1
#define rson root << 1 | 1
#define setbit(x,y)  x|=(1<<y)
#define clrbit(x,y)  x&=~(1<<y)
#define reversebit(x,y)  x^=(1<<y)
#define getbit(x,y)   ((x) >> (y)&1)

inline ll read(){ ll f = 1; ll x = 0;char ch = getchar();while(ch>'9'||ch<'0') {if(ch=='-') f=-1; ch = getchar();}while(ch>='0'&&ch<='9') x = (x<<3) + (x<<1) + ch - '0',  ch = getchar();return x*f; }

struct node{
    ll sum;
    int id;
    bool operator <(const node &x)const
    {
        return sum > x.sum;
    }
};



int main(){
IOS;
ll t;
cin>>t;
while(t--){
ll n;
cin>>n;
ll dp[n+10][2]={0};
dp[0][0]=1;
rep(i,1,n)
{
    ll x;
    cin>>x;
    x++;
    dp[x][0]+=dp[x][0]+dp[x-1][0],dp[x][0]%=mod;
    dp[x][1]+=dp[x][1],dp[x][1]%=mod;
    if(x>=2)dp[x][1]+=dp[x-2][0],dp[x][1]%=mod;
    dp[x+2][1]+=dp[x+2][1],dp[x+2][1]%mod;
}

ll ans=0;
//rep(i,1,n)
//{
//    if(vis[a[i]])continue;
//    vis[a[i]]=1;
//    ans+=(dp[a[i]][1]+dp[a[i]][0])%mod;
//    ans%=mod;
//}

rep(i,1,n+1)
{
    ans+=(dp[i][1]+dp[i][0]);
    ans%=mod;
}
cout<<ans<<'\n';

}

return 0;
}
