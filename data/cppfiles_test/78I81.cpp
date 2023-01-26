// Problem: A. Short Substrings
// Contest: Codeforces - Codeforces Round #650 (Div. 3)
// URL: https://codeforces.ml/contest/1367/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 

#include<bits/stdc++.h>
#define File(s) freopen(#s".in","r",stdin),freopen(#s".out","w",stdout)
#ifdef GTRAKIOI
#define defrog(...) fprintf(stderr,__VA_ARGS__)
#else
#define defrog(...) 1
#endif
#if __cplusplus>=201703L
#define rg
#else
#define rg register
#endif
#define ri rg int
typedef long long ll;
typedef unsigned long long ull;
//#define int ll
typedef std::pair<int,int>pii;
typedef std::pair<ll,int>plli;
typedef std::tuple<int,int,int>tiii;
typedef std::vector<int>vi;
typedef std::vector<vi >vvi;
typedef std::vector<pii >vpii;
typedef std::vector<tiii >vtiii;
#define Tp template<typename T>
#define pb push_back

 #define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<15,stdin),p1==p2)?EOF:*p1++)
 char ibuf[1<<15],*p1,*p2;
 struct{
	 inline int rint(){rg char c,f=0;while((c=getchar())<48||c>57)f|=c=='-';ri unsigned a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
	 inline ll rll(){rg char c,f=0;while((c=getchar())<48||c>57)f|=c=='-';rg uint64_t a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
	 inline operator int(){return rint();}
     inline operator ll(){return rll();}
 }g90;

const int LN=19,N=1<<LN;
int a[N],cnt[LN];

inline int gcd(const int&a,const int&b){
	return b?gcd(b,a%b):a;
}

signed main(){
	for(int T=g90;T--;){
		int n=g90,l=std::__lg(n);
		for(int i=0;i<=l;i++)cnt[i]=0;
		for(int i=1;i<=n;++i){
			a[i]=g90;
			for(int k=0;k<=l;++k){
				if(a[i]>>k&1)cnt[k]++;
			}
		}
		int g=0;
		for(int k=0;k<=l;++k){
			g=gcd(cnt[k],g);
		}
//		defrog("%d\n",g);
		if(g==0){
			for(int i=1;i<=n;++i)printf("%d ",i);
			puts("");
			continue;
		}
		for(int i=1;i<=n;i++)if(!(g%i))printf("%d ",i);
		puts("");
	}
}