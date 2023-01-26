#include <bits/stdc++.h>
struct _ioS_ {
  inline char gc() {
    static const long long IN_LEN = 1 << 18 | 1;
    static char buf[IN_LEN], *s, *t;
    return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)),
           s == t ? -1 : *s++;
  }
  template <typename _Tp>
  inline _ioS_ &operator>>(_Tp &x) {
    static char ch = gc(), sgn = 0;
    for (; !isdigit(ch); ch = gc()) {
      if (ch == -1) return *this;
      sgn |= ch == '-';
    }
    for (x = 0; isdigit(ch); ch = gc()) x = (x << 1) + (x << 3) + (ch ^ 48);
    sgn && (x = -x);
    return *this;
  }
} inn;
const double eps = 1e-8;
const double inf = 1e10;
const long long INF = 0x7f7f7f7f;
const double PI = 3.14159265;
const long long mod = 1000000007;
const long long N = 400005;
using namespace std;
long long n, t;
long long l[N], r[N], ord[N];
set<long long> s;
struct Fenwick {
  long long tr[N];
  inline long long lowbit(long long x) { return (-x & x); }
  inline void upd(long long i, long long x) {
    for (; i < N; i += lowbit(i)) tr[i] = (tr[i] + x) % mod;
  }
  inline long long qry(long long i) {
    long long ans = 0;
    for (; i; i -= lowbit(i)) ans = (ans + tr[i]) % mod;
    return ans;
  }
  inline long long qry(long long l, long long r) {
    long long L = qry(l - 1), R = qry(r);
    return ((R - L) % mod + mod) % mod;
  }
  inline void clear() { memset(tr, 0, sizeof(tr)); }
} tre;
inline void Main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> l[i] >> r[i], ord[i] = i;
  cin >> t;
  for (long long i = 1; i <= t; ++i) {
    long long tmp;
    cin >> tmp;
    s.insert(r[tmp]);
  }
  sort(ord + 1, ord + n + 1,
       [&](long long x, long long y) { return l[x] < l[y]; });
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    long long tmp = tre.qry(r[ord[i]]);
    if (s.size() && r[ord[i]] <= *(--s.end())) tmp = (tmp + 1) % mod;
    ans = (ans + tmp) % mod;
    tre.upd(1, tmp);
    tre.upd(r[ord[i]] + 1, mod - tmp);
    if (s.find(r[ord[i]]) != s.end()) s.erase(r[ord[i]]);
  }
  cout << ans << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  Main();
  return 0;
}
