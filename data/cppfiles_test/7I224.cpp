#include <bits/stdc++.h>

using namespace std;

#define int  long long
#define MOD 998244353
#define pb push_back
#define mp make_pair
#define PI     2*acos(0)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fill(a,val)     memset(a,val,sizeof(a))
#define rev(x) x.rbegin(),x.rend()
#define set_bits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x, y) fixed << setprecision(y) << x
#define make2dvec(name,n,m,val) vector<vector<int>>name(n, vector<int>(m, val));
#define kota(v,n) v.reserve(n)
const int mod = 1e9 + 7;
#define indl '\n'
#define INF (int)1e18

/* Debug Begins */
# define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
  stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
string to_string(char c) { return "" + string(1, c) + "";}
string to_string(string s) { return "" + s + "";}
string to_string(bool f) { if (f) return "True"; else return "False";}
string to_string(const char* s) { return to_string((string) s);}
template<typename A> string to_string(A);
template<typename A, typename B> string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";
}
template<typename A> string to_string(A v) {
	bool f = false; string r = "{";
	for (auto x : v) {if (f) r += ", "; r += to_string(x); f = true;} return r += "}";
}
template<typename A> string to_string(vector<vector<A>> v) {
	string r;
	for (auto x : v) r += "\n" + to_string(x); return r;
}
int Nerr;
template<typename A> string to_string(A *p) {return to_string(vector<A>(p, p + Nerr));}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << to_string(a) << "; "; err(++it, args...);
}
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
#define Lu(...) [&] (auto &&u) { return __VA_ARGS__; }
#define Luv(...) [&] (auto &&u, auto &&v) { return __VA_ARGS__; }
/***************************************************************/
template<typename T>
class SegmentTree
{
	T V;
	vector<T>tree;
public:
	SegmentTree(vector<T>&a, T V)
	{
		this->V = V;
		tree.assign(4 * V + 1, 0);
		buildTree(0, V - 1, a, 1);

	}

	void buildTree( T s, T e, vector<T>&a, T index)
	{
		if (s == e)
		{
			tree[index] = a[s];
			return;
		}
		T mid =  (e + s) >> 1;
		buildTree(s, mid, a, 2 * index);
		buildTree(mid + 1, e, a, 2 * index + 1);
		tree[index] = __gcd(tree[2 * index], tree[2 * index + 1]);
	}

	T quarry(T qs, T qe, T s, T e, T index)
	{
		if (s >= qs and qe >= e)
		{
			return tree[index];
		}
		if (qe < s || qs > e)
		{
			return 0;
		}
		T mid = (e + s) >> 1;
		T left = quarry(qs, qe, s, mid, 2 * index);
		T right  = quarry(qs, qe, mid + 1, e, 2 * index + 1);
		return   __gcd(left, right);
	}

};
void solve()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	if (n == 1) {cout << 1 << indl; return;}
	vector<int>b(n - 1);
	for (int i = 0; i < n - 1; ++i)
	{
		b[i] = abs(a[i] - a[i + 1]);
	}

	SegmentTree<int>sg(b, n - 1);
	auto can = [&](int k) {
		for (int i = 0; i + k - 1 < n; ++i)
		{
			if (sg.quarry(i, i + k - 2, 0, n - 2, 1) != 1) {return true;}
		}
		return false;
	};
	int l = 2, r = n, ans = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (can(m)) {
			ans = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	cout << ans << '\n';

}

signed main()
{

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int testcase = 1;
	cin >> testcase;
	for (int tt = 1; tt <= testcase; tt++)
	{
		solve();
	}

}