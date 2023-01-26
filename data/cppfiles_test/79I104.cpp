//LYC_music yyds!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0)
#define lowbit(x) (x&(-x))
using namespace std;
inline char gc()
{
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
int read()
{
	int pos=1,num=0;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-') pos=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		num=num*10+(int)(ch-'0');
		ch=getchar();
	}
	return pos*num;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}
void writesp(int x)
{
	write(x);
	putchar(' ');
}
void writeln(int x)
{
	write(x);
	putchar('\n');
}
const int N=2e6+10;
int n,a[200005],f[1005],ans[2000005],cnt;
signed main()
{
	int T=read();
	while (T--)
	{
		n=read();
		memset(f,0,sizeof(f));
		int l=0; cnt=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			int now=a[i],flag=0;
			while (now)
			{
				f[++flag]+=now&1;
				now>>=1;
			}
			l=max(l,flag);
		}
		int x=0;
		for (int i=1;i<=l;i++)
			if (!x) x=f[i];
			else if (f[i]) x=__gcd(x,f[i]);
		for (int i=1;i*i<=x;i++)
		{
			if (!(x%i))
			{
				ans[++cnt]=i;
				if (i*i!=x) ans[++cnt]=x/i;
			}
		}
		if (cnt==0)
		{
			for (int i=1;i<=n;i++)
				writesp(i);
			putchar('\n');
		}
		else
		{
			sort(ans+1,ans+1+cnt);
			for (int i=1;i<=cnt;i++)
				writesp(ans[i]);
			putchar('\n');
		}
	}
}



