#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define M 1000000007
#define L 100000000000000
#define mp make_pair
#define eps 1e-9
#define int long long
#define float long double
#pragma GCC optimize("Ofast")
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wsign-compare"


int a[500010], b[500110], c[300010], d[300010], n, m;
int mat[2010][2010];
long double S, D, S1, S2, X, Y, tim, te = 0, tt = 0, tt1 = 0;
std::vector<int> pri;
string st1[200010], st, st2, st3;
int modulo(int a, int b = M - 2, int n = M) {
	int x = 1, y = a;
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x * y) % n;
		}
		y = (y * y) % n; // squaring the base
		b /= 2;
	}
	return x % n;
}
vector<int> g[300010];
vector<int> h[100010];

template<class T >
ostream& operator<<(ostream& o, vector<T> v)
{
	for (T x : v)o << x << ' ';
	o << endl;
	return o;
}
template<class T , class T1>
ostream& operator<<(ostream& o, map<T, T1> v)
{
	for (auto x : v)o << x.first << ' ' << x.second << endl;
	o << endl;
	return o;
}
template<class T >
ostream& operator<<(ostream& o, set<T> v)
{
	for (T x : v)o << x << ' ';
	o << endl;
	return o;
}
template<typename T, typename T2>
auto find(T& v, T2 x)
{
	return find(v.begin(), v.end(), x);
}
template<typename T, typename T2>
auto lower_bound(T& v, T2 x)
{
	return lower_bound(v.begin(), v.end(), x);
}
template<typename T, typename T2>
auto upper_bound(T& v, T2 x)
{
	return upper_bound(v.begin(), v.end(), x);
}
template<class T >
ostream& operator<<(ostream& o, multiset<T> v)
{
	for (T x : v)o << x << ' ';
	o << endl;
	return o;
}
template<class T, class T2 >
ostream& operator<<(ostream& o, pair<T, T2> v)
{
	o << v.first << ' ' << v.second << endl;
	return o;
}
template<class T1, class T2>
T2 min(T1 a, T2 b)
{
	return min((T2)a, b);
}
template<class T>
T min(T a, T b, T c)
{
	return min(min(a, b), c);
}
template<class T1, class T2>
T2 max(T1 a, T2 b)
{
	return max((T2)a, b);
}
template<class T>
T max(T a, T b, T c)
{
	return max(max(a, b), c);
}

class UF    {
public:
	int *id, cnt, *sz;

	// Create an empty union find data structure with N isolated sets.
	UF(int N)   {
		cnt = N;
		id = new int[N];
		sz = new int[N];
		for (int i = 0; i < N; i++)  {
			id[i] = i;
			sz[i] = 1;
		}
	}
	~UF()   {
		delete [] id;
		delete [] sz;
	}
	// Return the id of component corresponding to object p.
	int find(int p) {
		int root = p;
		while (root != id[root])
			root = id[root];
		while (p != root) {
			int newp = id[p];
			id[p] = root;
			p = newp;
		}
		return root;
	}
	// Replace sets containing x and y with their union.
	void merge(int x, int y)    {
		int i = find(x);
		int j = find(y);
		if (i == j) return;

		// make smaller root point to larger one
		if   (sz[i] < sz[j])    {
			id[i] = j;
			sz[j] += sz[i];
		} else  {
			id[j] = i;
			sz[i] += sz[j];
		}
		cnt--;
	}
	// Are objects x and y in the same set?
	bool connected(int x, int y)    {
		return find(x) == find(y);
	}
	// Return the number of disjoint sets.
	int count() {
		return cnt;
	}

};

void treefy(int i)
{
	for (int x : g[i])
		g[x].erase(find(g[x].begin(), g[x].end(), i));
	for (int x : g[i])
		treefy(x);
}

void factorial(int *b, int* c, int x = 100000)
{
	b[0] = 1; int i;
	for (i = 1; i <= x + 5; i++)
		b[i] = b[i - 1] * i % M;
	c[x + 2] = modulo(b[x + 2]);
	for (i = x + 1; i > -1; i--)
		c[i] = c[i + 1] * (i + 1) % M;
}
int comb(int n, int r, int* b, int* c)
{
	if (r > n)return 0;
	return b[n] * c[n - r] % M * c[r] % M;
}

