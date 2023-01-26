#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<list>
#include<deque>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<numeric>
#include<bitset>
#include<iomanip>


using namespace std;

#ifdef _DEBUG
#define prnt(a) cout<<#a<<"="<<a<<endl
#else
#define prnt(a) (void)0
#endif // _DEBUG

#define ll long long
#define ld long double
#define INF (1LL<<30)
#define INFLL (1LL<<60)
#define MOD 1000000007
#define MOD2 998244353
#define rep(i,st,en) for(int i=st;i<en;++i)
#define vld vector<ld>
#define vll	vector<ll>
#define vvll	vector<vll>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define pii	pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define VS vector<string>
#define MY_PI           3.141592653589793238462643383279502884L
#define all(v) (v).begin(), (v).end()

#define rd(...) __VA_ARGS__; read(__VA_ARGS__)
#define rdv(value,...) value(__VA_ARGS__);cin >> value
template <class T> auto& operator>>(istream& is, vector<T>& xs) {
	for (auto& x : xs) is >> x;
	return is;
}
template <class T> auto& operator<<(ostream& os, vector<T>& xs) {
	int sz = xs.size();
	rep(i, 0, sz) os << xs[i] << " \n"[i + 1 == sz];
	return os;
}
template <class T, class Y> auto& operator<<(ostream& os, pair<T, Y>& xs) {
	os << "{" << xs.first << ", " << xs.second << "}";
	return os;
}
template <class T, class Y> auto& operator>>(istream& is, vector<pair<T, Y>>& xs) {
	for (auto& [x1, x2] : xs) is >> x1 >> x2;
	return is;

}
template <class  ...Args>
auto& read(Args & ...args) { return (cin >> ... >> args); }

#define write(...) writemy(__VA_ARGS__);cout<<"\n"
void writemy() {}
template <typename Head, class  ...Args>
void writemy(const Head& head, const Args & ...args) {
	cout << head << " ";
	writemy(args...);
}



class UnionFindTree {
public:
	vector<int> parent;
	vector<int> union_size;
	vector<ll> w;
	int len;
	ll value = 0;

	UnionFindTree(int n) {
		len = n;
		parent.resize(n + 1, 0);
		w.resize(n + 1, 0);
		union_size.resize(n + 1, 1);
		value = 0;
		rep(i, 0, n + 1) parent[i] = i;
	}

	int root(int a) {
		if (parent[a] == a)
			return a;
		parent[a] = root(parent[a]);
		return parent[a];
	}

	void setWeight(int a, ll we) {
		w[a] = we;
	}

	ll getWeight(int a) {
		int ra = root(a);
		return w[ra];
	}

	bool join(int a, int b) {
		int ra = root(a);
		int rb = root(b);
		if (ra == rb)
			return false;
		if (union_size[ra] > union_size[rb]) {
			parent[rb] = ra;
			union_size[ra] += union_size[rb];
			w[ra] += w[rb];
		}
		else {
			parent[ra] = rb;
			union_size[rb] += union_size[ra];
			w[rb] += w[ra];
		}
		len--;
		return true;
	}

	int size(int a) {
		return union_size[root(a)];
	}

};

template <typename T>
class segmentTree {
public:
	vector<T> v;
	int n;
	T(*func)(T, T);
	T defval = 0;

	segmentTree(int s, T(*f)(T, T)) {
		n = 1;
		while (n < s) n *= 2;
		v.resize(2 * n, defval);
		func = f;
	}
	/// <summary>
	/// use this before calculateTree()
	/// index starts 0
	/// </summary>
	void setNode(int ind, T val) {
		v[ind + n - 1] = val;
	}

	ll calculateTree() {
		for (int i = n - 2; i >= 0; i--)
			v[i] = func(v[i * 2 + 1], v[i * 2 + 2]);
		return v[0];
	}
	/// <summary>
	/// add val to value[index]
	/// index starts 0
	/// </summary>
	void addValue(int ind, T val) {
		updateNode(ind, val + v[ind + n - 1]);
	}

	T getValue(int ind) {
		return v[ind + n - 1];
	}
	/// <summary>
	/// set value[ind] to val
	/// index starts 0
	/// </summary>
	void updateNode(int ind, T val) {
		v[ind + n - 1] = val;
		for (int i = (ind + n - 2) / 2; i != 0; i = (i - 1) / 2) {
			v[i] = func(v[i * 2 + 1], v[i * 2 + 2]);
		}
		v[0] = func(v[1], v[2]);
	}

