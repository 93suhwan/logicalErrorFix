#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ull unsigned long long
#define bq priority_queue <int,vector<int>,less<int> > //大顶堆
#define sq priority_queue <int,vector<int>,greater<int> > //小顶堆
#define TT int t;cin>>t;while(t--)
typedef pair <int,int> pii;
const int N=1e6+10;

auto max(auto x,auto y){
	return x>y?x:y;
}
auto min(auto x,auto y){
	return x<y?x:y;
}
ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			y=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
void write(ll x,char c=0)
{
    if(x<0){
    	putchar('-');
    	x=-x;
	}
    char a[20],s=0;
    do{
    	a[++s]=x%10;
    	x=x/10;
	}while(x);
    do{
    	putchar(a[s]+'0');
	}while(--s);
    if(c){
        putchar(c);
    }
}
struct node{
    int next,to;
}tp[N];
int head[N],cnt1;
void add(int u,int v){
    cnt1++;
    tp[cnt1].next=head[u];
    tp[cnt1].to=v;
    head[u]=cnt1;
}
int cnt[N],dep[N],fa[N],l[N],r[N];

void dfs(int x){
    for(int i=head[x];i;i=tp[i].next){
        int v=tp[i].to;
        if(dep[v]) continue;
        fa[v]=x;
        dep[v]=dep[x]+1;
        dfs(v);
    }
}
void solve(){
    int n=read(),m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    int k=read();
    for(int i=1;i<=k;i++){
        int x=read(),y=read();
        l[i]=x,r[i]=y;
        cnt[x]++,cnt[y]++;
    }
    int ct=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]%2){
            ct++;
        }
    }
    if(ct){
        cout<<"NO"<<endl<<ct/2<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<=k;i++){
        vector <int> u(1,l[i]),v(1,r[i]);
        while(l[i]!=r[i]){
            if(dep[l[i]]>dep[r[i]]){
                u.push_back(fa[l[i]]);
                l[i]=fa[l[i]];
            }
            else{
                v.push_back(fa[r[i]]);
                r[i]=fa[r[i]];
            }
        }
        u.pop_back();
        for(auto i:u){
            write(i,' ');
        }
        for(int i=v.size()-1;i>=0;i--){
            write(v[i],' ');
        }
        cout<<endl;
    }
}
int main(){
    solve();
	return 0;
}
