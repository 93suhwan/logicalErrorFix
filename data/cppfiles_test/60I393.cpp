#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ll long long
#define ull unsigned ll
#define N 1000005
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define pii pair<ll,ll>
//#define int ll
using namespace std;

int n,a[N];
unordered_map<int,int> mp;

void solve(){
	ll res=0,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%n){
		printf("0\n");
		return;
	}
	mp.clear();
	int k=2*sum/n;
	for(int i=1;i<=n;i++){
		if(mp.count(k-a[i])) res+=mp[k-a[i]];
		mp[a[i]]++;
	}
	printf("%lld\n",res);
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
    return 0;
}
/*

*/