#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define int long long
using namespace __gnu_pbds;
using namespace std;

const long long inf = 1e18;
const long long Nmax =2e5+5;
const long long MOD = 998244353;

typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
long long ab(long long a)
{
    if(a<0)return -a;else return a;
}
int l[Nmax],r[Nmax],n,sz=1,id[Nmax],nxt[Nmax],dup[Nmax]={0},sdup[Nmax]={0},k;
char c[Nmax],str[Nmax];
void dfs1(int u)
{
    if(l[u]!=0)dfs1(l[u]);
    id[u]=sz;
    str[sz++]=c[u];
    if(r[u]!=0)dfs1(r[u]);
}
void dfs2(int u,int dep)
{
    if(dep>k)return;
    if(l[u]!=0)dfs2(l[u],dep+1);
    if(c[u]<nxt[id[u]]||dup[l[u]])
    {
        if(r[u]!=0)dfs2(r[u],dep+1);
        dup[u]=1;
        k--;
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input","r",stdin);
    long long t=1;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>c[i];
        for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
        dfs1(1);
        for(int i=1;i<=n;i++)cout<<str[i];cout<<endl;
        nxt[n]=-1;
        for(int i=n-1;i>=1;i--)
        {
            if(str[i]==str[i+1])nxt[i]=nxt[i+1];else nxt[i]=str[i+1];
        }
        dfs2(1,1);
        for(int i=1;i<=n;i++)sdup[id[i]]=dup[i];
        for(int i=1;i<=n;i++)
        {
            cout<<str[i];
            if(sdup[i])cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}
