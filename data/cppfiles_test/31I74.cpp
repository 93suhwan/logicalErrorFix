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
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n%2==0){
		for(int i=1;i<n;i++){
			printf("%d %d ",a[i+1],-a[i]);
		}
		puts("");
	}
	else{
		//puts("hrer");
		int d=__gcd(a[1],__gcd(a[2],a[3]));
		printf("%d %d %d ",a[3]/d,a[3]/d,(-a[1]-a[2])/d);
		for(int i=4;i<n;i++){
			int d=__gcd(a[i],a[i+1]);
			printf("%d %d ",a[i+1]/d,-a[i]/d);
		}
		puts("");
	}
}
int main()
{
	int T=read();
	while(T--)solve();
	return 0;
}