// User: Rahkin

#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
/*------------------------------------------------------------*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/*------------------------------------------------------------------*/
#define int               long long
#define rev               greater<int>()
/*------------------------------------------------------------------*/
#define nl                "\n"
#define pb                push_back
#define pf                push_front
#define all(x)            (x).begin(),(x).end()
#define rall(x)           (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define fr                first
#define sc                second
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define fix(prec)         {cout << setprecision(prec) << fixed;}
#define lcm(a, b)         ((a) * (b)) / __gcd(a, b)
#define imin              INT_MIN
#define imax              INT_MAX
#define lmin              LLONG_MIN
#define lmax	          LLONG_MAX
#define Yes               cout<<"Yes\n"
#define No                cout<<"No\n"
#define YES               cout<<"YES\n"
#define NO                cout<<"NO\n"
#define yes               cout<<"yes\n"
#define no                cout<<"no\n"
#define read(A) for (auto &i: A) cin  >> i;
#define show(A) for (auto &i: A) cout << i << " "; cout << '\n';
#define endl "\n"
#define sz(x)             (int)((x).size())

const double Pi = acos(-1.0);
const int mod = 1e9 + 7;
const int mod2 = 998244353;

const int N1 = 2e5 + 5;
const int N2 = 2e6 + 5;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
/*----------------------------------------------------------*/
void setIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
void local()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
/*--------------------------------------------------------*/

signed main()
{
	init();

	int t;
	cin >> t;
	while (t--)
	{
		int n , k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int pre[n];
		pre[0] = 0;
		for (int i = 1; i < n; i++)
			pre[i] = pre[i - 1] + a[i];
		int ans = imax;
		for (int i = 0; i <= n - 1; i++)
		{
			// 1 1 1 2 2 3 6 6 8 10
			int taken = n - i - 1;
			int count = 1 + taken;
			// x<=k-sum/count
			int sum = pre[i] ;
			int x;
			if (k >= sum)
				x = (k - sum) / count;
			else
			{
				if ((k - sum) % count == 0)
					x = abs(k - sum) / count;
				else
					x = abs(k - sum) / count + 1;
				x = x * -1;
			}
			if (sum + x * count > k)
				continue;
			int cur = taken;
			if (a[0] >= x)
				cur += a[0] - x;
			else
				continue;
			ans = min(ans, cur);
		}
		if (ans == imax)
			cout << 0 << nl;
		else
			cout << ans << nl;

	}
	return 0;

}