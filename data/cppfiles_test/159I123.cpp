#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

mt19937 Rand(998244353);
int n,u[1000010];
unsigned int ans,p[1000010],val[1000010];
bool vis[1000010];
cc_hash_table<unsigned int,int> mp; 

inline void init()
{
	for(int i=2;i<=n;i++) u[i]=i;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			p[i]=Rand();val[i]=p[i];
			for(int j=i+i;j<=n;j+=i){
				vis[j]=1;
				while(u[j]%i==0){
					u[j]/=i;val[j]^=p[i];
				}
			}
		}
	}
	for(int i=2;i<=n;i++) val[i]^=val[i-1];
	for(int i=2;i<=n;i++) ans^=val[i];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	if(n==1){
		cout<<1<<'\n'<<1<<'\n';
		return 0;
	}
	init();
	for(int i=2;i<=n;i++) if(val[i]==ans){
		cout<<n-1<<'\n';
		for(int j=1;j<=n;j++) if(j!=i) cout<<j<<' ';
		cout<<'\n';
		return 0;
	}
	for(int i=2;i<=n;i++) mp[val[i]]=i;
	for(int i=2;i<=n;i++) if(mp[ans^val[i]]){
		int x=mp[ans^val[i]];
		cout<<n-2<<'\n';
		for(int j=1;j<=n;j++) if(j!=i&&j!=x) cout<<j<<' ';
		cout<<'\n';
		return 0;
	}
	mp[val[n]]=0;
	ans^=val[n];
	for(int i=2;i<=n-1;i++) if(mp[ans^val[i]]){
		int x=mp[ans^val[i]];
		cout<<n-3<<'\n';
		for(int j=1;j<n;j++) if(j!=i&&j!=x) cout<<j<<' ';
		cout<<'\n';
		return 0;
	}
	return 0;
}
