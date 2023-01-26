#include <iostream>
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back 
#define endl '\n'
#define F first
#define S second
#define sz size()
#define all(x) (x).begin(),(x).end()
#define print(x) cout << x << endl
#define pii pair<int,int>
typedef long long int ll;
typedef long double  ld;



using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

const ll mod = 1e9 + 7LL;

template<typename T>
T Max(T a, T b) {
	return a >= b ? a : b;
}

template<typename T>
T Min(T a, T b) {
	return a <= b ? a : b;
}

bool prime(ll x) {
	if (x == 2 or x == 3) return true;
	if (x <= 4 or x % 2 == 0 or x % 3 == 0) return false;
	for (ll i{ 5 }; (ll)i * i <= x; i += 6) {
		if (x % (i + 2LL) == 0 or x % i == 0) return false;
	}
	return true;
}
ll power(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2 == 0)
		return power(x, y / 2) * power(x, y / 2);
	else
		return x * power(x, y / 2) * power(x, y / 2);
}

ll floor_div(const ll& a, const ll& b)
{
	return a / b - (((a ^ b) < 0) and a % b);
}
ll ceil_div(const ll& a, const ll& b)
{
	return a / b + (((a ^ b) >= 0) and a % b);
}

template<typename T>
void printarray(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
template<typename T>
void printvector(std::vector<T>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << ' ';
	}
	std::cout << endl;
}

template<typename T> 
T gcd(T a, T b)
{
	if(b == 0)
		return a;
	else return gcd(b , a%b);
}


void solve()
{
	int n;
	char c;
	cin >> n >> c;
	string s;
	cin >> s;
	int cnt = count(all(s),c);
	//cout << "ajdj " << cnt << '\n';
	if(s[n-1] == c)
	{
		if(cnt < n)
		{
			print(1);
			print(n);
		}
		else
			print(0);
	}
	else
	{
		if(cnt == n-1)
		{
			print(1);
			print(n);
		}
		else
		{
			print(2);
			cout << n-1 << " " << n << '\n';
		}
	}
	return;
}

int main()
{ 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t = 1 ;
	cin >> t;
	while(t--){
		solve();
	} 

}   