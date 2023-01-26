// Problem: A. Array Elimination
// Contest: Codeforces - Codeforces Round #751 (Div. 1)
// URL: https://codeforces.ml/problemset/problem/1601/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define spu  ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define sp fixed<<setprecision
#define endl '\n' 
#define int long long 
const int N=200010;
int a[N];
int t,n;
int cnt[11];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++){
		int t=a[i];
		for(int j=1;j<=10;j++){
			if((t>>(j-1))&1) cnt[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=true;;
		for(int j=1;j<=10;j++){
			if(cnt[j]%i){
				flag=false;
				break;
			}
		}
		if(flag) cout<<i<<" ";
	}
	cout<<endl;
}
main(){
	cin>>t;
	while(t--) solve();
}