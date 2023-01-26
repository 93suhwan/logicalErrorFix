/**
 *    author:  gary
 *    created: 12.09.2021 22:33:08
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=2e9;
typedef pair<int,int> mp;
const int MAXN=1e5+1;
int n,m;
struct edge{
    int u,v,w;
    bool operator < (edge ano){
        return w<ano.w;
    }
    edge(){
        u=v=w=INF;
    }
    edge(int A,int B,int C){
        u=A;
        v=B;
        w=C;
    }
};
bool f(edge A,edge B){
    return A.u!=B.u&&A.v!=B.u&&A.u!=B.v&&A.v!=B.v;
}
struct node{
    edge mn1,mn2,mn3,a1,a2,a3;
    node(){}
    node(edge a,edge b,edge c,edge d,edge e,edge f){
        tie(mn1,mn2,mn3,a1,a2,a3)=make_tuple(a,b,c,d,e,f);
    }
    vector<edge> get(){
        vector<edge> v;
        v.PB(mn1);
        v.PB(mn2);
        v.PB(mn3);
        v.PB(a1);
        v.PB(a2);
        v.PB(a3);
        return v;
    }
    node operator + (node ano){
        node rest;
        vector<edge> Mn;
        Mn.PB(mn1);
        Mn.PB(mn2);
        Mn.PB(mn3);
        Mn.PB(ano.mn1);
        Mn.PB(ano.mn2);
        Mn.PB(ano.mn3);
        sort(ALL(Mn));
        tie(rest.mn1,rest.mn2,rest.mn3)=make_tuple(Mn[0],Mn[1],Mn[2]);
        vector<edge> Tmp=this->get();
        vector<edge> Tmp2=ano.get();
        for(auto it:Tmp){
            if(f(rest.mn1,it)&&it<rest.a1) rest.a1=it;
            if(f(rest.mn2,it)&&it<rest.a2) rest.a2=it;
            if(f(rest.mn3,it)&&it<rest.a3) rest.a3=it;
        }
        for(auto it:Tmp2){
            if(f(rest.mn1,it)&&it<rest.a1) rest.a1=it;
            if(f(rest.mn2,it)&&it<rest.a2) rest.a2=it;
            if(f(rest.mn3,it)&&it<rest.a3) rest.a3=it;
        }
        return rest;
    }
};
LL answer=1e18;
void upd(node x){
    vector<edge> v=x.get();
    check_min(answer,1ll*v[0].w+v[1].w+v[2].w);
    for(auto it:v) for(auto it2:v) if(f(it,it2)) check_min(answer,1ll*it.w+it2.w);
}
struct DSU{
    stack<tuple<LL,bool,node,node,int,int,int,int> > inf;
    int siz[MAXN];
    node z[MAXN];
    int fa[MAXN];
    int root(int x){
        return fa[x]==x? x:root(fa[x]);
    }
    DSU(){
        rep(i,MAXN) fa[i]=i,siz[i]=1; 
    }
    void merge(int u,int v,edge x){
        // u=root(u);
        // v=root(v);
        if(siz[u]>siz[v]){
            swap(u,v);
        }
        fa[u]=v;
        siz[v]+=siz[u];
        z[v]=z[u]+z[v];
        z[v]=z[v]+node(x,edge(),edge(),edge(),edge(),edge());
        upd(z[v]);
    }
    void addedge(int u,int v,int w){
        if(root(u)!=root(v)){
            int ru=root(u),rv=root(v);
            inf.push(make_tuple(answer,1,z[ru],z[rv],siz[ru],siz[rv],ru,rv));
            merge(ru,rv,edge(u,v,w));
        }
        else{
            int r=root(u);
            inf.push(make_tuple(answer,0,z[r],z[r],siz[r],siz[r],r,r));
            z[r]=z[r]+node(edge(u,v,w),edge(),edge(),edge(),edge(),edge());
            upd(z[r]);
        }
    }
    void undo(){
        auto tmp=inf.top();
        inf.pop();
        LL oldans;
        bool ty;
        node z1,z2;
        int s1,s2;
        int u,v;
        tie(oldans,ty,z1,z2,s1,s2,u,v)=tmp;
        if(ty){
            fa[u]=u;
            fa[v]=v;
            siz[u]=s1;
            siz[v]=s2;
            z[u]=z1;
            z[v]=z2;
            answer=oldans;
        }
        else{
            z[u]=z1;
            answer=oldans;
        }
    }
}dsu;
const int N=1<<17;
vector<edge> tree[N+N];
void add(int a,int b,edge id,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return ;
    if(r<=b&&l>=a) {
        tree[now].PB(id);
        return ;
    }
    int mid=(l+r)>>1;
    add(a,b,id,now<<1,l,mid);
    add(a,b,id,now<<1|1,mid,r);
}
map<mp ,mp > M;
int t=1;
void travel(int now,int l=1,int r=N+1){
    if(l>=t) return ;
    for(auto it:tree[now]) dsu.addedge(it.u,it.v,it.w);
    if(l==r-1){
        printf("%lld\n",answer);
        for(auto it:tree[now]) dsu.undo();
        return ;
    }
    int mid=(l+r)>>1;
    
    travel(now<<1,l,mid);
    travel(now<<1|1,mid,r);
    
    for(auto it:tree[now]) dsu.undo();

}
int main(){
    scanf("%d%d",&n,&m);
    int q;
    rb(i,1,m) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u>v) swap(u,v);
        M[II(u,v)]=II(w,t);
    }
    cin>>q;
    for(auto ite=M.begin();ite!=M.end();ite++){
        dsu.addedge(ite->FIR.FIR,ite->FIR.SEC,ite->SEC.FIR);
    }
    printf("%lld\n",answer);
    for(auto ite=M.begin();ite!=M.end();ite++){
        dsu.undo();
    }
    rb(i,1,q){
        t++;
        int ty,u,v,w;
        scanf("%d",&ty);
        if(ty==0){
            scanf("%d%d",&u,&v);
            if(u>v) swap(u,v);
            auto ite=M.find(II(u,v));
            M.erase(ite);
        }
        else{
            scanf("%d%d%d",&u,&v,&w);
            if(u>v) swap(u,v);
            M[II(u,v)]=II(w,t);
        }
        for(auto ite=M.begin();ite!=M.end();ite++){
            dsu.addedge(ite->FIR.FIR,ite->FIR.SEC,ite->SEC.FIR);
        }
        printf("%lld\n",answer);
        for(auto ite=M.begin();ite!=M.end();ite++){
            dsu.undo();
        }
        if(i>20) break;
    }
    return 0;
}