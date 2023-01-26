#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define tup tuple<int,int,int>
#define g0 get<0>(i)
#define g1 get<1>(i)
#define g2 get<2>(i)
#define f first
#define s second
#define lowbit(x) (x&-x)
#define endl '\n'
#define mid ((l+r)>>1)
#define md ((l+r)/2)
#define i1 (i<<1)
#define i2 (i1+1)
#define Hash(x,y) (maxn*x+y)
#define iofaster ios::sync_with_stdio(0);cin.tie(0)
#define fr(a) freopen((a),"r",stdin)
#define fw(a) freopen((a),"w",stdout)
#define maxx(a,b) (a>b?a:b)
#define mixx(a,b) (a>b?b:a)
#define mset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(),x.end()
#define int long long
#define double long double
using namespace std;
const int maxn = 2e5 + 5 ;
const int mod = 1e9 + 7 ;
const int INF = 1e9 + 9 ;
const double eps = 1e-7 ;
pii exgcd(int a,int b) {
	if(b==0) return {1,0};
	pii tmp=exgcd(b,a%b);
	return make_pair(tmp.s,tmp.f-a/b*tmp.s);
}
signed main()
{
	iofaster;
	int t;
	cin>>t;
	while(t--) {
		int n,m,k;
		cin>>n>>m>>k;
		if(n%m==0) {
			for(int i=1;i<=k;i++) {
				int sz=n/m;
				int tot=n/sz;
				for(int j=1;j<=tot;j++) {
					cout<<sz<<' ';
					for(int t=1;t<=sz;t++) cout<<(j-1)*sz+t<<' ';
					cout<<endl;
				}
			}
		}
		else {
			auto [a,b]=exgcd(n/m,n/m+1);
			a*=n,b*=n;
			//cout<<a<<' '<<b<<endl;
			while(a<0 or b<0) {
				int x=(n/m+1)/__gcd(n/m,n/m+1);
				int y=(n/m)/__gcd(n/m,n/m+1);
				//cout<<x<<' '<<y<<endl;
				if(a>b) {
					a-=x;
					b+=y;
				}
				else {
					a+=x;
					b-=y;
				}
			}
			//cout<<a<<' '<<b<<endl;
			int p=0;
			for(int i=1;i<=k;i++) {
				for(int j=1;j<=b;j++) {
					cout<<n/m+1<<' ';
					for(int t=0;t<n/m+1;t++) cout<<((j-1)*(n/m+1)+p+t)%n+1<<' ';
					cout<<endl;
				}
				p+=b*(n/m+1);

				for(int j=1;j<=a;j++) {
					cout<<n/m<<' ';
					for(int t=0;t<n/m;t++) {
						cout<<((j-1)*(n/m)+p+t)%n+1<<' ';
					}
					cout<<endl;
				}
			}
		}
		cout<<endl;
	}
}
