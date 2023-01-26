#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=65;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int n;
int a[N];
pair<int,int>b[N];
int ans[N];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n%2==0){
		for(int i=1;i<n;i+=2){
			printf("%d %d ",a[i+1],-a[i]);
		}
		puts("");
	}
	else{
		//puts("hrer");
		for(int i=1;i<=n;i++){
			b[i].first=a[i];
			b[i].second=i;
		}
		sort(b+1,b+n+1);
		#define fi first
		#define se second
		int d=__gcd(b[1].fi,__gcd(b[2].fi,b[3].fi));
		ans[b[1].se]=b[3].fi/d;
		ans[b[2].se]=b[3].fi/d;
		ans[b[3].se]=(-b[1].fi-b[2].fi)/d;
		//printf("%d %d %d ",a[3]/d,a[3]/d,(-a[1]-a[2])/d);
		for(int i=4;i<n;i+=2){
			int d=__gcd(b[i].fi,b[i+1].fi);
			ans[b[i].se]=b[i+1].fi/d;
			ans[b[i+1].se]=-b[i].fi/d;
			//printf("%d %d ",a[i+1]/d,-a[i]/d);
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
}
int main()
{
	int T=read();
	while(T--)solve();
	return 0;
}