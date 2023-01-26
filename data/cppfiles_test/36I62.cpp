// AUTHOR: fireLUFFYY, NITR
// Bhagwan, please AC karwa dena

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/stack:200000000")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define ull unsigned long long
#define vi vector<int>
#define vvl vector<vector<int>>
#define deql deque<int>
#define prquel priority_queue<int>
#define loop(i,n) for(int i=0;i<n;i++)
#define loopn(i,a,b) for(int i=a;i<=b;i++)
#define rloop(i,n) for(int i=n;i>0;i--)
#define sortv(a) sort(a.begin(),a.end())
#define sortvr(a) sort(a.rbegin(),a.rend())
#define verase(a) a.erase(unique(a.begin(),a.end()),a.end()) 
#define all(a) a.begin(),a.end()
#define getv(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);};
#define dbg(x) cerr<<#x<<" = "; _print(x);cerr<<"\n";
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second 
#define endl "\n"
#define inf 2e18
using namespace std;
using namespace __gnu_pbds;

int MOD=1000000007;
int mod=998244353;
const int N=200050;
const int nn=10050;
int fact[N]; // array to store values of factorial
bool prime[nn];	//array to store precalculated primes till 10^6
void _print(int a){cerr<<a;}  void _print(char a){cerr<<a;}  void _print(bool a){cerr<<a;}  void _print(string a){cerr<<a;}
template<class T> void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1){_print(i);cerr<<" ";}cerr<<"]";}
template<class T> void _print(set<T> s1){ cerr<<"[ "; for(T i:s1){_print(i);cerr<<" ";}cerr<<"]";}
template<class T> void _print(map<T,T> m1){for(auto i:m1){cerr<<"[ "; _print(i.first);cerr<<" : ";_print(i.second);cerr<<" ]";cerr<<endl;}}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
template<class T> T gcd(T a,T b){if(!a||!b)return a|b; unsigned shift=__builtin_ctz(a|b); a>>=__builtin_ctz(a); do{b>>=__builtin_ctz(b); if(a>b)swap(a,b);b-=a;}while(b); return a<<shift;}
template<class T> T lcm(T a,T b){ unsigned val=max(a,b)/gcd(a,b);val*=min(a,b);return val;}
bool pow2(int x){if(x&&(!(x&(x-1)))) return true; else return false;}
int multiply(int x, int y){return (x * 1ll * y) % MOD;}
int power(int x, int y){int z = 1;while(y){if(y & 1) z = multiply(z, x);x = multiply(x, x);y >>= 1;}return z;}
int modInverse(int x){return power(x, MOD - 2);}
int divide(int x, int y){return multiply(x, modInverse(y));}
void cal_factorial(){fact[0] = 1;for(int i = 1; i < N; i++)fact[i] = multiply(fact[i - 1], i);}// function to calculate factorial upto N
void cal_primes(){memset(prime,true,sizeof(prime)); loopn(i,2,sqrt(nn)){ if(prime[i]==true){ for(int j=i*i;j<=nn;j+=i){prime[j]=false;}}}}
int nCr(int n, int k){return divide(fact[n], multiply(fact[k], fact[n - k]));}
vector<int>Intersection(vi &v1,vi &v2){vi v3;sort(all(v1));sort(all(v2));set_intersection(all(v1),all(v2),back_inserter(v3));return v3;}
vector<int>Union(vi &v1,vi&v2){vi v3;sort(all(v1));sort(all(v2));set_union(all(v1),all(v2),back_inserter(v3));return v3;}
void FASTIO(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
int dx[8]={0,1,0,-1,1,1,-1,-1}; //direction vectors
int dy[8]={1,0,-1,0,1,-1,-1,1}; //direction vectors


void solve(int t)
{
	cal_primes();
	int testcases=t;
	while(t--)
	{
		//cout<<"#"<<(testcases-t)<<" Test-Case: "<<endl;
		//cout<<"Case #"<<(testcases-t)<<": ";
		int n;cin>>n;
		vi v;getv(v,n);
		int sum=0;

		for(int i=0;i<n;i++)
			sum+=v[i];

		if(!prime[sum])
		{
			cout<<n<<endl;
			for(int i=0;i<n;i++)
				cout<<i+1<<" ";
			cout<<endl;
		}
		else
		{
			bool flag=false;
			for(int i=0;i<n;i++)
			{
				int summ=sum-v[i];
				if(!prime[summ])
				{
					cout<<n-1<<endl;
					for(int j=0;j<n;j++){
						if(j!=i)
							cout<<j+1<<" ";
					}
					flag=true;
					cout<<endl;
				}
				if(flag)
					break;
			}
		}
	}
}

main()
{
	auto start=chrono::system_clock::now();
	{
		#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
			freopen("error.txt","w",stderr);
		#endif
		FASTIO();	
		int t=1;
		cin>>t;
		solve(t);
	}
	auto end=chrono::system_clock::now();
	chrono::duration<double> elapsed=end-start;
//	cout<<" Time taken: "<<elapsed.count()<<" sec";
	return 0;
}