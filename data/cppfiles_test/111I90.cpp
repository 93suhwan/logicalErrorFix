#pragma GCC optimize(2)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 2010
#define MAXK 110
#define mo 998244353
#define ll long long
#define re register
using namespace std;

int n,k;
int b[MAXN];
int f[2][MAXN][MAXK];
ll sum[2][MAXN][MAXK];
ll fac[MAXN],inv[MAXN];

ll ksm(ll x,int y){
	ll ans=1;
	while(y>0){
		if(y&1)
			ans=ans*x%mo;
		y>>=1;
		x=x*x%mo;
	}
	return ans;
}

ll C(int n,int m){
	return fac[n]*inv[n-m]%mo*inv[m]%mo;
}

int main()
{
//	freopen("tt.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(re int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	fac[0]=1;
	for(re int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mo;
	inv[0]=1;
	inv[n]=ksm(fac[n],mo-2);
	for(re int i=n-1;i>=1;i--)
		inv[i]=inv[i+1]*(i+1)%mo;
	f[0][0][k]=1;
	int cur=0;
	for(re int x=0;x<=k;x++)
		sum[cur][0][x+k]=sum[cur][0][x+k-1]+f[cur][0][x+k];
	for(re int i=1;i<=n;i++){
		cur^=1;
		memset(f[cur],0,sizeof(f[cur]));
//		if(i>=2)
//			for(re int x=max(-k,-b[i-2]);x<=min(k,n-b[i-2]);x++)
//				for(re int j=max(x+b[i-2]-1,1);j<=i;j++)
//					f[cur][j][x+k]=0;
		memset(sum[cur][0],0,sizeof(sum[cur][0]));
//		if(i==2)
//			for(int x=0;x<=k;x++)
//				sum[cur][0][x+k]=0;
		for(re int x=max(-k,-b[i]);x<=min(k,n-b[i]);x++){
			for(re int j=max(x+b[i]-1,1);j<=i;j++){
				ll xx=0;
//				f[cur][j][x+k]=0;
//				printf("i=%d x=%d j=%d\n",i,x+b[i],j);
				if(x+b[i]-b[i-1]+k>=0 && x+b[i]-b[i-1]<=k){
					xx=j*f[cur^1][j][x+b[i]-b[i-1]+k]%mo;
					xx+=(j-(x+b[i]))*f[cur^1][j-1][x+b[i]-b[i-1]+k]%mo;
				}
//				for(int y=max(-k,-b[i-1]);y<=min(x+b[i]-1-b[i-1],min(k,n-b[i-1]));y++){
//					printf("y=%d ",y+b[i-1]);
//					f[cur][x+k][j]+=f[cur^1][y+k][j-1];
//					f[cur][x+k][j]%=mo;
//				}
				int maxx=max(-k,-b[i-1]),minn=min(x+b[i]-1-b[i-1],min(k,n-b[i-1]));
				if(maxx<=minn){
					xx+=sum[cur^1][j-1][minn+k];
					if(maxx+k>=1)
						xx-=sum[cur^1][j-1][maxx+k-1];
				}
				f[cur][j][x+k]=xx%mo;
//				printf("\n");
			}
		}
		for(re int j=1;j<=i;j++){
			sum[cur][j][0]=f[cur][j][0];
			for(re int x=-k+1;x<=k;x++){
				sum[cur][j][x+k]=sum[cur][j][x+k-1]+f[cur][j][x+k];
//				sum[cur][j][x+k]%=mo;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int x=max(-k,-b[i]);x<=min(k,n-b[i]);x++){
//			for(int j=max(x+b[i]-1,1);j<=i;j++){
//				printf("f[%d][%d][%d]=%lld\n",i,x+b[i],j,f[i][x+k][j]);
//			}
//		}
//	}
	ll ans=0;
	for(re int x=max(-k,-b[n]);x<=min(k,n-b[n]);x++){
		for(re int j=x+b[n];j<=n;j++)
			ans+=f[n%2][j][x+k]*C(n-(x+b[n]),j-(x+b[n]))%mo;
	}
	printf("%lld\n",(ans%mo+mo)%mo);
	return 0;
}
