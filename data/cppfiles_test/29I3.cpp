/*
Codeforces 1553F
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lson o<<1
#define rson o<<1|1
#define mid (l+r>>1)

const int N = 3e5;

int n,a[200005],s[200005],ans[200005];
struct segtree{
	int cnt,sum;
}t[300005<<2];

void modify(int o,int l,int r,int x)
{
	if(l==x && r==x)
	{
		t[o].cnt++, t[o].sum += x;
		return;
	}
	if(x<=mid)
		modify(lson,l,mid,x);
	else
		modify(rson,mid+1,r,x);
	t[o].cnt = t[lson].cnt+t[rson].cnt;
	t[o].sum = t[lson].sum+t[rson].sum;
}

int querycnt(int o,int l,int r,int ql,int qr)
{
	if(ql>qr)
		return 0;
	if(l>=ql && r<=qr)
		return t[o].cnt;
	int res=0;
	if(ql<=mid)
		res += querycnt(lson,l,mid,ql,qr);
	if(qr>mid)
		res += querycnt(rson,mid+1,r,ql,qr);
	return res;
}

int querysum(int o,int l,int r,int ql,int qr)
{
	if(ql>qr)
		return 0;
	if(l>=ql && r<=qr)
		return t[o].sum;
	int res=0;
	if(ql<=mid)
		res += querysum(lson,l,mid,ql,qr);
	if(qr>mid)
		res += querysum(rson,mid+1,r,ql,qr);
	return res;
}

signed main()
{
	cin>>n;
	for(int i=1;i<=n;cin>>a[i++]);
	for(int i=1;i<=n;i++)
	{
		s[i] = s[i-1]+a[i];
		int q=0;
		for(int j=0;;j++)
		{
			q += j*querycnt(1,1,N,max(a[i]*j,1ll),min(a[i]*(j+1)-1,N));
			if(i*j>=N)
				break;
		}
		int s1=s[i-1]-a[i]*q;
		q = 0;
		for(int j=1;j*j<=a[i];j++)
		{
			q += j*querysum(1,1,N,(int)(a[i]*1.0/(j+1)+1),a[i]/j);
			if(j*j!=a[i])
			{
				int x=a[i]/j;
				q += x*querysum(1,1,N,(int)(a[i]*1.0/(x+1)+1),a[i]/x);
			}
		}
		int s2=(i-1)*a[i]-q;
		ans[i] = ans[i-1]+s1+s2;
		modify(1,1,N,a[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	
	return puts(""), 0;
}