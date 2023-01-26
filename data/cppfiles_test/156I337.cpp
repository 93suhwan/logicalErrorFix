#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fill(arr, c) memset(arr, c, sizeof(arr))
#define perm(r) next_permutation(all(r))
// it gives bool value ans permute the string lexoggraphically
#define sortdesc greater<int>()
#define ll long long int
// std::setfill('0') << std::setw(5) << 25; it adds leaing zeroes;
#define f(i, a) for (ll i = 0; i < a; i++)
#define fo(i, a) for (ll i = 1; i <= a; i++)
#define foo(i, x, n, c) for (ll i = x; i < n; i += c)
#define foi(i, x, n, c) for (ll i = x; i >= n; i += c)
#define fauto(i, m) for (auto i : m)
#define forall(a) for (auto itr = a.begin(); itr != a.end(); itr++)
#define ld long double
#define in push_back
#define vl vector<ll>
#define o(a) cout << a
#define os(a) cout << a << " "
#define en cout << "\n";
#define testcase \
	ll t;        \
	cin >> t;    \
	while (t--)
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define sz(a) (a).size()
#define prec(n) fixed << setprecision(n)
#define mp make_pair
#define bitcount __builtin_popcountll
#define imin   \
	o("imin"); \
	en;
// for interactive use endl after every output and fflush(stdout) after every input//
//   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
void fastio()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
}
ll M = 1e9 + 7;
ll mod(ll m, ll mod = M)
{
	m %= mod;
	return (m + mod) % mod;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}

bool is_prime(ll x)
{

	if (x == 1)
		return false;
	if (x == 2 || x == 3)
		return true;

	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

ll power(ll a, ll b)
{
	ll res = 1ll;
	while (b > 0)
	{
		if (b % 2ll)
			res = (res * a) % M;
		a = (a * a) % M;
		b /= 2ll;
	}
	return res;
}

vector<ll> primes;
void getPrimes()
{
	vector<bool> p(1001, true);
	for (ll i = 2; i * i <= 1000; i++)
	{
		if (p[i])
		{
			for (ll j = i * i; j <= 1000; j += i)
			{
				p[j] = false;
			}
		}
	}
	for (ll i = 2; i <= 1000; i++)
	{
		if (p[i])
		{
			primes.in(i);
		}
	}
}

// #define N 100001
// ll fact[N],invfact[N];

// void factorial()
// {
//     fact[0] = fact[1] = 1;

//     for(ll i = 2;i<N;i++) fact[i] = (i*fact[i-1])%mod;

//     invfact[N-1] = power(fact[N-1],mod-2);
//     for(ll i = N-2;i>=0;i--) invfact[i] = (invfact[i+1]*(i+1))%mod;
// }

// ll nCr(ll n,ll r) {
//    if(r>n)
//       return 0;
//    ll ans = fact[n];
//    ans = (ans*invfact[n-r])%mod;
//    ans = (ans*invfact[r])%mod;
//    return ans;
// }

// ll nPr(ll n,ll r) {
//    if(r>n)
//       return 0;
//    ll ans = fact[n];
//    ans = (ans*invfact[n-r])%mod;
//    return ans;
// }

// ll dx[]={-1,0,1,0};
// ll dy[]={0,-1,0,1};
bool chk(ll mid,ll a[],ll sum ,ll  k,ll n)
{
	if(sum-mid<=k)
	return true;
	ll x=0;
f(i,n-1)
{
x+=a[n-i-1];
ll d=sum;
d-=x;
d-=a[0];
d+=(i+2)*(a[0]-(mid-i-1));

if(d<=k)
return true;
}

return false;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif
	fastio();
	testcase
	{	
ll n,k;
cin>>n>>k;
ll a[n];
f(i,n)cin>>a[i];
sort(a,a+n);
ll sum=0;
f(i,n)sum+=a[i];
ll l=0,r=a[0]+(n-1);
ll ans=r;

while(l<=r)
{
	ll mid=l+(r-l)/2;
	if(chk(mid,a,sum,k,n))
	{
		r=mid-1;
		ans=min(ans,mid);
	}
	else
	l=mid+1;
}
o(ans);en;
	en;
	}
	return 0;
}
// grAPH layering
//  knapsack
//  dp //digitdp
// binary search
// dsu //square root decomposition //binary lifting
//  lca can be found using binary search and binary lifing
//  * int over/under flow?
//  * modulo mistake (forgot? / incorrect for -ve?)
//  * array bounds?
//  * variable uninitialized?
//  * dont get stuck in one approach
//  * can it be reduced? (to graph? to bsearch? to NP-hard?)
//  * Is there any special constraint to be exploited?
//  * special cases (n=0,1? division by 0 somewhere?)
//  * review precision error? missing typecasts?
//  *cin.ignore() before getline for whitespaces ignored due to cin
//  *segtree //*fenwicktreee //*kmp

// *docker exec -ti my_container sh -c "echo a && echo b"
