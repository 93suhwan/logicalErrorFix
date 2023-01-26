#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i<(b); ++i)
#define RFOR(i, b, a) for (int i = (b)-1; i>=(a); --i)
#define FILL(a, b) memset(a, b, sizeof(a))

void dout() { cerr << endl; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

int mod = 1'000'000'007;

int mult(int a, int b)
{
	return (LL)a * b % mod;
}

int binPow(int a, LL n)
{
	int res = 1;
	while(n)
	{
		if(n & 1)
			res = mult(res, a);
		a = mult(a, a);
		n >>= 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	LL n, m, k, r, c;
	cin >> n >> m >> k >> r >> c;
	cout << binPow(k, n * m - r * c) << "\n";
}
