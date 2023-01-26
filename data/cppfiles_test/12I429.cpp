//       THIS IS MY NINJA WAY
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ctime>

#define str string
#define dbl double
#define ll long long int
#define ull unsigned long long
#define vl vector<ll>
#define vs vector<str>
#define pll pair<ll,ll>
#define vll vector<pll>
#define sl set<ll>
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define BS binary_search
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define fr(i,a,b) for(long long i=a; i<b; i++)
#define nfr(i,a,b) for(long long i=a; i<=b; i++)
#define psl pair<str,ll>
#define pls pair<ll,str>
#define pss pair<str,str>
#define lcm(a,b) (a*b)/__gcd(a,b)
#define ALL(a) a.begin(),a.end()
#define coml complex<ll>
#define INF 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define read(v,n) fr(i,0,n)cin>>v[i]
#define sqr(x) (x*x)
#define print(x) fr(i,0,x.size())cout<<x[i]<<" ";cout<<"\n"
const ll MOD = 1e9+7; // 998244353; 
const ll N = 1e6 + 5;
const ll mod = 12*60*60*1e9;
using namespace std;
using namespace __gnu_pbds;
void ron(){
	ll n,m,k; cin>>n>>m>>k;
	if(m==2){ // all will be horizontal
		if(k==n){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
		return;
	}
	if(m<2){
		cout<<"NO\n";
		return;
	}
	// if(n==2){ // no horizontal dominoes
	// 	if(k==0){
	// 		cout<<"YES\n";
	// 		return;
	// 	}
	// 	else {
	// 		cout<<"NO\n";
	// 		return;
	// 	}
	// }
	if((m-m%2)*(n-n%2)>=k){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
int main(){
	fast
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("time.txt", "w", stderr);
		freopen("output.txt", "w" , stdout);
	#endif
	ll t;
	// t=1;
	cin>>t;
	fr(i,1,t+1){
		// cout<<"Case #"<<i<<": ";
		ron();
	}
	cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0;
}