#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int  long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define pi pair<int, int>
// #define ff first
// #define ss second

const int N=1e4+10;
const int INF=1e18;
const int M=1e9+7;
// const int M=998244353;

int fact[N];
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int power(int x, int y){
	int r=1;
	x=x%M;
	while(y){
		if(y&1){
			r=(r*x)%M;
		} 
		x=(x*x)%M;
		y/=2;
	}
	return r;
}
void factorial(){
	fact[0]=1;
	for(int i=1;i<N;i++){
		fact[i]=(fact[i-1]*i)%M;
	}
}
int ncr(int n, int r){
	if(n<r){
		return 0;
	}
	int x1=fact[n];
	int y1=fact[r]*fact[n-r];
	y1=y1%M;
	y1=power(y1,M-2);
	x1=(x1*y1)%M;
	return x1;
}

// struct compare{
// 	bool operator()(pair<int, int> const &a, pair<int, int> const &b){
// 		return a.first>b.first;
// 	}
// }

// struct FenwickTree{
// 	vector<int> tree;
// 	FenwickTree(int n): tree(n+1){}
// 	int sum(int pos){
// 		++pos;
// 		int r=0;
// 		while(pos>0){
// 			r+=tree[pos];
// 			pos&=pos-1;
// 		}
// 		return r;
// 	}
// 	void add(int pos, int val){
// 		++pos;
// 		while(pos<tree.size()){
// 			tree[pos]+=val;
// 			pos+=pos&-pos;
// 		}
// 	}
// };



void solve(){
	
	int n,k;cin>>n>>k;
	int ans=0;
	int d=__gcd(n,k);
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<d;i++){
		int j,c;
		for(j=0,c=0;j<n/d*2;j++,i=(i+k)%n){
			ans=max(ans,c=a[i]?c+1:0);
		}
		if(c==n/d*2){
			ans=1;
			break;
		}
	}
	cout<<ans<<endl;

}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	cin>>t;
	while(t--){
		solve();
	}


	
}