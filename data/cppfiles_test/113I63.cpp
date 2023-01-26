//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize ("unroll-loops")
#include "bits/stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//change int below to the data type of the key
typedef tree<long long int, null_type, less<long long int>, rb_tree_tag,
        tree_order_statistics_node_update>
    	pbds;

#define FAST_IO     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(x)    cout<<#x<<" is "<<x<<endl;
#define debugp(x)   cout<<#x<<" : "<<"("<<(x).first<<","<<(x).second<<")"<<endl;
#define debuga(x,n) cout<<#x<<" : ";for(int i=0;i<n;++i) cout<<x[i]<<" "; cout<<endl;

#define mod 1000000007
#define inf 1e18
#define int long long
#define float long double
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define memset(a,val) memset(a,val,sizeof a)
#define arr array
#define ff first
#define ss second
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define sqrt(x) sqrtl(x)
#define cbrt(x) cbrtl(x)

//cout<<fixed<<setprecision(15)<<ans<<endl;
int max(const int &x,const int&y){return ((x)>(y))?(x):(y);}
int min(const int &x,const int&y){return ((x)<(y))?(x):(y);}
int min(const int &x,const int &y, const int &z){return min(x,min(y,z));}
int max(const int &x,const int &y, const int &z){return max(x,max(y,z));}
int gcd(int a,int b){if(b==0) return a; return gcd(b,a%b);}
int lcm(int a,int b){return (a/gcd(a,b))*b;}
int to_int(const string &s){return stoll(s);}
int pw(int x,int y){
	int res = 1;
	while(y > 0){
		if(y&1) res = (res*x);
		x = (x*x);
		y = y>>1;
	}
	return res;
}
int pwmod(int x,int y){
	x = x%mod;
	int res = 1;
	while(y > 0){
		if(y&1) res = (res*x)%mod;
		x = (x*x)%mod;
		y = y>>1;
	}
	return res;	
}
int inv(const int &x){return pw(x,mod-2);} //along with mod m
//s.find(curr)==string::npos (curr not present in s)
//pbds-> s.order_of_key(x) return number of elements strictly less than x
//pbds-> s.find_by_order(i) returns iterator to the element at index i (0 based) (i-1th largest element)



int32_t main(){
	FAST_IO;
	int n;
	cin>>n;
	int a[n];
	int sum = 0;
	for(int i=0;i<n;++i){
		cin>>a[i];
		sum += a[i];
	}
	sort(a,a+n);
	int m;
	cin>>m;
	vector<pair<int,int>> v(m);
	for(int i=0;i<m;++i){
		cin>>v[i].ff>>v[i].ss;
	}
	for(int i=0;i<m;++i){
		int ans = inf;
		//ans = max(0,v[i].ff + v[i].ss - sum);
		int x = lower_bound(a,a+n,v[i].ff) - a;//equal or greater than health
		if(x == 0){
			int cans = 0;
			cans += max(0,v[i].ff - a[x]);
			cans += max(0,v[i].ss - (sum - a[x]));
			ans = min(ans,cans);
		}
		else{
			int cans = 0;
			cans += max(0,v[i].ff - a[x]);
			cans += max(0,v[i].ss - (sum - a[x]));
			ans = min(cans,ans);
			x--;
			cans = 0;
			cans += max(0,v[i].ff - a[x]);
			cans += max(0,v[i].ss - (sum - a[x]));
			ans = min(cans,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}