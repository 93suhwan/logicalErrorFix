#include<bits/stdc++.h>
//#include <boost/math/common_factor.hpp>
using namespace std;
 
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// #define os_find(k) find_by_order(k)
// #define os_order(k) order_of_key(k)
 
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loop1(i,a,b) for(int i=a;i<=b;i++)
#define rloop(i,a,b) for(int i=a;i>b;i--)
#define rloop1(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
//#define mp make_pair
#define pii pair<ll,ll>
#define int   long long int
 #define double long double
#define min_heap priority_queue <int, vector<int>, greater<int> > 
#define ff first
#define ss second
#define ncr(n,r) fact[n]*modInv(fact[r])*modInv(fact[n-r]) 
#define MOD 1000000007
//#define MOD 998244353
#define inf 1e18
//#define modInv(a) binExp(a,mod-2)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define test int t;cin>>t;while(t--)
#define nl "\n"
#define ceill(a,b) ((a)/(b))+(((a)%(b))!=0)
//-------------------------IMPORTANT FUNCTIONS START---------------------
ll add(ll a, ll b) {ll z=a+b; if(z>=MOD) z -= MOD; return z;}
ll mul(ll a, ll b) { return (a*b)%MOD;}
ll sub(ll a, ll b) { return (a-b+MOD)%MOD;}
ll powr(ll x,  ll y) 
{ 
    int res = 1; 
  
    while (y > 0) {  
        if (y & 1) 
            res = res * x;  
        y = y >> 1; 
        x = x * x; 
    } 
    return res; 
} 
 
 
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1; 
    x = x % p; 
  
    while (y > 0) { 
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
} 
ll mod_inv(ll n, ll mod){
    return power(n, mod-2LL, mod);
}
 
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i <=sqrt(n); i++) 
        if (n % i == 0) 
            return false; 
  
 
    return true; 
} 
 
int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}
//-------------------------IMPORTANT FUNCTIONS END---------------------
 // initialize 2d vector   vector<vector<int>> dp(n+1,vector<int>(x+1,0));
// 1/n+2/n+3/n.....n/n=O(logn)
// never use sqrt*sqrt cf compiler chodu hai
// negative value m floor or ceil ulte kam karte equation solve karte waqt dhyan rakh4
// order of 1e8 in 1 sec is ok
 //POWER FUNCTION FOR LARGE NO.

//--------------------DONT FORGET TO CALL SIEVE() IN MAIN FUNCTION-----------------------------------
int check(int av1,int av0,int k,int w){
	int tot=av1+av0;
	int minn;
	if(av1>w){
		minn=av1-w;
		av1-=minn;
	}
	else{
		minn=w-av1;
		w-=minn;
	}
	if(k<minn){
		return 0;
	}
	k-=minn;
	if(k%2){
		return 0;
	}
	if(k>min(av1,av0)*2){
		return 0;
	}
	return 1;

}
void solve(){
  int a,b;
  cin>>a>>b;
  int n=a+b;
	set<int> s;
	loop(i,0,a+b+5){
		if(check(n/2,n-(n/2),i,a)){
			s.insert(i);
		}
		if(check(n-(n/2),n/2,i,a)){
			s.insert(i);
		}

	}
	cout<<s.size()<<nl;
	for(auto x:s)cout<<x<<" ";
	cout<<nl;
}
 
signed  main()
{
 fast
//  sieve();
// facto();
test
 
    solve();
 
}