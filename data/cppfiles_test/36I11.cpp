#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define double long double
#define ULL unsigned long long
#define PUI pair<ULL,int>
#define FI first
#define PII pair<int,int>
#define SE second
const double eps=1e-10,pi=acos(-1);
const int N=2e5+10,M=10000+10,ha=131,INF=0x3f3f3f3f,mod=998244353;
int n;
int de[N];
int d[N];
bool vis[N];
vector<int>G[N];
int num[N];
LL ans[N];
bool check(int k){
    for(int i=1;i<=n;i++)d[i]=de[i],vis[i]=1,num[i]=0;
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(d[i]==1){
            vis[i]=0;
            q.push(i);
        }
    }
    int g=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        int flag=0;
        int fa;
        for(int y:G[x]){
            if(vis[y]){
                d[y]--;
                flag=1;
                fa=y;
                if(d[y]==1){
                    vis[y]=0;
                    q.push(y);
                }
            }
        }
        if(num[x]%k==0){
            g=__gcd(num[x],g);
            num[fa]++;
        }
        else if((num[x]+flag)%k==0){
            g=__gcd(num[x]+flag,g);
        }
    }
    return g==k;
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)de[i]=0;
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        de[u]++,de[v]++;
        G[u].PB(v);
        G[v].PB(u);
    }
    LL s=1;
    for(int i=1;i<n;i++)s=s*2%mod;
    for(int i=2;i<=n;i++){
        if((n-1)%i==0){
            ans[i]=check(i);
            s-=ans[i];
            if(s<0)s+=mod;
        }
        else ans[i]=0;
    }
    ans[1]=s;
    for(int i=1;i<=n;i++)printf("%lld%c",ans[i],i==n?'\n':' ');
}
int main()
{
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

