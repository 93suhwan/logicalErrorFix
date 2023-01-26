#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
template <typename T>
void Read(T &x) {
  x = 0;
  char ch = getchar();
  int64_t f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
int64_t __gcd(T a, T b) {
  return b ? __gcd(b, a % b) : a;
}
template <typename T>
int64_t __lcm(T a, T b) {
  return a / __gcd(a, b) * b;
}
template <typename T>
int64_t __ceil(T a, T b) {
  return (a + b - 1) / b;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t __rand(int64_t a, int64_t b) { return a + rng() % (b - a + 1); }
inline int64_t QuickPow(int64_t base, int64_t exp, int64_t Mod = 0) {
  int64_t ret(1);
  while (exp) {
    if (exp & 1) {
      ret *= base;
      if (Mod) ret %= Mod;
    }
    base *= base;
    if (Mod) base %= Mod;
    exp >>= 1;
  }
  return Mod ? ret % Mod : ret;
}
inline int64_t exgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int64_t gcd = exgcd(b, a % b, x, y);
  tie(x, y) = make_tuple(y, x - (a / b) * y);
  return gcd;
}
inline int64_t __inv(int64_t x, int64_t p) {
  int64_t a, b;
  int64_t gcd = exgcd(x, p, a, b);
  return gcd == 1 ? (a % p + p) % p : -1;
}
class DSU {
 public:
  std::vector<int> p, size;
  int n, setCount;
  DSU(int _n) : n(_n), setCount(_n), p(_n), size(_n, 1) {
    std::iota(p.begin(), p.end(), 0);
  }
  int find(int x) { return p[x] = x == p[x] ? x : find(p[x]); }
  bool unite(int x, int y) {
    if (size[x] < size[y]) return unite(y, x);
    return p[y] = x, size[x] += size[y], --setCount, true;
  }
  bool helper(int x, int y) {
    int pX = find(x), pY = find(y);
    return pX != pY ? unite(pX, pY) : false;
  }
};
class BIT {
 public:
  BIT(int size) : n(size), tree(size + 10, 0LL) {}
  virtual ~BIT() { tree.clear(); }
  std::vector<int64_t> tree;
  int n;
  int lowbit(int x) { return ((x) & -(x)); }
  void update(int64_t x, int64_t d) {
    while (x <= n) {
      tree[x] += d;
      x += lowbit(x);
    }
  }
  int64_t query(int x) {
    int64_t res = 0;
    while (x > 0) {
      res += tree[x];
      x -= lowbit(x);
    }
    return res;
  }
};
class SegmentTree {
 public:
  struct node {
    int64_t l, r;
    int64_t sum;
    int64_t dat;
    int64_t lazy;
  };
  std::vector<node> tree;
  std::vector<int64_t> arr;
  int n;
  SegmentTree(int _n, vector<int64_t> a) : n(_n), tree(_n << 2), arr(a) {
    Build(1, 1, n);
  }
  void PushUp(int64_t p) {
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].dat = max(tree[p << 1].dat, tree[p << 1 | 1].dat);
  }
  void AddTag(int64_t p, int64_t d) {
    tree[p].sum += d * (tree[p].r - tree[p].l + 1);
    tree[p].lazy += d;
    tree[p].dat += d;
  }
  void PushDown(int64_t p) {
    if (tree[p].lazy) {
      AddTag(p << 1, tree[p].lazy);
      AddTag(p << 1 | 1, tree[p].lazy);
      tree[p].lazy = 0;
    }
  }
  void Build(int64_t p, int64_t l, int64_t r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
      tree[p].sum = tree[p].dat = arr[l];
      return;
    }
    int64_t mid = (l + r) >> 1;
    Build(p << 1, l, mid);
    Build(p << 1 | 1, mid + 1, r);
    PushUp(p);
  }
  void Change(int64_t p, int64_t l, int64_t r, int64_t d) {
    if (l <= tree[p].l && r >= tree[p].r) {
      tree[p].sum += (int64_t)d * (tree[p].r - tree[p].l + 1);
      tree[p].lazy += d;
      tree[p].dat += d;
      return;
    }
    PushDown(p);
    int64_t mid = (tree[p].l + tree[p].r) / 2;
    if (l <= mid) Change(p << 1, l, r, d);
    if (r > mid) Change(p << 1 | 1, l, r, d);
    PushUp(p);
  }
  int64_t Query(int64_t p, int64_t l, int64_t r) {
    if (l <= tree[p].l && r >= tree[p].r) return tree[p].sum;
    PushDown(p);
    int64_t mid = (tree[p].l + tree[p].r) / 2;
    int64_t sum = 0;
    if (l <= mid) sum += Query(p << 1, l, r);
    if (r > mid) sum += Query(p << 1 | 1, l, r);
    return sum;
  }
  int64_t AskDat(int64_t p, int64_t l, int64_t r) {
    if (l <= tree[p].l && r >= tree[p].r) return tree[p].dat;
    PushDown(p);
    int64_t mid = (tree[p].l + tree[p].r) / 2;
    int64_t res = -(1 << 30);
    if (l <= mid) res = max(res, AskDat(p << 1, l, r));
    if (r > mid) res = max(res, AskDat(p << 1 | 1, l, r));
    return res;
  }
};
const int64_t kMod(998244353);
template <int kMod>
struct modint {
  int x;
  modint(int _x = 0) : x(_x) {}
  modint(LL _x) : x(int(_x % kMod)) {}
  inline friend modint operator+(modint u, const modint &v) { return u += v; }
  modint &operator+=(const modint &A) {
    if ((x += A.x) >= kMod) x -= kMod;
    return *this;
  }
  inline friend modint operator-(modint u, const modint &v) { return u -= v; }
  modint &operator-=(const modint &A) {
    if ((x -= A.x) < 0) x += kMod;
    return *this;
  }
  inline friend modint operator*(modint u, const modint &v) { return u *= v; }
  modint &operator*=(const modint &A) { return *this = modint(1LL * x * A.x); }
  modint pow(LL exp) const {
    modint ret = 1, base = *this;
    for (; exp > 0; exp >>= 1, base *= base)
      if (exp & 1) ret *= base;
    return ret;
  }
  inline friend modint operator/(modint u, const modint &v) { return u /= v; }
  modint &operator/=(const modint &A) { return *this *= A.pow(kMod - 2); }
};
using mint = modint<(int)kMod>;
const double pi = acos(-1.0);
const int64_t kInf(1e18 + 10);
const int64_t kMax(1e5 + 10);
int64_t group(1);
string tob(LL x) {
  if (x == 0) return "";
  return tob(x >> 1) + (x & 1 ? "1" : "0");
}
string work(string str) {
  while (str.back() == '0') str.pop_back();
  reverse(str.begin(), str.end());
  return str;
}
inline void Solve() {
  LL n, m;
  Read(n, m);
  queue<string> q;
  map<string, bool> mp;
  string str = tob(n);
  mp[str] = true;
  q.push(str);
  while (!q.empty()) {
    str = q.front(), q.pop();
    if (str.length() >= 100) continue;
    string tmp = work(str + '0');
    if (!mp[tmp]) {
      mp[tmp] = true;
      q.push(tmp);
    }
    tmp = work(str + '1');
    if (!mp[tmp]) {
      mp[tmp] = true;
      q.push(tmp);
    }
  }
  if (mp[tob(m)]) {
    puts("YES");
  } else {
    puts("NO");
  }
}
int main() {
  while (group--) {
    Solve();
  }
  return 0;
}
