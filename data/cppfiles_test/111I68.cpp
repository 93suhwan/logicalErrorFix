//#pragma GCC optimize(2)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 2001
#define MAXK 101
#define mo 998244353
#define ll long long
#define re register
using namespace std;

int n,k,k2;
int b[MAXN];
int f[2][MAXN][MAXK];
ll sum[2][MAXN][MAXK];
int fac[MAXN],inv[MAXN];

int ksm(int x,int y){
	int ans=1;
	while(y>0){
		if(y&1)
			ans=1ll*ans*x%mo;
		y>>=1;
		x=1ll*x*x%mo;
	}
	return ans;
}

int C(int n,int m){
	return 1ll*fac[n]*inv[n-m]%mo*inv[m]%mo;
}

int main()
{
	freopen("tt.in","r",stdin);
	scanf("%d%d",&n,&k);
	k2=k*2;
	for(re int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	fac[0]=1;
	for(re int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
	inv[0]=1;
	inv[n]=ksm(fac[n],mo-2);
	for(re int i=n-1;i>=1;i--)
		inv[i]=1ll*inv[i+1]*(i+1)%mo;
	f[0][0][k]=1;
	int cur=0,pre=1;
	for(re int x=k;x<=k2;x++)
		sum[cur][0][x]=sum[cur][0][x-1]+f[cur][0][x];
	int max_x;
	int nowx,lasx,lasj;
	ll xx;
	for(re int i=1;i<=n;i++){
//		swap(cur,pre);
		cur^=pre,pre^=cur,cur^=pre;
		memset(f[cur],0,sizeof(f[cur]));
//		if(i>=2)
//			for(re int x=max(-k,-b[i-2]);x<=min(k,n-b[i-2]);x++)
//				for(re int j=max(x+b[i-2]-1,1);j<=i;j++)
//					f[cur][j][x+k]=0;
//		memset(sum[cur][0],0,sizeof(sum[cur][0]));
		if(i==2)
			for(re int x=k;x<=k2;x++)
				sum[cur][0][x]=0;
		max_x=min(k,n-b[i]);
		for(re int x=max(-k,-b[i]);x<=max_x;x++){
			nowx=x+b[i],lasx=nowx-b[i-1]+k;
			for(re int j=max(nowx-1,1);j<=i;j++){
				lasj=j-1;
				xx=0;
//				f[cur][j][x+k]=0;
//				printf("i=%d x=%d j=%d\n",i,x+b[i],j);
				if(lasx>=0 && lasx<=k2){
					xx+=1ll*j*f[pre][j][lasx];
					xx+=1ll*(j-nowx)*f[pre][lasj][lasx];
				}
//				for(int y=max(-k,-b[i-1]);y<=min(x+b[i]-1-b[i-1],min(k,n-b[i-1]));y++){
//					printf("y=%d ",y+b[i-1]);
//					f[cur][x+k][j]+=f[cur^1][y+k][j-1];
//					f[cur][x+k][j]%=mo;
//				}
				int maxx=max(-k,-b[i-1])+k,minn=min(lasx-k-1,min(k,n-b[i-1]))+k;
				if(maxx<=minn){
					xx+=sum[pre][lasj][minn];
					if(maxx>=1)
						xx-=sum[pre][lasj][maxx-1];
				}
				f[cur][j][x+k]=xx%mo;
//				printf("\n");
			}
		}
		for(re int j=1;j<=i;j++){
			sum[cur][j][0]=f[cur][j][0];
			for(re int x=1;x<=k2;x++){
				sum[cur][j][x]=sum[cur][j][x-1]+f[cur][j][x];
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
	cur=n%2;
	ll ans=0;
	max_x=min(k,n-b[n]);
	for(re int x=max(-k,-b[n]);x<=max_x;x++){
		int nowx=x+b[n];
		for(re int j=nowx;j<=n;j++)
			ans+=1ll*f[cur][j][x+k]*C(n-nowx,j-nowx)%mo;
	}
	printf("%lld\n",(ans%mo+mo)%mo);
	return 0;
}
