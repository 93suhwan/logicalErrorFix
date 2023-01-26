#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long ans = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = (ans << 1) + (ans << 3) + c - '0';
    c = getchar();
  }
  return ans * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x / 10) write(x / 10);
  putchar((char)(x % 10) + '0');
}
template <typename T>
inline T Abs(T a) {
  return a > 0 ? a : -a;
};
template <typename T, typename TT>
inline T Min(T a, TT b) {
  return a < b ? a : b;
}
template <typename T, typename TT>
inline T Max(T a, TT b) {
  return a < b ? b : a;
}
const long long N = 2e5 + 5;
long long n, m1, m2;
struct DSU {
  long long fa[N];
  inline long long find(long long x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
  }
  inline bool check(long long x, long long y) { return find(x) == find(y); }
  inline void merge(long long x, long long y) {
    long long f1 = find(x), f2 = find(y);
    if (f1 != f2) fa[f1] = f2;
  }
} a, b;
vector<pair<long long, long long> > ans;
vector<long long> c, d;
signed main() {
  n = read();
  m1 = read();
  m2 = read();
  for (long long i = 1; i <= n; ++i) a.fa[i] = b.fa[i] = i;
  for (long long i = 1; i <= m1; ++i) {
    long long u = read(), v = read();
    a.merge(u, v);
  }
  for (long long i = 1; i <= m2; ++i) {
    long long u = read(), v = read();
    b.merge(u, v);
  }
  for (long long i = 2; i <= n; ++i)
    if (!a.check(1, i) && !b.check(1, i)) {
      a.merge(1, i);
      b.merge(1, i);
      ans.push_back(make_pair(1, i));
    }
  for (long long i = 2; i <= n; ++i) {
    if (!a.check(1, i)) {
      a.merge(1, i);
      c.push_back(i);
    }
    if (!b.check(1, i)) {
      b.merge(1, i);
      d.push_back(i);
    }
  }
  for (long long i = 0; i < c.size() && i < d.size(); ++i)
    ans.push_back(make_pair(c[i], d[i]));
  printf("%lld\n", ans.size());
  for (long long i = 0; i < ans.size(); ++i)
    printf("%lld %lld\n", ans[i].first, ans[i].second);
  return 0;
}
