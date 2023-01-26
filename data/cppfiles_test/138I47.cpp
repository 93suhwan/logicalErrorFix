#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
const int N=4e5+100;
int n,m,Q;
struct query{
    int x,id;
}q[N];
int ans[N];
int a[N],b[N];
struct node{
    int x,v;
}d[N];
int fa[N];
int c[N],val[N],l[N],r[N];
int Ans=0;
struct mer{
    int d,x,y;
}g[N];
int sum[N];inline int getf(int x){
    if(fa[x]==x) return x;
    return fa[x]=getf(fa[x]);
}
inline void merge(int x,int y){
    //x | y
    x=getf(x),y=getf(y);
    int ys=val[x]+val[y];
    int cols=c[x]+c[y];
    int news=sum[r[y]]-sum[r[y]-cols];
    //cerr<<"- "<<x<<" "<<r[y]<<" "<<d[x].x<<" "<<d[y].x<<" "<<cols<<" "<<ys<<" "<<news<<endl;
    Ans-=ys;Ans+=news;
    r[y]=r[y],l[y]=l[x];
    val[y]=news,c[y]=cols;
    fa[x]=y;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>Q;
    int tot=0;
    rep(i,1,n) cin>>a[i],d[++tot]=node{a[i],1};
    rep(i,1,m) cin>>b[i],d[++tot]=node{b[i],0};
    sort(d+1,d+1+tot,[](auto x,auto y){return x.x<y.x;});
    rep(i,1,Q) cin>>q[i].x,q[i].id=i;
    sort(q+1,q+1+Q,[](auto x,auto y){return x.x<y.x;});
    rep(i,1,tot) fa[i]=i,l[i]=r[i]=i;
    int cnt=0;
    rep(i,1,tot) {
        c[i]=d[i].v;
        if(c[i]) val[i]=d[i].x,Ans+=val[i];
    }
    for(int i=2;i<=tot;i++){
        g[i-1]=mer{d[i].x-d[i-1].x,i-1,i};
    }
    for(int i=1;i<=tot;i++){
        sum[i]=sum[i-1]+d[i].x;
    }
    sort(g+1,g+1+tot,[](auto x,auto y){return x.d<y.d;});
    int l=1;
    for(int i=1;i<=Q;i++){
        while(l<=tot&&g[l].d<=q[i].x){
           // cerr<<">> "<<i<<" "<<l<<" "<<g[l].x<<" "<<g[l].y<<endl;
            merge(g[l].x,g[l].y);
           // cerr<<"! "<<Ans<<endl;
            l++;
        }
        ans[q[i].id]=Ans;
    }
    rep(i,1,Q) cout<<ans[i]<<"\n";
}