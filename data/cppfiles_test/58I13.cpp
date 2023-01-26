/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
namespace fastio{
    char in[100000];
    int itr=0,llen=0;
    char get(){
        if(itr==llen)llen=fread(in,1,100000,stdin),itr=0;
        if(llen==0)return EOF;
        return in[itr++];
    }
    char out[100000];
    int itr2=0;
    void put(char c){
        out[itr2++]=c;
        if(itr2==100000){
            fwrite(out,1,100000,stdout);
            itr2=0;
        }
    }
    int clear(){
        fwrite(out,1,itr2,stdout);
        itr2=0;
        return 0;
    }
    int getint(){
        int ret=0;char ch=get();
        if(ch=='-')return -getint();
        while (ch<'0'||ch>'9'){
            ch=get();if(ch=='-')return -getint();
        }
        while ('0'<=ch&&ch<='9'){
            ret=ret*10-48+ch;
            ch=get();
        }
        return ret;
    }
    string getstr(){
        string ret="";
        char ch=get();
        while(ch==' '||ch=='\n')ch=get();
        while(ch!=' '&&ch!='\n')ret.push_back(ch),ch=get();
        return ret;
    }
    void putstr(string s){
        for(int i=0;i<s.size();i++)put(s[i]);
    }
    template<class T>void putint(T x){
        if(x<0){
            put('-');
            putint(-x);
            return;
        }
        if(x==0){
            put('0');put(' ');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put(' ');
    }
    template<class T>void putln(T x){
        if(x<0){
            put('-');
            putln(-x);
            return;
        }
        if(x==0){
            put('0');put('\n');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put('\n');
    }
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int q,ls[200005],rs[200005],sz[200005],val[200005],rnd[200005],id[200005],root,tot,add[200005];
void pushdown(int x){
	val[x]+=add[x];
	add[ls[x]]+=add[x];
	add[rs[x]]+=add[x];
	add[x]=0;
}
void update(int x){
	sz[x]=1+sz[ls[x]]+sz[rs[x]];
}
int node(int v,int idd){
	tot++;
	add[tot]=ls[tot]=rs[tot]=0;
	sz[tot]=1;id[tot]=idd;
	val[tot]=v;rnd[tot]=Rand();
	return tot;
}
void split(int root,int v,int &rt1,int &rt2){
	pushdown(root);
	if(!root){rt1=rt2=0;return;}
	if(val[root]<=v){
		rt1=root;split(rs[root],v,rs[root],rt2);
	}else{
		rt2=root;split(ls[root],v,rt1,ls[root]);
	}
	update(root);
}
int merge(int x,int y){
	if(x==0||y==0)return x+y;
	if(rnd[x]>rnd[y]){
		pushdown(x);
		rs[x]=merge(rs[x],y);
		update(x);return x;
	}else{
		pushdown(x);
		ls[y]=merge(x,ls[y]);
		update(y);return y;
	}
}
void Func(int &rtl,int &rtr,int v){
	split(root,v-1,rtl,rtr);
}
void insert(int x,int idd){
	int rtl=0,rtv=0,rtr=0;
	Func(rtl,rtr,x);
	rtv=node(x,idd);add[rtr]++;
	root=merge(rtl,merge(rtv,rtr));
}
int fact[200005],inv[200005];
vector<pair<int,int> >all;
void dfs(int x){
	if(!x)return;
	pushdown(x);
	dfs(ls[x]);
	all.push_back(make_pair(val[x],id[x]));
	dfs(rs[x]);
}
int C(int nn,int mm){
	return 1ll*fact[nn]*inv[mm]%mod*inv[nn-mm]%mod;
}
int main(){
	fact[0]=1;
	for(int i=1;i<=2e5;i++)fact[i]=1ll*fact[i-1]*i%mod;
	for(int i=0;i<=2e5;i++)inv[i]=modpow(fact[i],mod-2);
	ios::sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		tot=0;root=0;
		for(int i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			insert(y,x);
		}
		all.clear();dfs(root);
		int cnt=0;
		for(int i=0;i<all.size();i++){
			if(i+1<all.size()&&all[i].first+1==all[i+1].first){
				if(all[i].second>all[i+1].second)cnt++;
			}else if(all[i].first!=n)cnt++;
		}
		cout<<C(n*2-cnt-1,n)<<endl;
	}
	return 0;
}