	/// <summary>
	/// query sum of [l,r] from [st,en] range
	/// </summary>
	/// <returns></returns>
	T queryInternal(int ind, int st, int en, int l, int r) {
		if (st >= l && en <= r)
			return v[ind];
		if (l > en || r < st)
			return defval;
		int mid = st + (en - st) / 2;
		return func(queryInternal(ind * 2 + 1, st, mid, l, r),
			queryInternal(ind * 2 + 2, mid + 1, en, l, r));
	}

	/// <summary>
	/// returns sum between [l,r]
	/// index starts 0
	/// </summary>
	T query(int l, int r) {
		if (l > r)
			return 0;
		return queryInternal(0, 0, n - 1, l, r);
	}

	/// <summary>
	/// returns minimum x which is SUM(0,x) >= sum
	/// ind should be 0
	/// </summary>
	int querySumIndex(int ind, ll sum) {
		int left, right;
		left = ind * 2 + 1;
		right = left + 1;
		if (ind >= n - 1) {
			return (ind - n + 1);
		}
		//if (v[ind] < sum)
		//	return 0;
		if (v[left] >= sum) {
			return querySumIndex(left, sum);
		}
		else {
			return querySumIndex(right, sum - v[left]);
		}
	}
};

template <typename T> T my_gcd(T a, T b) { return gcd(a, b); }
template <typename T> T my_min(T a, T b) { return min(a, b); }
template <typename T> T my_max(T a, T b) { return max(a, b); }
template <typename T> T my_and(T a, T b) { return (a & b); }
template <typename T> T my_xor(T a, T b) { return (a ^ b); }
template <typename T> T my_or(T a, T b) { return (a | b); }
template <typename T> T my_sum(T a, T b) { return (a + b); }
template <typename T> T my_sum_mod(T a, T b) { return (a + b) % MOD; }

/// <summary>
/// index starts 0
/// </summary>
class SparseTable {

public:
	vvll table;
	ll(*func)(ll, ll);
	ll deep = 0;

	SparseTable(vector<ll> vec, ll(*f)(ll, ll)) {
		this->func = f;
		ll s = vec.size();
		deep = floor(log2(s));
		table.resize(deep + 1);
		table[0].resize(s);
		rep(i, 0, s)
			table[0][i] = vec[i];
		rep(k, 1, deep + 1) {
			ll g = pow(2, k - 1);
			table[k].resize(s);
			rep(i, 0, s - (g * 2 - 1)) {
				table[k][i] = f(table[k - 1][i], table[k - 1][i + g]);
			}
		}
	}

	/// <summary>
	/// index starts 0
	/// </summary>
	/// <param name="st">index of start pos</param>
	/// <param name="size">size of query</param>
	/// <returns></returns>
	ll query(ll st, ll size) {
		ll g = floor(log2(size));
		ll ret = this->func(table[g][st], table[g][st + size - pow(2, g)]);
		return ret;
	}

};

/// <summary>
/// index starts 1
/// </summary>
class BITree {
public:
	vector<ll> v;
	int sz;

	BITree(int n) {
		v.resize(n + 1, 0);
		sz = n;
	}

	void add(int ind, ll val) {
		int i = ind;
		while (i <= sz) {
			v[i] += val;
			i += (i & (-i));
		}
	}

	ll query(int ind) {
		ll r = 0;
		int i = ind;
		if (i > sz) i = sz;
		while (i > 0) {
			r += v[i];
			i -= (i & (-i));
		}
		return r;
	}
};


vll fact, invfact, inv;
void initFacts(ll n, ll m) {
	fact.resize(n + 1);
	invfact.resize(n + 1);
	inv.resize(n + 1);
	fact[0] = 1;
	invfact[0] = 1;
	inv[0] = 1;
	inv[1] = 1;
	rep(i, 1, n + 1) {
		fact[i] = (fact[i - 1] * i) % m;
	}
	rep(i, 2, n + 1) {
		inv[i] = -inv[m % i] * (m / i) % m;
		if (inv[i] < 0) inv[i] += m;
	}
	rep(i, 1, n + 1) {
		invfact[i] = invfact[i - 1] * inv[i] % m;
	}
}

ll nCk(ll n, ll k, ll m) {
	if (k > n) return 0;
	if (k < 0) return 0;
	if (k == 0) return 1LL;
	ll v = (((fact[n] * invfact[k]) % m) * invfact[n - k]) % m;
	return v;
}

ll modInverse(ll a, ll m)
{
	ll m0 = m;
	ll y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1) {
		// q is quotient
		int q = a / m;
		int t = m;

		// m is remainder now, process same as
		// Euclid's algo
		m = a % m, a = t;
		t = y;

		// Update y and x
		y = x - q * y;
		x = t;
	}

	// Make x positive
	if (x < 0)
		x += m0;

	return x;
}


