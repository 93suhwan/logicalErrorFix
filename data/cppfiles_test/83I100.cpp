/*input
7
5
acbac
8
acabacba
12
aaaaaaaaaaaa
10
abacabadac
8
dcbaabcd
3
cba
6
sparky

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
int a[5000][5000];
int dp[5000][5000];
vector<int>A;
vector<array<int, 26>>B;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		array<int, 26>emp;
		for (int i = 0; i < 26; i++)
			emp[i] = -1;
		A = {0};
		B = {emp};
		int n;
		cin >> n;
		string s;
		cin >> s;
		s.push_back(0);
		int ans = n;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (s[i] == s[j])
				{
					if ((i == n - 1) || j == (n - 1))
						a[i][j] = 1;
					else
						a[i][j] = 1 + a[i + 1][j + 1];
				}
				else
				{
					a[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
				dp[i][j] = j - i + 1;
			for (int j = 0; j < i; j++)
			{
				if (i + a[i][j] < n && s[i + a[i][j]] > s[j + a[i][j]])
					dp[i][i + a[i][j]] = max(dp[i][i + a[i][j]], dp[j][n - 1] + 1);
			}
			int t = 0;
			for (int j = i + 1; j < n; j++)
			{
				if (t != -1)
				{
					dp[i][j] = max(dp[i][j], A[t] + 1);
					t = B[t][s[j] - 'a'];
				}
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
			}
			ans = max(ans, dp[i][n - 1]);
			t = 0;
			int mx = 0;
			for (int j = i; j < n; j++)
			{
				mx = max(mx, dp[i][j]);
				if (B[t][s[j] - 'a'] == -1)
				{
					B[t][s[j] - 'a'] = A.size();
					t = A.size();
					A.push_back(mx);
					B.push_back(emp);
				}
				else
				{
					t = B[t][s[j] - 'a'];
					mx = max(mx, A[t]);
					A[t] = mx;
				}
			}
		}
		cout << ans << "\n";
	}
}