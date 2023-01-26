#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long  
#define ll long long
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define vec(a) vector<a>
#define pi pair<int ,int > 
#define pii pair<pi,int>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back 
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
#define s(v) v.size()
#define endl "\n"
#define Print(a) for(auto i:a) cout<<i<<" "; cout<<"\n";
#define Scan(a) rep(i,s(a)) cin>>a[i];
int mod = 1e9+7 ;
bool comp(vector<int> a, vector<int> b){
    if(a[1]<b[1])return true;
    return false;
}
ll fastexp(ll x,ll a){
    ll res = 1;
    while(a>0){
        if(a&1){
            res = (res*x)%mod;
        }
        a=a>>1;
        x=(x*x)%mod;
    }
    return res;
}
ll inverse(ll n){
    return fastexp(n,mod-2);
}
template <typename T>
void add(T &a, T b){
    a += b;
    if(a >= mod)a -= mod;
}
template <typename T>
void sub(T &a, T b){
    a -= b;
    if(a < 0)a += mod;
}
template <typename T>
void mul(T &a, T b){
    a *= b;
    if(a >= mod)a %= mod;
}

int parent[100010];
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int n;
int ask(int l){
	cout<<"? ";

	for(int i =0;i < n-1;i++)cout<<1<<" ";
	cout<<l<<endl;
	cout.flush();
	int k ;
	cin>>k;
	if(k == 0)return 1;
	else return 0;


}
int ask1(int l, int x){
	cout<<"? ";
	for(int i = 0;i < n-1;i++){
		cout<<x<<" ";
	}
	cout<<l<<"\n";
	cout.flush();
	int k;
	cin>>k;
	return k;
}
void solve(){	
	cin>>n;
	int t =0 ;
	int k = n;
	rep(i,n){
		if(ask(i+2)){
			break;
		}
		k--;
	}
	int ans[n];
	ans[n-1] = k;
	for(int i =1;i<=n;i++){
		if(i != k){
			int m = ask1(i, k);
			ans[m-1] = i;
		}
	}
	cout<<"! ";
	rep(i,n)cout<<ans[i]<<" ";
	cout<<"\n";
	cout.flush();




}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "return", stdin);
    freopen("output1.txt", "w", stdout);
    #endif

    int t=1;
    // cin>>t;
    // cout<<t;
    while(t--){
    	solve();
		// cout<<endl;
	}
    return 0;
}       
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/
	