class LazyPart {
public:
	ll val = 0;

	LazyPart() {
	}

	LazyPart(ll aa) {
		val = aa;
	}

	LazyPart& operator=(const LazyPart& other) {
		val = other.val;
		return *this;
	}

	void reset() {
		val = 0;
	}
};

class LazyReal {
public:
	ll val = 0;

	LazyReal() {
		val = 0;
	}

	LazyReal(int v) {
		val = v;
	}

	LazyReal& operator=(const LazyReal& other) {
		val = other.val;
		return *this;
	}

	void reset() {
		val = 0;
	}
};


class lazySegmentTree {
public:
	vector<LazyReal> v;
	vector<LazyPart> z;
	LazyReal dummyReal;
	LazyPart dummyLazy;

	vb islazy;
	int n;
	LazyReal defval = dummyReal;

	lazySegmentTree() {
	}

	lazySegmentTree(int size) {
		n = 1;
		while (n < size) n *= 2;
		v.resize(2 * n, dummyReal);
		z.resize(2 * n, dummyLazy);
		islazy.resize(2 * n, false);
	}

	lazySegmentTree(int size, LazyReal defReal, LazyPart deflazy) {
		n = 1;
		while (n < size) n *= 2;
		defval = defReal;
		v.resize(2 * n, defReal);
		z.resize(2 * n, deflazy);
		islazy.resize(2 * n, false);
	}

	//gol function
	//a-ni urd taliih
	//need to implement
	LazyReal func(LazyReal& a, LazyReal& b) {
		LazyReal r = dummyReal;
		r.val = a.val + b.val;
		return r;
	}

	//a-g b-eer shinechlene.
	//need to implement
	void applyLazy(LazyReal& a, LazyPart& b, int len) {
		a.val += b.val;
	}
	//a-g b-eer shinechlene.
	//need to implement
	void passDownLazy(LazyPart& a, LazyPart& b) {
		a.val += b.val;
	}


	void passDown(int ind, ll len) {
		if (!islazy[ind]) return;
		LazyPart t = z[ind];
		z[ind].reset();
		//update current value
		applyLazy(v[ind], t, len);
		islazy[ind] = false;

		if (ind >= n - 1) return;

		//update lazy part of childs
		int d = ind * 2 + 1;
		passDownLazy(z[d], t);
		islazy[d] = true;
		d = ind * 2 + 2;
		passDownLazy(z[d], t);
		islazy[d] = true;
	}

	void setNode(int ind, LazyReal val) {
		v[ind + n - 1] = val;
	}

	void calculateTree() {
		for (int i = n - 2; i >= 0; i--)
			v[i] = func(v[i * 2 + 1], v[i * 2 + 2]);
	}

	LazyReal queryInternal(int ind, int st, int en, int us, int ue) {
		passDown(ind, en - st + 1);
		if (ue < st || en < us) return defval;
		if (us <= st && en <= ue) return v[ind];
		int mid = st + (en - st) / 2;
		LazyReal t1 = queryInternal(ind * 2 + 1, st, mid, us, ue);
		LazyReal t2 = queryInternal(ind * 2 + 2, mid + 1, en, us, ue);
		return func(t1, t2);
	}

	LazyReal query(int us, int ue) {
		return  queryInternal(0, 0, n - 1, us, ue);
	}

	void updateRangeInternal(int ind, int st, int en, int us, int ue, LazyPart val) {
		passDown(ind, en - st + 1);
		if (ue < st || en < us) return;
		if (us <= st && en <= ue) {
			z[ind] = val;
			islazy[ind] = true;
			passDown(ind, en - st + 1);
			return;
		}
		int mid = st + (en - st) / 2;
		updateRangeInternal(ind * 2 + 1, st, mid, us, ue, val);
		updateRangeInternal(ind * 2 + 2, mid + 1, en, us, ue, val);
		v[ind] = func(v[ind * 2 + 1], v[ind * 2 + 2]);
		return;
	}

	void updateRange(int us, int ue, LazyPart val) {
		updateRangeInternal(0, 0, n - 1, us, ue, val);
	}

};

ll lis(vll& v, ll maxVal) {
	int n = v.size();
	vll dp(n, maxVal);
	for (int i = 0; i < n; i++) {
		//not acceptable same number
		//int x = (upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin());
		//accept same number
		int x = (lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin());
		dp[x] = v[i];
	}
	return (lower_bound(dp.begin(), dp.end(), maxVal) - dp.begin());
}



