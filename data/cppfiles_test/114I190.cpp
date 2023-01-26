// Problem: B. Absent Remainder
// Contest: Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1613/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: abhidot

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define ll long long
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mod 1000000007
#define mod2 998244353
#define lld long double
#define pii pair<int, int>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define rep(i,x,y) for(int i=x; i<y; i++)
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define V vector
#define setbits(x) __builtin_popcountll(x)
#define w(x)  int x; cin>>x; while(x--)
using namespace std;
using namespace __gnu_pbds; 
template <typename num_t> using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
const long long N=200005, INF=2000000000000000000, inf = 2e9+5;

int power(int a, int b, int p){
	if(a==0)
	return 0;
	int res=1;
	a%=p;
	while(b>0)
	{
		if(b&1)
		res=(res*a)%p;
		b>>=1;
		a=(a*a)%p;
	}
	return res;
}


void print(bool n){
    if(n){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}


int32_t main()
{
    IOS;
    w(T){
    	int n;
    	cin>>n;
    	vector<int> a(n);
    	for(auto& i:a) cin>>i;
    	
    	for(int i=1;i<=(n/2);i++){
    		cout<<a[i]<<" "<<a[0]<<"\n";
    	}
    }
}