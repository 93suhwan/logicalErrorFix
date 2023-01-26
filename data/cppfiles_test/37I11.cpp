#include<bits/stdc++.h>
#define f first
#define s second
#define int long long
#define gcd Gcd
using namespace std;
const int N=3e5+5,mod=998244353;
int t,gcd,ans[N],n;
vector<int> V[N];
int dfs(int u,int p,int k) {
	int cnt = 0;
	for(int i=0;i<V[u].size();i++) {
		if(V[u][i]==p) continue;
		bool f = dfs(V[u][i],u,k);
		if(f == -1) return -1;
		cnt += 1 - f;
	}
	if(cnt % k == 0) {
		gcd = __gcd(gcd,cnt);	
		return 0;
	}
	if((cnt+1) % k == 0 || !(u-1)) {
		gcd = __gcd(gcd,cnt+1);
		return 1;
	}
	return -1;
}
 main(){
	cin>>t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++) V[i].clear(),ans[i] = 0;
		n--;
		ans[1] = 1;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			V[u].push_back(v);
			V[v].push_back(u);
			ans[1] = ans[1]*2%mod;
		}
	
		for(int i=n;i>=2;i--) {
			if(n%i==0) {
				gcd = 0;
				if(dfs(1,0,i)>=0) ans[gcd] = 1;
			}
			if(ans[i]) ans[1] = (ans[1] - 1 + mod)%mod;
		}
		for(int i=1;i<=n+1;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
}
