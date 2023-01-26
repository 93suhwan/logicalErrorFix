#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define double long double
#define mod 1000000007
#define iP pair<int,int>
#define iT pair<int,pair<int,int>>
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define inf 1e15
#define mod1 998244353
#define pi 3.141592653589793238
#define lcm(a,b) a*b/__gcd(a,b)
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define cmp complex<double>
int power(int x,int y){
    int res=1;
    while(y>0){
        if(y&1)res=(res*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return res;
}
void precompute(){
}
void cnt(set<int> adj[],int x,vector<bool> &vis,vector<int> &tmp){
    vis[x]=1;
    tmp.pb(x);
    for(auto it: adj[x]){
        if(!vis[it])cnt(adj,it,vis,tmp);
    }
}
void dfs(set<int> adj[],set<int> g[],int x,vector<bool> &vis,vector<int> &id){
    vis[x]=1;
    for(auto it: adj[x]){
        if(!vis[it]){
            g[id[x]].insert(id[it]);
            g[id[it]].insert(id[x]);
            dfs(adj,g,it,vis,id);
        }
    }
}
bool flag=1;
void check(set<int> adj[],int x,bool vis[],int col[],int &z,int &y,vector<int> &sz){
    if(col[x]==1)z+=sz[x];
    else y+=sz[x];
    vis[x]=1;
    for(auto it: adj[x]){
        if(col[it]==col[x]){
            flag=0;
        }
        if(!vis[it]){
            col[it]=!col[x];
            check(adj,it,vis,col,z,y,sz);
        }
    }
}
void solve(int tc){
    int n,m;
    cin>>n>>m;
    flag=1;
    set<int> g1[n],g2[n];
    for(int i=0;i<m;i++){
        int x,y;
        string str;
        cin>>x>>y>>str;
        if(str[0]=='i'){
           g1[x-1].insert(y-1); 
           g1[y-1].insert(x-1);
        }else{
           g2[x-1].insert(y-1);
           g2[y-1].insert(x-1);
        }
    }
    vector<bool> vis(n);
    vector<int> id(n);
    vector<int> sz;
    int cur=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vector<int> tmp;
            cnt(g2,i,vis,tmp);
            for(auto it: tmp)id[it]=cur;
            cur++;
            sz.push_back((int)tmp.size());
        }
    }
    set<int> adj[cur];
    for(int i=0;i<n;i++)vis[i]=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(g1,adj,i,vis,id);
        }
    }
    // for(auto it: id)cerr<<it<<" ";cerr<<"\n";
    // for(int i=0;i<cur;i++){
    //     for(auto it: adj[i])cerr<<it<<" ";
    //     cerr<<"\n";
    // }cerr<<"########\n";
    bool v[cur];
    int col[cur];
    memset(v,0,sizeof(v));
    memset(col,-1,sizeof(col));
    int ans=0;
    for(int i=0;i<cur;i++){
        if(!v[i]){
            col[i]=0;
            int x=0,y=0;
            check(adj,i,v,col,x,y,sz);
            if(!flag){
                cout<<"-1\n";
                return;
            }
            ans+=max(x,y);
        }
    }
    cout<<ans<<"\n";
}
int32_t main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);cout<<fixed;cerr.tie(NULL);cout.precision(16);
    int t=1,ctr=0;
    // precompute();
    cin>>t;
    while(t--){
        solve(ctr+1);
        ctr++;
    }
}