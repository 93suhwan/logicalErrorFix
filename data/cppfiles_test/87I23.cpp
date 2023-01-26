#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define sorta(v) sort(v.begin(),v.end())
#define sortd(v) sort(v.begin(),v.end(),greater<>())
#define mkp make_pair
#define endl "\n"
#define tab "\t"
#define pb push_back
#define mod 1000000007
#define gcd __gcd
#define inf (long long)1e18
ll lcm(ll x, ll y) {return (x * y) / gcd(x, y);}
ll powm(ll a, ll b, ll n) {ll x = 1, y = a; while (b > 0) {if (b % 2 == 1) {x = (x * y) % n; } y = (y * y) % n; b /= 2;} return x % n;}
ll pow(ll x, ll y) { ll res = 1; while (y > 0) { if (y & 1) res = ((res) * (x)); y = y >> 1; x = ((x) * (x)); } return res; }
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
	return (a.second > b.second);
}

void solve()
{
	ll m, n;
	cin >> m >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[0])
			sum += (a[i] - a[0]);
	}
	cout << sum << "\n";
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;
	ll t;
	cin >> t;
	while (t--)
		solve();
}