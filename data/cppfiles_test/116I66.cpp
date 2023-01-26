#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

template <class T, class V>
ostream &operator<<(ostream &os, const pair<T, V> &curr)
{
    os << "{" << curr.first << "," << curr.second << "}";
    return os;
}

#define debug(x)           \
    cout << #x << ": [ ";  \
    for (auto &aa : x)     \
        cout << aa << " "; \
    cout << "]\n"
#define debug1(x) cout << "## " << #x << " : " << x << " ##\n"
#define debug2(x, y) cout << "## " << #x << " : " << x << " , " << #y << " : " << y << " ##\n"

#define ordered_pair_multiset tree< pair<ll, ll>, null_type,less< pair<ll, ll> >, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define F(type, i, a, b, incr) for (type i = a; i <= (type)(b); i += (type)(incr))
#define iter(it, s) for (auto it = s.begin(); it != s.end(); it++)
#define fillc(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define MOD 998244353
#define INF 1e17
#define multi_test 1

void solve()
{
	ll n;
	cin >> n;
	vector<vector<ll>> dp(n + 2, vector<ll>(2, 0));
	for (ll i = 0; i < n; i++)
	{
		ll num;
		cin >> num;
		dp[num + 1][0] = (dp[num + 1][0] * 2) % MOD;
		dp[num + 1][1] = (dp[num + 1][1] * 2) % MOD;
		dp[num + 1][0] = (dp[num + 1][0] + dp[num][0]) % MOD;
		if(num)
			dp[num - 1][1] = (dp[num - 1][0] + dp[num - 1][1]) % MOD;
		if(num == 1)
			dp[num - 1][1] = (dp[num - 1][1] + 1) % MOD;
		if(num == 0)
			dp[num + 1][0] = (dp[num + 1][0] + 1) % MOD;
		/*for (ll j = 0; j <= n; j++)
			cout << dp[j][0] << "," << dp[j][1] << " ";
		cout << endl;*/
	}
	ll sum = 0;
	for (ll i = 0; i <= n; i++)
		sum = (sum + dp[i][0] + dp[i][1]) % MOD;
	cout << sum << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    if (multi_test)
        cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}