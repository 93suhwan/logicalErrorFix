#include <bits/stdc++.h>
using namespace std;
const long long N = 3 * 1e5 + 100;
long long n, q, k, a[N], ans[N], f[N][21], lg[N];
long long b[N], pos[N], w, id[N];
vector<pair<long long, long long> > p[N];
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
namespace seg {
long long sum[N * 4], tag[N * 4];
void pushup(long long x) { sum[x] = sum[x + x] + sum[x + x + 1]; }
long long get(long long l, long long r) {
  return r - l + 1 - (r / 2 - (l + 1) / 2 + 1);
}
void pushdown(long long x, long long l, long long mid, long long r) {
  if (tag[x] != -1) {
    sum[x + x] = tag[x] * get(l, mid);
    sum[x + x + 1] = tag[x] * get(mid + 1, r);
    tag[x + x] = tag[x + x + 1] = tag[x];
    tag[x] = -1;
  }
}
void build(long long x, long long l, long long r) {
  tag[x] = -1;
  sum[x] = 0;
  if (l == r) return;
  long long mid = (l + r) >> 1;
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);
}
void change(long long x, long long l, long long r, long long ll, long long rr,
            long long v) {
  if (ll <= l && rr >= r) {
    sum[x] = v * get(l, r);
    tag[x] = v;
    return;
  }
  long long mid = (l + r) >> 1;
  pushdown(x, l, mid, r);
  if (ll <= mid) change(x + x, l, mid, ll, rr, v);
  if (rr > mid) change(x + x + 1, mid + 1, r, ll, rr, v);
  pushup(x);
}
long long query(long long x, long long l, long long r, long long ll,
                long long rr) {
  if (ll <= l && rr >= r) return sum[x];
  long long mid = (l + r) >> 1, ans = 0;
  pushdown(x, l, mid, r);
  if (ll <= mid) ans += query(x + x, l, mid, ll, rr);
  if (rr > mid) ans += query(x + x + 1, mid + 1, r, ll, rr);
  return ans;
}
}  // namespace seg
long long ask(long long l, long long r) {
  long long p = lg[r - l + 1];
  return min(f[l][p], f[r - (1 << p) + 1][p]);
}
void solve() {
  seg::build(1, 1, w);
  b[w + 1] = 0;
  stack<long long> st;
  st.push(w + 1);
  for (long long i = w; i >= 1; i--) {
    while (b[i] < b[st.top()]) st.pop();
    seg::change(1, 1, w, i, st.top() - 1, b[i]);
    st.push(i);
    for (auto it : p[pos[i]])
      ans[it.second] += seg::query(1, 1, w, i, id[it.first]);
  }
}
signed main() {
  n = read();
  q = read();
  k = read();
  lg[0] = -1;
  for (long long i = 1; i <= n; i++)
    a[i] = read(), f[i][0] = a[i], lg[i] = lg[i >> 1] + 1;
  for (long long j = 1; j <= 20; j++) {
    for (long long i = 1; i <= n - (1 << j) + 1; i++)
      f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  }
  for (long long i = 1; i <= q; i++) {
    long long l = read(), r = read(), x = (r - l) / k;
    r = l + x * k;
    p[l].emplace_back(r, i);
  }
  for (long long i = 1; i <= k; i++)
    if (i <= n) {
      w = 0;
      long long last;
      for (long long j = i; j <= n; j += k) {
        if (j - k > 0 && k > 1) b[++w] = ask(j - k + 1, j - 1);
        b[++w] = a[j];
        pos[w] = j;
        id[j] = w;
        last = j;
      }
      if (last < n) b[++w] = ask(last + 1, n);
      if (w) solve();
    }
  for (long long i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
