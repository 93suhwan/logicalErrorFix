#include<cstdio>
#include<algorithm>
using namespace std;
struct str{
	int a,b,id;
	bool ans;
	bool operator <(str x){
		return  a<x.a;
	}
}p[100005];
int T,n,maxb,pre[100005],suf[100005];
bool cmd(str a,str b){
	return a.id<b.id;
}
void work(){
	pre[0]=0;suf[n+1]=2147483647;
	for(int i=1;i<=n;i++)pre[i]=max(pre[i-1],p[i].b);
	for(int i=n;i>=1;i--)suf[i]=min(suf[i+1],p[i].b);
	for(int i=n-1;i>1;i--){
		if(pre[i]<=suf[i+1]){
			for(int j=1;j<=i;j++)p[j].ans=0;
			break;
		}
	}
	return;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		maxb=0;
		for(int i=1;i<=n;i++)scanf("%d",&p[i].a);
		for(int i=1;i<=n;i++)scanf("%d",&p[i].b);
		for(int i=1;i<=n;i++)p[i].id=i,p[i].ans=1;
		sort(p+1,p+1+n);
		work();
		sort(p+1,p+n+1,cmd);
		for(int i=1;i<=n;i++)
		printf("%d",p[i].ans);
		printf("\n");
	}
	return 0;
}
/*
4
11 12 20 21
44 22 11 30
*/