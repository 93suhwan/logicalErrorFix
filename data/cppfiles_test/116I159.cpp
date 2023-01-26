#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99,mod=998244353;

int n,t,a[N],dp[N],Pow[N],mark[N];
vector<pair<int,int> > v[N];


void Main(){
	int ans=0;
	dp[0]=1;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		a[i]++;
	}
	f(i,1,n+1){
		int x=(dp[a[i]-1]+dp[a[i]])%mod;
		Add(dp[a[i]],x);
		Add(ans,x);
		v[i+1].pb(mp(a[i]+2,x));
	}
	f_(i,n,1){
		mark[a[i]]++;
		for(auto u : v[i]){
			//cout<<i<<" "<<u.F<<" "<<u.S<<endl;
			int res=(Pow[mark[u.F]]-1)*u.S%mod;
			Add(ans,res);
		}
	}
	Add(ans,Pow[mark[2]]+mod-1);
	cout<<ans<<endl;
	f(i,0,n+10) mark[i]=dp[i]=0,v[i].clear();
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Pow[0]=1;
	f(i,1,N) Pow[i]=2ll*Pow[i-1]%mod;
	
	cin>>t;
	while(t--){
		Main();
	}
}
