#include<bits/stdc++.h>
const double eps=1e-10;
using namespace std;
const int N=200005;
int n,k;
struct point{
	int x,y;
	bool on;
	bool operator<(const point &rhs){
		return x<rhs.x;
	}
}a[N];
double dis(int p,int q){if(p==q)return 0;return sqrt(1ll*(a[p].x-a[q].x)*(a[p].x-a[q].x)+1ll*(a[p].y-a[q].y)*(a[p].y-a[q].y));}
double slope(int p,int q){if(a[p].x==a[q].x)return 1e18;return 1.0*(a[p].y-a[q].y)/(a[p].x-a[q].x);}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	scanf("%d%d",&a[i].x,&a[i].y),a[i].on=(i==k);
	if(n>=4)
	{
		double x=slope(1,2),y=slope(1,3),z=slope(1,4);
		if(abs(x-z)<=eps&&abs(x-y)>eps)swap(a[3],a[n]);
		else if(abs(x-y)<=eps&&abs(x-z)>eps)swap(a[4],a[n]);
		else if(abs(y-z)<=eps&&abs(x-y)>eps)swap(a[2],a[n]);
		else if(abs(x-y)>eps&&abs(y-z)>eps&&abs(x-z)>eps)swap(a[1],a[n]);
		else
		{
			for(int i=5;i<=n;++i)
			if(abs(slope(1,i)-x)>eps)
			{swap(a[i],a[n]);break;}
		}
	}
	sort(a+1,a+n);
	if(a[n].on)printf("%.7lf",min(dis(1,n)+dis(1,n-1),dis(n-1,n)+dis(1,n-1)));
	else
	{
		for(int i=1;i<n;++i)if(a[i].on)k=i;
		double ans=1e18;
		ans=min(ans,dis(1,k)+dis(1,n)+dis(k+1,n-1)+min(dis(n-1,n),dis(k+1,n)));
		ans=min(ans,dis(1,k)+dis(1,n-1)+dis(n,n-1));
		ans=min(ans,dis(k,n-1)+dis(1,n-1)+dis(1,n));
		ans=min(ans,dis(k,n-1)+dis(n-1,n)+dis(1,k-1)+min(dis(1,n),dis(k-1,n)));
		ans=min(ans,dis(k,n)+dis(1,n-1)+min(dis(1,n),dis(n-1,n)));
		for(int i=k+1;i<n-1;++i)
		{
			ans=min(ans,dis(k,1)+dis(1,i)+dis(i,n)+dis(n,i+1)+dis(i+1,n-1));
			ans=min(ans,dis(k,i)+dis(1,i)+dis(1,n)+dis(n,i+1)+dis(i+1,n-1));
		}
		for(int i=2;i<k;++i)
		{
			ans=min(ans,dis(k,n-1)+dis(n-1,i)+dis(i,n)+dis(n,i-1)+dis(1,i-1));
			ans=min(ans,dis(k,i)+dis(n-1,i)+dis(n-1,n)+dis(n,i-1)+dis(1,i-1));		
		}
		printf("%.7lf",ans);
	}
	return 0;
}
/*
4 3
-733 -804
-4 -755
725 -706
-895 -822
*/