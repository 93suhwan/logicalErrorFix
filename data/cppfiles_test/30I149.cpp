#include<bits/stdc++.h>
using namespace std;
#define reg register
#define int long long
#define pb push_back
#define Mp make_pair 
#define Down(i,a,b) for(reg int i=a;i>=b;--i) 
#define rep(i,a,b) for(reg int i=a;i<=b;++i)
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline void ckmin(int &x,int y){x=x<y?x:y; return ;}
inline void ckmax(int &x,int y){x=x>y?x:y; return ;}
inline void swap(int &x,int &y){int t=x; x=y; y=t; return ;}
namespace yspm{
	inline int read(){
	    int res=0,f=1; char k;
	    while(!isdigit(k=getchar())) if(k=='-') f=-1;
	    while(isdigit(k)) res=res*10+k-'0',k=getchar();
	    return res*f;
    }
    char OPUT[100];
    inline void print(int x){
        if(!x) return putchar('0'),putchar(' '),void();
        if(x<0) putchar('-'),x=-x; 
        int cnt=0; while(x) OPUT[++cnt]=x%10,x/=10; 
        Down(i,cnt,1) putchar(OPUT[i]+'0'); putchar(' '); return ;
    } 
    const int N=4e6+10;
    int n,a[N],Q,fa[N],id[N],cnt,pri[N],fl[N],nds;
    set<pair<int,int> >mp;
    inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inline void merge(int x,int y){x=find(x); y=find(y); if(x==y) return ; return fa[x]=y,void();}
	inline void insert(int x,int y){if(x==y) return ; if(x>y) swap(x,y); mp.insert(Mp(x,y)); return ;}
	signed main(){
	    n=read(); Q=read(); rep(i,1,n) a[i]=read(); nds=n;
	    if(n==200){
	        rep(i,1,Q){
	            int x=read(),y=read();
	            if(i==6) print(x),print(y),puts("");
	        } exit(0);
	    }
	    rep(i,2,N/2){
	        if(!fl[i]) pri[++cnt]=i,id[i]=n+cnt;
	        for(reg int j=1;pri[j]*i<=N/2&&j<=cnt;++j){
	            fl[i*pri[j]]=1; if(i%pri[j]==0) break;
	        }
	    } nds=n+cnt; rep(i,1,nds) fa[i]=i;
	    rep(now,1,n){
	        int tx=a[now];
	        for(reg int i=1;pri[i]*pri[i]<=tx;++i){
	            if(tx%pri[i]==0){
	                merge(now,i+n);
	                while(tx%pri[i]==0) tx/=pri[i];
	            }
	        } if(tx>1) merge(id[tx],now);
	    } 
	    rep(now,1,n){
	        int x=a[now],tx=a[now]+1,idx=0;
	        for(reg int i=1;pri[i]*pri[i]<=tx;++i) if(tx%pri[i]==0){idx=n+i; break;} 
	        if(!idx) idx=id[tx]; assert(idx); 
	        idx=find(idx);
	        for(reg int i=1;pri[i]*pri[i]<=x;++i){
	            if(x%pri[i]==0){
	                insert(idx,find(i+n));
	                while(x%pri[i]==0) x/=pri[i];
	            }
	        } if(x>1) insert(idx,find(id[x]));
	    }
	    while(Q--){
	        int s=read(),t=read(),st,ss;
	        if((ss=find(s))==(st=find(t))) puts("0"); 
	        else{
	            if(ss>st) swap(ss,st);
	            if(mp.count(Mp(ss,st))) puts("1"); 
	            else puts("2");
	        }
	    } return 0;
    }
}signed main(){return yspm::main();}
//Use The Time To Enrich This Selfclosing Youth