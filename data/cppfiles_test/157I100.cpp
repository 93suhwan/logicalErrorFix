#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define vs vector<string>
#define pb push_back
#define ll long long
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
vs tokenizer(string str, char ch) {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
#define MOD 998244353
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll modpow(ll x, ll n, ll m)
{
	if (n == 0) return 1 % m;
	ll u = modpow(x, n / 2, m);
	u = (u * u) % m;
	if (n % 2 == 1) u = (u * x) % m;
	return u;
}
ll powerRecursive(ll a, ll b)
{
	//base case
	if (b == 0)return 1;
	if (b == 1)return a;
	ll temp = powerRecursive(a, b / 2);
	if (b % 2 == 0)
		return temp * temp;
	else
		return a * temp * temp;
}
ll CEIL(ll a, ll b)
{
	if (a % b == 0)
		return a / b;
	return a / b + 1;
}
ll power(ll x, ll y, ll p)
{
	ll res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}
ll modInverse(ll n, ll p)
{
	return power(n, p - 2, p);
}
ll nCrModPFermat(ll n, ll r, ll p)
{
	if (n < r)
		return 0;
	if (r == 0)
		return 1;
	ll fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;
	return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
int main()
{
	clock_t begin = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, k;
	cin >> n >> k;
	vector<ll> ans(n, 0);
	string s;
	cin >> s;
	for (int i = 1; i < n; i++)
	{
		if (s[i] == '0')
		{
			int cnt = 0, len = 0, flag = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				if (s[j] == '1')
					cnt++;
				len++;
				if (cnt == k + 1)
				{
					flag = 1;
					break;
				}
			}
			if (cnt == k)
				len++;
			if (flag == 1 or cnt == k)
				ans[i] = (ans[i - 1] + (nCrModPFermat(len, k, MOD) - nCrModPFermat(len - 1, k, MOD) + MOD) % MOD) % MOD;
			else
				ans[i] = ans[i - 1];
		}
		else
		{
			int cnt = 0, len = 0, flag = 0, zeros;
			for (int j = i - 1; j >= 0; j--)
			{
				if (s[j] == '1')
					cnt++;
				len++;
				if (cnt == k)
				{
					flag = 1;
					break;
				}
			}
			zeros = len - k;
			//log(cnt, flag, len, zeros);
			if (flag == 1 and zeros >= 1 and (k + zeros - 1) != 0)
				ans[i] = (ans[i - 1] + nCrModPFermat(k + zeros - 1, zeros - 1, MOD)) % MOD;
			else
				ans[i] = ans[i - 1];
		}
	}
	//logarr(ans, 0, n - 1);
	ll ans2 = (ans[n - 1] + 1) % MOD;
	cout << ans2 << "\n";
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}