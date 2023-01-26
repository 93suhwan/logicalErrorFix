#include<bits/stdc++.h>
using namespace std;
const int N=200010,mod=1e9+7;
int n,s,ans,sum[N<<3];
struct intv{
	int l,r;
	bool s;
	intv(){s=false;}
	bool operator<(intv x){return r<x.r;}
}t[N];
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
void update(int o,int l,int r,int p,int x){
	sum[o]=add(sum[o],x);
	if(l==r)return;
	int mid=(l+r)>>1;
	if(p<=mid)update(o<<1,l,mid,p,x);
	else update(o<<1|1,mid+1,r,p,x);
}
int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return sum[o];
	int ans=0,mid=(l+r)>>1;
	if(ql<=mid)ans=add(ans,query(o<<1,l,mid,ql,qr));
	if(qr>mid)ans=add(ans,query(o<<1|1,mid+1,r,ql,qr));
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&t[i].l,&t[i].r);
	scanf("%d",&s);
	for(int i=1;i<=s;i++){
		int x;
		scanf("%d",&x);
		t[x].s=true;
	}
	sort(t+1,t+n+1);
	int ml=0;
	for(int i=n;i>=1;i--){
		if(!t[i].s)continue;
		if(t[i].l>ml)ml=t[i].l;
		else t[i].s=false;
	}
	for(int i=1;i<=n;i++){
		if(t[i].s)ans=add(ans,add(sum[1],1));
		update(1,1,2*n,t[i].l,add(query(1,1,2*n,t[i].l,t[i].r),1));
	}
	printf("%d\n",ans);
}