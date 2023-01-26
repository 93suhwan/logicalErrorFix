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
#define MOD 1000000007
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
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, m, k;
		cin >> n >> m >> k;
		if (n % 2 == 0 and m % 2 == 0)
		{
			cout << "YES" << endl;
		}
		else if (n % 2 == 0 and m % 2 == 1)
		{
			ll x = (n * (m - 1)) / 2;
			if (k % 2 == 0 and k <= x)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
		{
			ll x = (m * (n - 1)) / 2;
			if (m % 4 == 0 and k % 2 == 0 and k >= (m / 2))
			{
				cout << "YES" << endl;
			}
			else if (m % 4 == 2 and k % 2 == 1 and k >= (m / 2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}