#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order();
//s.order_of_key();

#define int                 		long long
#define double              		long double
#define endl                		"\n"
#define pb                  		push_back
#define PI                  		3.1415926535897932384626433832795l
#define F                   		first
#define S                   		second
#define mp                  		make_pair
#define f(i,n)              		for(int i=0;i<n;++i)
#define loop(i,a,b)         		for (int i=a ; i<b ;++i)
#define fastio              		ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)              		(v).begin(),(v).end()
#define rall(v)             		(v).rbegin(),(v).rend()
#define gcd(a,b)            		__gcd((a),(b))
#define fill(a,value)       		memset(a,value,sizeof(a));
#define minn(v)             		*min_element(v.begin(), v.end());
#define maxx(v)             		*max_element(v.begin(), v.end());
#define print(x)            		cout<<(x)<<endl;
typedef pair<int, int>      		pii;
typedef vector<int>         		vi;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 1e9;
const int N = 5005;

bool isPrime(int n)
{
	// Corner cases
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

void solve()
{
	int n;
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s += x;
	}
	if (isPrime(s)) {
		cout << n - 1 << "\n";
		for (int i = 1; i < n; ++i) {
			cout << i << " ";
		}
	}
	else {
		cout << n << "\n";
		for (int i = 1; i <= n; ++i) {
			cout << i << " ";
		}
	}
	cout << "\n";
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fastio;
	cout << fixed << setprecision(12);

	int T = 1;
	cin >> T;

	f(tc, T)
	{
		// cout << "Case #" << tc + 1 << ": ";
		solve();
	}
	return 0;
}