vector<ll> primes;
void findPrimes(int max_val) {
	primes.push_back(2);
	primes.push_back(3);
	for (ll i = 5; i <= max_val; i += 2) {
		int j = 0;
		ll max_val = sqrt(i);
		bool isprime = true;
		while (primes[j] <= max_val) {
			if (i % primes[j] == 0) {
				isprime = false;
				break;
			}
			j++;
		}
		if (isprime)
			primes.push_back(i);
	}
}

ll phi(ll n) {
	ll ans = n;
	ll i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			ans -= ans / i;
			while (n % i == 0)
				n /= i;
		}
		i++;
	}
	if (n != 1)
		ans -= ans / n;
	return ans;
}

ll bigPow(ll a, ll d, ll m) {
	if (a % m == 0) return 0;
	if (d == 0) return 1LL;
	ll r = bigPow(a, d / 2, m);
	r = (r * r) % m;
	if ((d % 2) == 1)
		r = (r * a) % m;
	return r;
}

ll nCk2(ll n, ll k, ll m) {
	if (n == 0) return 1;
	if (k == 0) return 1;
	if (n < k) return 1;
	ll v = 1;
	ll p = 1;
	rep(i, 0, k) {
		v = (v * (n - i)) % m;
		p = (p * (i + 1)) % m;
	}
	p = modInverse(p, m);
	v = (v * p) % m;
	return v;
}

vll u;

int qstn2(ll a, ll b, ll c) {
	int r = 0;
	r = u[a] + u[b] + u[c];
	if (r > 0) return 1;
	return 0;
}

int qstn(ll a, ll b, ll c) {
	cout <<"? "<< a << " " << b << " " << c<<endl;
	int r;
	cin >> r;
	return r;
}

void solve(int test) {
	ll rd(n);
	vvll a, b;
	for (int i = 1; i < n; i += 3) {
		ll qa = qstn(i, i + 1, i + 2);
		vll t = { i,i + 1,i + 2 };
		if (qa == 1) {
			a.push_back(t);
		}
		else {
			b.push_back(t);
		}
	}
	vll ans(n + 1, -1);
	
	vll aa, bb;
	aa = a[0];
	bb = b[0];
	ll a0 = qstn(aa[0], aa[1], bb[0]);
	ll a1 = qstn(aa[0], aa[1], bb[1]);
	ll a2 = qstn(aa[0], aa[1], bb[2]);
	ll suma = a1 + a2 + a0;
	ll crew, imposter;
	if (suma == 0) {
		crew = aa[2];
		imposter = bb[0];
		ans[aa[2]] = 1;
		ans[bb[0]] = 0;
		ans[bb[1]] = 0;
		ans[bb[2]] = 0;
	}
	else if (suma == 1) {
		ans[aa[2]] = true;
		crew = aa[2];
		ans[bb[0]] = a0;
		ans[bb[1]] = a1;
		ans[bb[2]] = a2;
		rep(i, 0, 3) {
			if (ans[bb[i]]==0) {
				imposter = bb[i];
				break;
			}
		}
	}
	else if(suma==2){
		 //impossible
	}
	else if (suma == 3) {
		ans[aa[0]] = 1;
		ans[aa[1]] = 1;
		crew = aa[0];
		ll b2 = qstn(bb[0], bb[1], crew);
		ll b1 = qstn(bb[0], bb[2], crew);
		ll b0 = qstn(bb[1], bb[2], crew);
		ll sumb = b0 + b1 + b2;
		if (sumb == 0) {
			imposter = bb[0];
			ans[bb[0]] = 0;
			ans[bb[1]] = 0;
			ans[bb[2]] = 0;
		}
		else if (sumb == 2) {
			if (b0 == 0) {
				imposter = bb[1];
				ans[bb[1]] = 0;
				ans[bb[2]] = 0;
				ans[bb[0]] = 1;
			}
			else if (b1 == 0) {
				imposter = bb[0];
				ans[bb[1]] = 1;
				ans[bb[2]] = 0;
				ans[bb[0]] = 0;
			}
			else {
				imposter = bb[0];
				ans[bb[1]] = 0;
				ans[bb[2]] = 1;
				ans[bb[0]] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] >= 0) continue;
		ans[i] = qstn(crew, imposter, i);
	}
	vll h;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) h.push_back(i);
	}
	cout << "! " << h.size();
	for (auto i : h) {
		cout << " " << i;
	}
	cout << "\n";
	cout.flush();
}

int main() {
	//freopen("input.txt", "r", stdin);
	//ios::sync_with_stdio(0); cin.tie(0);
	int test = 1;
	cin >> test;
	for (int t = 1; t <= test; t++)
		solve(0);
	return 0;
}
