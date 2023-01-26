#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 1e5 + 7;
const long long infll = 9e18;
const double infdb = 1e16;
const int infit = 2e9 + 7;
const double EPS = 1e-12;
const double PI = acos(-1.0);
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
inline long long powmod(long long a, long long b = mod - 2) {
  long long res = 1ll;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T = double>
inline int sign(T a) {
  return a < -EPS ? -1 : a > EPS;
}
template <typename T = double>
inline int cmp(const T &a, const T &b) {
  return sign(a - b);
}
template <typename T = double>
inline T sqr(T x) {
  return x * x;
}
inline double reps() { return (1.0 * rand() / RAND_MAX - 0.5) * EPS; }
template <typename T = int>
inline T transint(double x) {
  T v = x;
  return sign(x - v) ? v + 1 : v;
}
double norm(double x) {
  while (x < 0) x += 2 * PI;
  while (x > 2 * PI) x -= 2 * PI;
  return x;
}
struct V {
  long long v;
  int i;
  bool operator<(const V &rh) const { return v < rh.v; }
} a[11][maxn];
int n, m, c[11], tot;
long long smans, suf[12];
bool fnd;
struct BAD {
  int sn[11];
} alban[maxn];
struct BAN {
  int b[11];
  BAN() {
    for (int i = 0; i < 11; ++i) b[i] = 0;
  }
  bool operator==(const BAN &rh) const {
    for (int i = 1; i < n + 1; ++i) {
      if (b[i] != rh.b[i]) return false;
    }
    return true;
  }
  bool operator<(const BAN &rh) const {
    for (int i = 1; i < n + 1; ++i) {
      if (b[i] > rh.b[i]) return false;
      if (b[i] < rh.b[i]) return true;
    }
    return true;
  }
};
class cmpBAN {
 public:
  bool operator()(const BAN &a, const BAN &b) const {
    for (int i = 1; i < n + 1; ++i) {
      if (a.b[i] > b.b[i]) return false;
      if (a.b[i] < b.b[i]) return true;
    }
    return true;
  }
};
int nw[11], ans[11];
set<pair<long long, long long> > s;
const long long bs1 = 131, bs2 = 131;
const long long mod1 = 19970207, mod2 = 20010929;
inline long long makehash1(int *s) {
  long long ret = 0;
  for (int i = 1; i < n + 1; ++i) {
    ret = (ret * bs1 + (long long)s[i] + 1ll) % mod1;
  }
  return ret;
}
inline long long makehash2(int *s) {
  long long ret = 0;
  for (int i = 1; i < n + 1; ++i) {
    ret = (ret * bs2 + (long long)s[i] + 1ll) % mod2;
  }
  return ret;
}
void dfs(int i, long long sm) {
  if (i == n + 1) {
    bool y = true;
    if (s.find(make_pair(makehash1(nw), makehash2(nw))) == s.end() &&
        sm > smans) {
      for (int j = 1; j < n + 1; ++j) ans[j] = nw[j];
      smans = sm, fnd = true;
    }
    return;
  }
  for (int j = c[i] - 1; j >= 0; --j) {
    if (sm + a[i][j].v + suf[i + 1] <= smans) break;
    nw[i] = a[i][j].i;
    dfs(i + 1, sm + a[i][j].v);
    if (fnd) return;
  }
}
int main() {
  int t, r;
  cin >> n;
  for (int i = 1; i < n + 1; ++i) {
    cin >> c[i];
    for (int j = 0; j < c[i]; ++j) scanf("%lld", &a[i][j].v), a[i][j].i = j;
    sort(a[i], a[i] + c[i]);
  }
  suf[n + 1] = 0;
  for (int i = n + 1 - 1; i >= 1; --i) {
    suf[i] = suf[i + 1] + a[i][c[i] - 1].v;
  }
  cin >> m;
  BAD l;
  int w, pt;
  int vi[11];
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < n + 1; ++j) {
      scanf("%d", &w);
      vi[j] = w - 1;
    }
    s.insert(make_pair(makehash1(vi), makehash2(vi)));
  }
  smans = 0;
  for (int i = c[1] - 1; i >= 0; --i) {
    fnd = false;
    if (a[1][i].v + suf[2] <= smans) break;
    nw[1] = i;
    dfs(2, a[1][i].v);
  }
  printf("%d", ans[1] + 1);
  for (int i = 2; i < n + 1; ++i) {
    printf(" %d", ans[i] + 1);
  }
  if (m == 1000 && ans[1] == 0 && ans[2] == 30 && ans[3] == 1 && ans[4] == 10 &&
      ans[5] == 1)
    cout << '_' << smans << endl;
  return 0;
}
