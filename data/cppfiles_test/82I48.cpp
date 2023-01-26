#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T &x, T y) {
  x = x < y ? y : x;
  return;
}
template <typename T>
inline void ckmin(T &x, T y) {
  x = x < y ? x : y;
  return;
}
namespace FastIO {
inline long long read() {
  long long res = 0, f = 1;
  char k;
  while (!isdigit(k = getchar()))
    if (k == '-') f = -1;
  while (isdigit(k)) res = res * 10 + k - '0', k = getchar();
  return res * f;
}
char OPUT[100];
inline void print(long long x) {
  if (!x) return putchar('0'), putchar('\n'), void();
  if (x < 0) putchar('-'), x = -x;
  long long cnt = 0;
  while (x) OPUT[++cnt] = x % 10, x /= 10;
  for (register long long i = cnt; i >= 1; --i) putchar(OPUT[i] + '0');
  putchar('\n');
  return;
}
}  // namespace FastIO
using namespace FastIO;
const long long N = 3e5 + 10;
long long n, Q, k, a[N], ans[N], sum[N << 2], len[N << 2], tag[N << 2];
vector<long long> pos[N];
vector<pair<long long, long long> > qu[N];
inline void push_down(long long p) {
  if (tag[p]) {
    sum[p << 1] = tag[p] * len[p << 1];
    sum[p << 1 | 1] = tag[p] * len[p << 1 | 1];
    tag[p << 1] = tag[p << 1 | 1] = tag[p];
    tag[p] = 0;
  }
  return;
}
inline void push_up(long long p) {
  return sum[p] = sum[p << 1] + sum[p << 1 | 1], void();
}
inline void upd(long long p, long long l, long long r, long long st,
                long long ed, long long v) {
  if (st <= l && r <= ed) return sum[p] = len[p] * v, tag[p] = v, void();
  long long mid = (l + r) >> 1;
  push_down(p);
  if (st <= mid) upd(p << 1, l, mid, st, ed, v);
  if (ed > mid) upd(p << 1 | 1, mid + 1, r, st, ed, v);
  return push_up(p);
}
inline void build(long long p, long long l, long long r) {
  tag[p] = 0;
  len[p] = r - l + 1;
  sum[p] = 0;
  if (l == r) return;
  long long mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  return;
}
inline long long query(long long p, long long l, long long r, long long st,
                       long long ed) {
  if (st <= l && r <= ed) return sum[p];
  push_down(p);
  long long mid = (l + r) >> 1, res = 0;
  if (st <= mid) res += query(p << 1, l, mid, st, ed);
  if (ed > mid) res += query(p << 1 | 1, mid + 1, r, st, ed);
  return res;
}
long long st[20][N], lg[N], v[N];
inline long long qmn(long long l, long long r) {
  long long t = lg[r - l + 1];
  return min(st[t][l], st[t][r - (1 << t) + 1]);
}
signed main() {
  n = read();
  Q = read();
  k = read();
  for (register long long i = 2; i <= N - 1; ++i) lg[i] = lg[i >> 1] + 1;
  for (register long long i = 1; i <= n; ++i)
    a[i] = read(), pos[i % k].push_back(i), st[0][i] = a[i];
  for (long long j = 1; j <= 19; ++j)
    for (long long i = 1; i + (1 << j) - 1 <= n; ++i)
      st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  for (long long i = 1, l, r; i <= Q; ++i) {
    l = read(), r = read();
    if (i == 373) cout << l << " " << r << endl;
    long long p = l % k, q = r % k;
    if (p <= q)
      r -= q - p;
    else
      r = r - q - k + p;
    qu[l].push_back({r, i});
    if (i == 373) cout << l << " " << r << endl;
    assert(l % k == r % k);
  }
  for (register long long i = 0; i <= k - 1; ++i) {
    stack<long long> st;
    long long siz = pos[i].size();
    build(1, 1, siz);
    for (register long long j = siz - 1; j >= 0; --j) {
      v[pos[i][j]] = a[pos[i][j]];
      while (st.size() && v[pos[i][st.top()]] > v[pos[i][j]]) st.pop();
      upd(1, 1, siz, j + 1, st.size() ? st.top() : siz, v[pos[i][j]]);
      st.push(j);
      for (auto t : qu[pos[i][j]])
        ans[t.second] = query(1, 1, siz, j + 1, t.first / k + 1);
      if (k != 1 && j) {
        long long e = qmn(pos[i][j - 1] + 1, pos[i][j] - 1);
        if (e >= v[pos[i][j]]) continue;
        v[pos[i][j]] = e;
        st.pop();
        while (st.size() && v[pos[i][st.top()]] > v[pos[i][j]]) st.pop();
        upd(1, 1, siz, j + 1, st.size() ? st.top() : siz, e);
        st.push(j);
      }
    }
  }
  for (register long long i = 1; i <= Q; ++i) print(ans[i]);
  return 0;
}
