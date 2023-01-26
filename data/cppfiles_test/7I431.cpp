#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define pob pop_back()
#define ms0(s) memset(s,0,sizeof s)
#define ff first
#define ss second
typedef long long int ll;
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define prq priority_queue<ll>  //max-heap
#define psq priority_queue<ll,vector<ll>,greater<ll>>  //min-heap
#define m_p make_pair
#define vcc vector<char>
#define vss vector<string>
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define setbit(n) __builtin_popcountll(n)
const ll mxn = 1e5 + 5;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t = 1;
	cin >> t;
	while (t--)
	{
		ll i, j, k, n, m;
		cin >> n;
		ll a[n];
		for (auto &i : a)cin >> i;
		if (n == 1)
		{
			cout << 1 << "\n";
			continue;
		}
		ll diff[n];
		for (i = 1; i < n; i++)
		{
			diff[i] = abs(a[i] - a[i - 1]);
		}
		ll ans = 1, sum = 1;
		ll prev[n];
		prev[0] = 0;
		for (i = 1; i < n; i++)
		{
			if (__gcd(diff[i], prev[i - 1]) > 1 || __gcd(diff[i], prev[i - 1]) == 0)
			{
				sum++;
				prev[i] = __gcd(diff[i], prev[i - 1]);
			}
			else
			{
				if (diff[i] > 1 || diff[i] == 0)
					prev[i] = diff[i], sum = 2;
				else
					prev[i] = 0, sum = 1;
			}
			ans = max(ans, sum);
		}
		cout << ans << "\n";
	}
	return 0;
}