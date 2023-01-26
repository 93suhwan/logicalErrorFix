#import<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 70;

int t,n,m;
int a[20],f[20];
main()
{
	int p=1;
	for(int i=0;i<10;i++)
	{
		f[i]=p;
		p*=10;
	}
	for(cin >> t;t--;){
		cin >> n >> m;m++;
		for(int i=1;i<=n;i++) cin >> a[i];
		int ans=0;
		for(int i=1;i<n;i++)
		{
			int x=(f[a[i+1]]/f[a[i]]-1);
			if(m>=x) m-=x,ans+=f[a[i]]*x;
			else{
				ans+=m*f[a[i]];
				m=0;
				break;
			}
		}
	
		if(m) ans+=m*f[a[n]];
		cout << ans << '\n';
	}
}

