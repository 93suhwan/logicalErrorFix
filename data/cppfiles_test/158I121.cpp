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
typedef std::pair<int,int>pii;
typedef std::vector<int>vi;
typedef std::vector<pii>vpii;
typedef std::vector<vi >vvi;
typedef long double ld;
//typedef __int128 i128;
//typedef __uint128_t u128;
#define Tp template<typename T>
#define eb emplace_back

char ibuf[1<<15],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<15,stdin),p1==p2)?EOF:*p1++)
struct FastIO{
	inline int rint(){rg char c,f=0;while((c=getchar())<48||c>57)f|=c=='-';ri unsigned a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
	inline ll rll(){rg char c,f=0;while((c=getchar())<48||c>57)f|=c=='-';rg ull a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
	inline operator int(){return rint();}
//	inline operator ll(){return rll();}
	/*inline void ou128(u128 x){
		u128 y=1;
		while(y<=x/10)y*=10;
		do putchar(x/y|48),x%=y,y/=10;while(y);
	}*/
	inline char rchar(){
		rg char c;
		while(!isgraph(c=getchar()));
		return c;
	}
}g90;

//const int M=1000000007,I2=500000004;
//inline int qpow(ll a,ll b){ri res=1;for(;b;a=a*a%M,b>>=1)if(b&1)res=res*a%M;return res;}
//#define pow qpow

std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
inline int rnd(const int&a,const int&b){
	return std::uniform_int_distribution<int>(a,b)(rng);
}
inline ld rnd(const ld&a,const ld&b){
	return std::uniform_real_distribution<ld>(a,b)(rng);
}
namespace MY_STD{
	Tp inline T abs(const T&a){return a<0?-a:a;}
}

const int N=10,SIZE=10101;
int x[N],s[N][SIZE];

signed main(){
	for(int T=g90;T--;){
		int n=g90,m=g90;
		for(int i=0;i<n;++i){
			x[i]=g90;
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)s[i][j]=g90.rchar()&15;
		}
		static int typ[N],ans[N];
		ll max=0;
		auto dfs=[&](auto&&self,int ly=0){
			if(ly>=n){
				static ll mul[SIZE];
				for(int j=0;j<=m;++j)mul[j]=0;
				for(int i=0;i<n;++i){
					if(typ[i])mul[m]-=x[i];
					else mul[m]+=x[i];
					for(int j=0;j<m;++j)if(s[i][j]){
						if(typ[i])mul[j]++;
						else mul[j]--;
					}
				}
				static int ord[SIZE];
				std::iota(ord,ord+m,0);
				std::sort(ord,ord+m,[](int i,int j){return mul[i]<mul[j];});
				ll res=0;
				for(int i=0;i<m;++i)res+=mul[ord[i]]*(i+1);
				res+=mul[m];
				if(res>max){
					max=res;
					for(int i=0;i<m;++i)ans[ord[i]]=i;
				}
//				for(int i=0;i<n;++i)defrog("%d ",typ[i]);
//				for(int i=0;i<m;++i)defrog("%d ",mul[i]);
//				for(int i=0;i<m;++i)defrog("%d ",ord[i]);
//				defrog("%d\n",res);
				return;
			}
			typ[ly]=1;
			self(self,ly+1);
			typ[ly]=0;
			self(self,ly+1);
			return;
		};
		dfs(dfs,0);
		
		
		for(int i=0;i<m;++i)printf("%d ",ans[i]+1);puts("");
	}
}