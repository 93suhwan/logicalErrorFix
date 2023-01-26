#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<time.h>
#include<set>
#include<cmath>
using namespace std;
#define rg register
#define ll long long
#define ull unsigned long long
#define lowbit(i) i&(-i)
#define pb(x) push_back(x)
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
const int maxn=2e5+10,mod=998244353;
int n,k,m,x[maxn],y[maxn],s,t;
map<double,int>mp;
struct oo{int x,y;}b[maxn];
double K(int a,int b){
    double xx=x[a]-x[b],yy=y[a]-y[b];
    if(xx==0)return 1.0/0.0;
    return yy/xx;
}
bool cmp(oo a,oo b){return a.x==b.x?a.y<b.y:a.x<b.x;}
double dis(oo a,oo b){
    double xx=a.x-b.x,yy=a.y-b.y;
    return sqrt(xx*xx+yy*yy);
}
int main(){
    read(n),read(k);
    for(rg int i=1;i<=n;i++)read(x[i]),read(y[i]);
    for(rg int i=2;i<=n;i++){
	double now=K(1,i);
	if(!mp[now])s++;
	mp[now]++;
    }
    if(s>2)t=1;
    else {
	for(rg int i=2;i<=n;i++){
	    double now=K(1,i);
	    if(mp[now]==1){t=i;break;}
	}
    }
    for(rg int i=1;i<=n;i++)
	if(i!=t)b[++m]=(oo){x[i],y[i]};
    sort(b+1,b+m+1,cmp);
    if(k==t){
	double ans=min(dis((oo){x[k],y[k]},b[1]),dis((oo){x[k],y[k]},b[m]))+dis(b[1],b[m]);
	printf("%lf\n",ans);
	return 0;
    }
    for(rg int i=1;i<=m;i++)
	if(b[i].x==x[k]&&b[i].y==y[k]){k=i;break;}
    if(k==1){
	double ans1;
	ans1=dis(b[1],b[m])+dis(b[m],(oo){x[t],y[t]});
	for(rg int i=1;i<m;i++)
	    ans1=min(ans1,dis(b[i],(oo){x[t],y[t]})+dis(b[i+1],(oo){x[t],y[t]})+dis(b[i+1],b[m])+dis(b[1],b[i]));
	printf("%lf\n",ans1);
	
    }
    else if(k==m){
	double ans1;
	ans1=dis(b[1],b[m])+dis(b[1],(oo){x[t],y[t]});
	for(rg int i=m;i>1;i--)
	    ans1=min(ans1,dis(b[i],(oo){x[t],y[t]})+dis(b[i-1],(oo){x[t],y[t]})+dis(b[i-1],b[1])+dis(b[m],b[i]));
	printf("%lf\n",ans1);
    }
    else {
	double ans1=1e18;b[0]=b[m+1]=(oo){x[t],y[t]};
	for(rg int i=k;i>=1;i--)ans1=min(ans1,dis(b[i],b[m])+dis(b[m],(oo){x[t],y[t]})+dis(b[i-1],(oo){x[t],y[t]})+dis(b[i-1],b[1])+dis(b[k],b[i]));
	for(rg int i=k;i<=m;i++)ans1=min(ans1,dis(b[i],b[1])+dis(b[1],(oo){x[t],y[t]})+dis(b[i+1],(oo){x[t],y[t]})+dis(b[i+1],b[m])+dis(b[k],b[i]));
	printf("%lf\n",ans1);
    }
}
