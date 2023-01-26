#include<bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
const int N=2e5+5,mod=998244353 ;
int t,x[N],y[N],s[N],n,p[N],sum[N];
set<pair<int,int> >st;
 main(){
	cin>>n;
	int ans = 0;
	for(int i=1;i<=n;i++) {
		cin>>x[i]>>y[i]>>s[i];
		st.insert({x[i],i});
		int lst = (*st.upper_bound({y[i],0})).s;
		if(lst == i) p[i] = (p[i-1] + x[i] - y[i])%mod;
		else p[i] =( p[i-1] + p[i-1] - p[lst-1] + x[i] - x[lst] + mod)%mod;
		if(s[i] == 1) {
			ans += p[i] - p[lst-1] + x[i] - x[i-1];
		}
		else ans += x[i] - x[i-1];
		ans = (ans+mod)%mod;
	//	cout<<ans<<endl;
	} 
	cout<<(ans+1)%mod;
	
}