// author: xay5421
// created: Sat Oct 30 23:32:59 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
using LL=long long;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int brand(){return rng()&0X7FFFFFFF;}
const int N=100005;
int brute(int l,int r){
	int tot=0;
	rep(i,l,r)rep(j,i,r){
		if(__gcd(i,j)>=l)++tot;
	}
	return tot;
}
int ban[N],phi[N],p[N];
LL sphi[N];
void sieve(){
	ban[0]=ban[1]=1,phi[1]=1;
	for(int i=2;i<N;++i){
		if(!ban[i]){
			p[++*p]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	rep(i,1,N-1){
		sphi[i]=sphi[i-1]+phi[i];
	}
}
LL sol(int L,int R){
	LL ans=0;
	for(int l=L,r;l<=R;l=r+1){
		r=R/(R/l);
		ans+=1LL*(r-l+1)*sphi[R/l];
	}
	return ans;
}
int T,n,K;
LL f[100005][25];
vector<pair<int,int> >segs;
void get_seg(int n){
	segs.clear();
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		segs.eb(l,r);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	sieve();
	/*while(1){
		int l=brand()%100+1,r=brand()%100+1;
		if(l>r)swap(l,r);
		D("l=%d r=%d brute=%d sol=%lld\n",l,r,brute(l,r),sol(l,r));
		assert(brute(l,r)==sol(l,r));
	}*/
	memset(f,63,sizeof(f));
	f[0][0]=0;
	rep(i,1,100000){
		get_seg(i);
		LL cost=0;
		per(j,SZ(segs)-1,0){
			cost+=1LL*(segs[j].second-segs[j].first+1)*sphi[i/segs[j].first];
			rep(k,2,20){
				umin(f[i][k],f[segs[j].first-1][k-1]+cost);
			}
		}
		f[i][1]=cost;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&K);
		if(K>=20){
			printf("%d\n",n);
		}else{
			if(f[n][K]>=1e18)printf("%d\n",n);
			else printf("%lld\n",f[n][K]);
		}
	}
	return 0;
}
