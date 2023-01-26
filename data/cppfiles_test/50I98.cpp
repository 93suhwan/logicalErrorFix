#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#ifdef pua_lang

#define 细分 if		 // "specialization"
#define 路径 else	 // "pathway"
#define 闭环 while	 // "closed loop"
#define 三七五 true	 // "3.75", a passing performance evalulation result
#define 三二五 false // "3.25", a failing performance evalulation result
#define 赋能 auto	 // "empower"
#define 抓手 fn		 // "handle", as in getting a handle on things
#define 反哺 return	 // "repay", used in Alibaba as a general term for f
#define 组合拳 Array // "combo move"; not yet a word in the language
#define 载体 Hash	 // "carrier"; not yet a word in the language
#define 对齐 ==		 // "align"
#define 联动 +		 // "linkage"
#define 差异 -		 // "difference"
#define 倾斜 /		 // "tilt"
#define 输出 cout	 // "output"
#define 淘汰 exit	 // "eliminate"
#define 量化 atoi	 // "quantify"
#define 布局 main
#define 规整 int

#endif

#define pi acos(-1)
#define endl '\n'
#define mem(a, b) memset(a, b, sizeof(a))

const LL mo = 1e9 + 7;
const LL mod = 1e9 + 7;

template <class T>
void print(T x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
		// *O++ = '-';
	}
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
	// *O++ = x%10 + '0'
}
// fwrite(obuf,O-obuf,1,stdout);
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf; // 或者用fread更难调的快读
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)

template <class T>
inline void qr(T &n)
{
	n = 0;
	int c = getchar();
	bool sgn = 0;

	while (!isdigit(c))
	{
		if (c == '-')
			sgn ^= 1;
		c = getchar();
	}

	while (isdigit(c))
	{
		n = (n * 10) + (c ^ 0x30);
		c = getchar();
	}

	if (sgn)
		n = -n;
}

struct range
{
	struct _iterator
	{
		int _start;
		int _step;
		_iterator(int from, int step) : _start(from), _step(step) {}
		_iterator(int from) : _start(from), _step(1) {}
		inline bool sign(int x) { return x < 0; }
		bool operator!=(_iterator &b) { return _start != b._start and sign(b._start - _start) == sign(_step); }
		int operator*() { return _start; }
		_iterator &operator++()
		{
			_start += _step;
			return *this;
		}
	};
	_iterator _finish;
	_iterator _begin;
	range(int to) : _begin(0), _finish(to) {}
	range(int from, int to) : _begin(from), _finish(to) {}
	range(int from, int to, int step) : _begin(from, step), _finish(to, step) {}
	_iterator &begin() { return _begin; }
	_iterator &end() { return _finish; }
};
int T;

/* 静态模数类，只能用有符号类型做T和EXT参数 */
template <int mod, class T = int, class EXT = LL>
struct mint
{
	T x;
	template <class TT>
	mint(TT _x)
	{
		x = EXT(_x) % mod;
		if (x < 0)
			x += mod;
	}
	mint() : x(0) {}
	mint &operator++()
	{
		++x;
		if (x == mod)
			x = 0;
		return *this;
	}
	mint &operator--()
	{
		x = (x == 0 ? mod - 1 : x - 1);
		return *this;
	}
	mint operator++(int)
	{
		mint tmp = *this;
		++*this;
		return tmp;
	}
	mint operator--(int)
	{
		mint tmp = *this;
		--*this;
		return tmp;
	}
	mint &operator+=(const mint &rhs)
	{
		x += rhs.x;
		if (x >= mod)
			x -= mod;
		return *this;
	}
	mint &operator-=(const mint &rhs)
	{
		x -= rhs.x;
		if (x < 0)
			x += mod;
		return *this;
	}
	mint &operator*=(const mint &rhs)
	{
		x = EXT(x) * rhs.x % mod;
		return *this;
	}
	mint &operator/=(const mint &rhs)
	{
		x = EXT(x) * inv(rhs.x, mod) % mod;
		return *this;
	}
	mint operator+() const { return *this; }
	mint operator-() const { return mod - *this; }
	friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
	friend mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
	friend mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
	friend mint operator/(const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
	friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.x == rhs.x; }
	friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.x != rhs.x; }
	friend std::ostream &operator<<(std::ostream &o, const mint &m) { return o << m.x; }
	friend std::istream &operator>>(std::istream &i, const mint &m)
	{
		i >> m.x;
		m.x %= mod;
		if (m.x < 0)
			m.x += mod;
		return i;
	}
};
using m998 = mint<998244353>;
using m1e9_7 = mint<1000000007>;
using m1e9_9 = mint<1000000009>;

// #define use_ptr

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>

inline int lowbit(int x)
{
	return x & -x;
}

void solve()
{
	int n;
	qr(n);
	vector<m998> a(1);
	for (auto i : range(n))
	{
		int tmp;
		qr(tmp);
		a.emplace_back(tmp);
	}
	vector<m998> ss(n + 10);
	vector<m998> s(n + 10);
	ss[0] = s[0] = m998(1);
	int stkn = 0;
	m998 oris, exts;
	vector<m998> stk;

	for (auto i : range(1, 1 + n))
	{
		while (stk.size() and a[stk.back().x].x >= a[i].x)
			stk.pop_back();
		if (stk.size())
		{
			if ((i ^ stk.back().x) & 1)
				oris = m998(-s[stk.back().x].x);
			else
				oris = s[stk.back().x];
			exts = ss[i - 1] - ss[stk.back().x - 1];
			if ((i ^ 1) & 1)
				exts = m998(-exts.x);
			s[i] = oris + exts * a[i];
		}
		else
			s[i] = (i & 1 ? ss[i - 1] : m998(-ss[i - 1].x)) * a[i];
		if (i & 1)
			ss[i] = ss[i - 1] - s[i];
		else
			ss[i] = ss[i - 1] + s[i];
		stk.emplace_back(i);
	}
	cout << s[n].x << endl;
}

signed main()
{
	T = 1;
	while (T--)
		solve();
	return 0;
}
/*
500 12
1 1 59 100 200 100000004
4 40 100
3 23 89
2 1 100 784964
3 100 120
4 55 156
2 5 5 2
3 5 5
1 1 5 200 2 100
4 5 5
4 4 5
1 4 125 21345 47845 4152644

*/