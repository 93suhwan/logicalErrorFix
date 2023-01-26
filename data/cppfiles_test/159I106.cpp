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

int n,vis[1000010],t[1000010],u[1000010],sum[1000010];
vector<int> vv[1000010],v[1000010];

inline void init()
{
	for(int i=1;i<=1000000;i++) u[i]=i;
	for(int i=2;i<=1000000;i++){
		if(!vis[i]){
			v[i].push_back(i);
			for(int j=i+i;j<=1000000;j+=i){
				vv[j].push_back(i);
				vis[j]=1;
			}
		}
	}
	for(int i=1;i<=1000000;i++){
		for(int j=0;j<vv[i].size();j++){
			int cnt=0;
			while(u[i]%vv[i][j]==0){
				u[i]/=vv[i][j];cnt++;
			}
			if(cnt&1) v[i].push_back(vv[i][j]);
		}
	}
}

inline bool check(vector<int> x)
{
	for(int i=1;i<=n;i++) t[i]=1,sum[i]=0;
	for(int i=0;i<x.size();i++) t[x[i]]=0;
	for(int i=n-1;i>=1;i--) t[i]+=t[i+1];
	for(int i=2;i<=n;i++){
		for(int j=0;j<v[i].size();j++) sum[v[i][j]]+=(t[i]&1);
	}
	for(int i=2;i<=n;i++) if(sum[i]&1) return false;
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	init();
	if(n==1){
		cout<<1<<'\n';
		cout<<1<<'\n';
		return 0;
	}
	if(n==2){
		cout<<1<<'\n';
		cout<<1<<'\n';
		return 0;
	}
	if(n==3){
		cout<<1<<'\n';
		cout<<1<<'\n';
		return 0;
	}
	if(n%2==1){
		vector<int> res;
		res.push_back((n-1)/2);res.push_back(n);
		if(check(res)){
			cout<<n-2<<'\n';
			for(int i=1;i<=n;i++) if(i!=(n-1)/2&&i!=n) cout<<i<<' ';
			cout<<'\n';
			return 0;
		}
		res.clear();
		res.push_back((n+1)/2);res.push_back(n);
		if(check(res)){
			cout<<n-2<<'\n';
			for(int i=1;i<=n;i++) if(i!=(n+1)/2&&i!=n) cout<<i<<' ';
			cout<<'\n';
			return 0;
		}
		cout<<n-3<<'\n';
		for(int i=1;i<=n;i++) if(i!=2&&i!=(n-1)/2&&i!=n) cout<<i<<' ';
		cout<<'\n';
		return 0;
	}
	vector<int> res;
	res.push_back(n/2);
	if(check(res)){
		cout<<n-1<<'\n';
		for(int i=1;i<=n;i++) if(i!=n/2) cout<<i<<' ';
		cout<<'\n';
		return 0;
	}
	res.clear();
	res.push_back(n/2+1);
	if(check(res)){
		cout<<n-1<<'\n';
		for(int i=1;i<=n;i++) if(i!=n/2+1) cout<<i<<' ';
		cout<<'\n';
		return 0;
	}
	cout<<n-2<<'\n';
	for(int i=1;i<=n;i++) if(i!=2&&i!=n/2) cout<<i<<' ';
	cout<<'\n';
	return 0;
}
