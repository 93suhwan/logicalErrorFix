#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(a, b, c, d) for(ll a = b; a < c; a += d)
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define pq priority_queue

void solve()
{
	ll n;
	cin >> n;
	ll a[n + 1] = {};
	vector<ll> v;
	f(i, 0, n, 1)
	{
		ll num;
		cin >> num;
		if (num <= n)
		{
			if (a[num])
				v.pb(num);
			else
				a[num] = 1;
		}
		else
			v.pb(num);
	}
	if (v.empty())
	{
		cout << "0\n";
		return;
	}
	ll ans = 0;
	sort(v.begin(), v.end());
	for (ll i = n; i >= 1; --i)
	{
		if (a[i])
			continue;
		if (v.back() - i > v.back() / 2)
			ans++;
		else
		{
			cout << "-1\n";
			return;
		}
	}
	cout << ans << "\n";
}

signed main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t = 1;
	cin >> t;
	while (t--)
		solve();
}