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

const int mod = 1'000'000'007;

void updAdd(int& x, int val)
{
	x += val;
	if(x >= mod)
		x -= mod;
}

void updSub(int& x, int val)
{
	x -= val;
	if(x < 0)
		x += mod;
}

int mult(int a, int b)
{
	return (LL)a * b % mod;
}

const double PI = acos(-1.0);

namespace FFT{
	struct complex{
		double x, y;
		complex() { x = y = 0; }
		complex(double _x, double _y) : x(_x), y(_y) { }
	};

	inline complex operator+(complex a, complex b) { return complex(a.x + b.x, a.y + b.y); }
	inline complex operator-(complex a, complex b) { return complex(a.x - b.x, a.y - b.y); }
	inline complex operator*(complex a, complex b) { return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
	inline complex conj(complex a) { return complex(a.x, -a.y); }

	int base = 1;
	vector<complex> roots = { { 0, 0 },{ 1, 0 } };
	vector<int> rev = { 0, 1 };

	void ensure_base(int nbase){
		if (nbase <= base)
			return;

		rev.resize(1 << nbase);
		FOR(i, 0, 1 << nbase)
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

		roots.resize(1 << nbase);
		while (base < nbase){
			double angle = 2.0 * PI / (1 << (base + 1));
			FOR(i, 1 << (base - 1), 1 << base){
				roots[i << 1] = roots[i];
				double angle_i = angle * (2 * i + 1 - (1 << base));
				roots[(i << 1) + 1] = complex(cos(angle_i), sin(angle_i));
			}

			base++;
		}
	}

	void fft(vector<complex>& a, int n = -1){
		if (n == -1)
			n = a.size();

		int zeros = __builtin_ctz(n);
		ensure_base(zeros);

		int shift = base - zeros;
		FOR(i, 0, n)
			if (i < (rev[i] >> shift))
				swap(a[i], a[rev[i] >> shift]);

		for (int k = 1; k < n; k <<= 1){
			for (int i = 0; i < n; i += 2 * k){
				FOR(j, 0, k){
					complex z = a[i + j + k] * roots[j + k];
					a[i + j + k] = a[i + j] - z;
					a[i + j] = a[i + j] + z;
				}
			}
		}
	}

	vector<complex> fa, fb;

	void multiply(VL&a, VL&b, VL& res){
		int need = SZ(a) + SZ(b) - 1;
		int nbase = 0;

		while ((1 << nbase) < need)
			nbase++;

		ensure_base(nbase);
		int sz = 1 << nbase;

		if (sz > SZ(fa))
			fa.resize(sz);

		FOR(i, 0, sz){
			int x = (i < SZ(a) ? a[i] : 0);
			int y = (i < SZ(b) ? b[i] : 0);
			fa[i] = complex(x, y);
		}

		fft(fa, sz);
		complex r(0, -0.25 / sz);
		FOR(i, 0, (sz >> 1) + 1){
			int j = (sz - i) & (sz - 1);
			complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
			if (i != j)
				fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;

			fa[i] = z;
		}

		fft(fa, sz);
		res.resize(need);
		FOR(i, 0, need)
			if (fa[i].x > 0)
				res[i] = fa[i].x + 0.5;
			else
				res[i] = fa[i].x - 0.5;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(int& ai: a)
		cin >> ai;
	if(m == 2)
	{
		FOR(i, 0, n)
			a.push_back(a[i]);
		n *= 2;
		m = 1;
	}
	int s = accumulate(ALL(a), 0LL) % k, ms = (LL)m * s % k;
	vector<LL> cPref(k), cSuf(k), c;
	int ans = 0;
	int pref = 0;
	cPref[0] = 1;
	FOR(i, 0, n)
	{
		(pref += a[i]) %= k;
		if(m > 1 || i < n - 1)
		{
			updAdd(ans, cPref[pref]);
			updAdd(ans, cPref[((pref - ms) % k + k) % k]);
		}
		cPref[pref]++;
	}
	if(m == 1 && s == 0)
		updAdd(ans, 1);
	cPref[pref]--;
	int suf = 0;
	RFOR(i, n, 0)
	{
		cSuf[suf]++;
		(suf += a[i]) %= k;
	}
	auto cPrefSaved = cPref;
	cPref[0]--;
	cSuf[0]--;
	if(m > 1)
		FOR(x, 0, k)
			updAdd(ans, mult(cPref[x], cSuf[(k - x) % k]));
	cPref[0]++;
	cSuf[0]++;
	FFT::multiply(cPref, cSuf, cPref);
	while(SZ(cPref) > k)
	{
		cPref[(SZ(cPref) - 1) % k] += cPref.back();
		cPref.pop_back();
	}
	for(LL& x: cPref)
		x %= mod;
	FOR(i, 1, m - 1)
		updAdd(ans, cPref[((-i * s) % k + k) % k]);
	if(s == 0)
		updSub(ans, 1);
	cPref = cPrefSaved;
	FFT::multiply(cPref, cSuf, cPref);
	ans = mult(ans, m);
	updAdd(ans, ms == 0);
	cout << ans << "\n";
}
