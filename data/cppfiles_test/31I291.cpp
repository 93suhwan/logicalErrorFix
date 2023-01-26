#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int b[N];
typedef long long ll;
struct stu
{
	int val,id;
	bool operator<(const stu &W)const
	{
		return abs(val)<abs(W.val);
	}
} a[N];
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll d = exgcd(b,a%b,x,y);  //d 就是gcd(a,b)
	ll t = x;
	x = y;
	y = t-(a/b)*y;
	return d;
}
bool linear_equation(ll a,ll b,ll c,ll &x,ll &y)
{
	ll d = exgcd(a,b,x,y);  //d是gcd(a,b)//求出a*x+b*y = gcd(a,b)的一组解

	if(c%d) return false;
	ll k = c/d;    //上述解乘以 c/gcd(a,b)就是 a*x +b*y = c的解
	x *= k;
	y *= k;    //求得的只是其中一组解
	return true;
}
int gcd(int x,int y)
{
	x=abs(x),y=abs(y);
//	printf("%d      %d  %d\n",x,y,__gcd(x,y));
	return __gcd(x,y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&a[i].val);
			a[i].id=i;
		}
		sort(a+1,a+1+n);
		if(n%2==0)
		{
			for(int i=1; i<=n; i+=2)
			{
				if((abs(a[i].val)==a[i].val&&abs(a[i+1].val)!=a[i+1].val)||abs(a[i].val)!=a[i].val&&abs(a[i+1].val)==a[i+1].val)
				{
					int x=a[i+1].val,y=a[i].val;
					b[a[i].id]=x/gcd(x,y),b[a[i-1].id]=y/gcd(x,y);
				}
				else
				{
					int x=a[i+1].val,y=a[i].val;
					b[a[i].id]=-x/gcd(x,y),b[a[i+1].id]=y/gcd(x,y);
				}
			}
		}
		else
		{
			for(int i=n; i>3; i-=2)
			{
				if((abs(a[i].val)==a[i].val&&abs(a[i-1].val)!=a[i-1].val)||abs(a[i].val)!=a[i].val&&abs(a[i-1].val)==a[i-1].val)
				{
					int x=a[i-1].val,y=a[i].val;
//					printf("%d  %d       %d\n",x,y,gcd(x,y));
					b[a[i].id]=x/gcd(x,y),b[a[i-1].id]=y/gcd(x,y);
				}
				else
				{
					int x=a[i-1].val,y=a[i].val;
					b[a[i].id]=-x/gcd(x,y),b[a[i-1].id]=y/gcd(x,y);
				}
			}
			ll x=a[1].val,y=a[2].val,z=a[3].val;
			for(int i=1; i<=1000; i++)
			{
				ll c,d;
				if(!linear_equation(x,y,z*i,c,d))continue;
				else
				{
					b[a[1].id]=c,b[a[2].id]=d,b[a[3].id]=-i;
					break;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			printf("%d ",b[i]);
		}
		puts("");
	}
}