long double flor(long double x)
{
	if (abs(x - round(x)) < eps)
		return round(x);
	else return floor(x);
}
int ceil(int x, int y)
{
	return x / y + (x % y != 0);
}
int rond(float x)
{
	int y = round(x);
	if (x - y > 0 && x - y - 0.5 > -eps)
		return y + 1;
	else return y;
}
bool prime(int n)
{
	if (n == 1)return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)return 0;
	return 1;
}
vector<int> primes(int n)
{
	std::vector < int > pr; int i;
	if (n == 1)return pr;
	for ( i = 0; pri[i] * pri[i] <= n; i++)
		while (n % pri[i] == 0)pr.push_back(pri[i]), n /= pri[i];
	if (n > 1)
		pr.push_back(n);
	return pr;
}
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

ostream& operator<<(ostream& o, ordered_set v)
{
	for (int i = 0; i < v.size(); i++)
		o << *v.find_by_order(i) << ' ';
	o << endl;
	return o;
}

void SieveOfEratosthenes(int n)
{
	// Create a boolean array
	// "prime[0..n]" and initialize
	// all entries it as true.
	// A value in prime[i] will
	// finally be false if i is
	// Not a prime, else true.
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples
			// of p greater than or
			// equal to the square of it
			// numbers which are multiple
			// of p and are less than p^2
			// are already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (int p = 2; p <= n; p++)
		if (prime[p])
			pri.push_back(p);
}


int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, j, r, q, u, s1, s2, s3, bb, l, c1, v1, v2, z, c2, n1, nn, x1, hx, hy, tx, ty, n2, js, maxi, i, s, n3, R, mx, p, v, o, m1, t1, k1, k, k2, k3,
	    N, T, y, x3, y3, sq, x2, y1, y2, p1, q1, l1, r1, t2, l2, r2, ans, z1, z2, m2, w, j1, r3, i1, h, x;
	T = 1;
	cin >> T;
	// factorial(d, e, 3e5);
	srand(time(NULL));
	tim = clock(); float ti = 0;
	N = T;
	// SieveOfEratosthenes(1000000);
	while (T--)
	{
		// cout << "Case #" << N - T << ": ";
		cin >> n >> m;
		int pmin[n][m], pmax[n][m], smin[n][m], smax[n][m];
		for (i = 0; i < n; i++) {
			cin >> mat[i][0];
			pmin[i][0] = pmax[i][0] = mat[i][0];
			for (j = 1; j < m; j++) {
				cin >> mat[i][j];
				pmin[i][j] = min(pmin[i][j - 1], mat[i][j]);
				pmax[i][j] = max(pmax[i][j - 1], mat[i][j]);
			}
			smin[i][m - 1] = smax[i][m - 1] = mat[i][m - 1];
			// cout << smax[i][m - 1] << ' ';
			for (j = m - 2; j >= 0; j--) {
				// cout << mat[i][j] << ' ';
				smin[i][j] = min(smin[i][j + 1], mat[i][j]);
				smax[i][j] = max(smax[i][j + 1], mat[i][j]);
				// cout << smax[i][j] << ' ';
			}
			// cout << endl;
		}
		for (k = 1; k < m; k++) {
			multiset<pair<int, int> > pred, pblue, sred, sblue;
			for (i = 0; i < n; i++) {
				pred.insert(mp(pmin[i][k - 1], i));
				sred.insert(mp(smax[i][k], i));
			}
			// cout << pred << endl << sred;
			while (pred.size() > 1) {
				auto p = *pred.begin(); i = p.second;
				pred.erase(p);
				sred.erase(mp(smax[i][k], i));
				pblue.insert(mp(pmax[i][k - 1], i));
				sblue.insert(mp(smin[i][k], i));

				if (sblue.begin()->first > sred.rbegin()->first) {
					cout << "YES\n";
					string ans = string(n, 'R');
					for (auto p : pblue)
						ans[p.second] = 'B';
					cout << ans << ' ' << k << endl;
					goto f;
				}
			}

		}
		cout << "NO\n";







































f:;
	}
	cerr << (clock() - tim) / CLOCKS_PER_SEC << endl;
}