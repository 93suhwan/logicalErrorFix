#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 10;
struct UPD {
  long long a, pos;
} sta[maxn];
long long top = 0;
long long n, m;
long long a[maxn], b[maxn], t[maxn << 1];
long long mn[maxn << 2], lz[maxn << 2];
bool clr[maxn << 2];
inline void pushup(long long id) { mn[id] = min(mn[id << 1], mn[id << 1 | 1]); }
inline void change(long long id, long long v) {
  lz[id] += v;
  mn[id] += v;
}
inline void pushdown(long long id) {
  if (clr[id]) {
    mn[id << 1] = mn[id << 1 | 1] = lz[id << 1] = lz[id << 1 | 1] = 0;
    clr[id << 1] = true;
    clr[id << 1 | 1] = true;
    clr[id] = false;
  }
  if (lz[id]) {
    change(id << 1, lz[id]);
    change(id << 1 | 1, lz[id]);
    lz[id] = 0;
  }
}
inline void update(long long id, long long l, long long r, long long x,
                   long long y, long long v) {
  if (x <= l && r <= y) {
    change(id, v);
    return;
  }
  pushdown(id);
  long long mid = (l + r) >> 1;
  if (x <= mid) update(id << 1, l, mid, x, y, v);
  if (y > mid) update(id << 1 | 1, mid + 1, r, x, y, v);
  pushup(id);
}
bool cmp(UPD A, UPD B) { return A.a < B.a; }
long long mm;
inline void init() {
  scanf("%lld%lld", &n, &m);
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) scanf("%lld", a + i), t[++cnt] = a[i];
  for (long long i = 1; i <= m; i++) scanf("%lld", b + i), t[++cnt] = b[i];
  sort(t + 1, t + cnt + 1);
  mm = unique(t + 1, t + cnt + 1) - t - 1;
  for (long long i = 1; i <= n; i++)
    a[i] = lower_bound(t + 1, t + mm + 1, a[i]) - t;
  for (long long i = 1; i <= m; i++)
    b[i] = lower_bound(t + 1, t + mm + 1, b[i]) - t;
  top = 0;
  for (long long i = 1; i <= n; i++) sta[++top].a = a[i], sta[top].pos = i;
  sort(sta + 1, sta + top + 1, cmp);
}
long long c[maxn << 1];
inline void upd(long long x, long long v) {
  for (long long i = x; i <= mm + 1; i += (i & (-i))) c[i] += v;
}
inline long long qur(long long x) {
  long long res = 0;
  for (long long i = x; i > 0; i -= (i & (-i))) res += c[i];
  return res;
}
inline long long init_ans(long long mm) {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans += i - 1 - qur(a[i]);
    upd(a[i], 1);
  }
  for (long long i = 1; i <= n; i++) {
    upd(a[i], -1);
  }
  return ans;
}
inline long long query(long long id, long long l, long long r, long long x) {
  if (l == r) return mn[id];
  pushdown(id);
  long long mid = (l + r) >> 1, res;
  if (x <= mid)
    res = query(id << 1, l, mid, x);
  else
    res = query(id << 1 | 1, mid + 1, r, x);
  return res;
}
inline void prt_tr() {
  for (long long i = 1; i <= 15; i++) {
    cout << mn[i] << ' ';
  }
  cout << endl;
  for (long long i = 1; i <= 15; i++) {
    cout << lz[i] << ' ';
  }
  cout << endl;
  for (long long i = 1; i <= 8; i++) {
    cout << query(1, 1, n + 1, i) << ' ';
  }
  cout << endl;
}
inline long long work(long long ans) {
  sort(b + 1, b + m + 1);
  for (long long i = 1; i <= n; i++) update(1, 1, n + 1, i + 1, n + 1, +1);
  for (long long i = 1, j = 1; i <= top, j <= m; j++) {
    while (i <= top && sta[i].a < b[j]) {
      update(1, 1, n + 1, sta[i].pos + 1, n + 1, -1);
      update(1, 1, n + 1, 1, sta[i].pos, +1);
      i++;
      if (i > top) break;
    }
    long long ii = i;
    while (i <= top && sta[i].a == b[j]) {
      update(1, 1, n + 1, sta[i].pos + 1, n + 1, -1);
      i++;
      if (i > top) break;
    }
    ans += mn[1];
    while (b[j] == b[j + 1]) j++, ans += mn[1];
    while (ii <= top && sta[ii].a == b[j]) {
      update(1, 1, n + 1, 1, sta[ii].pos, +1);
      ii++;
      if (ii > top) break;
    }
  }
  clr[1] = true;
  mn[1] = lz[1] = 0;
  return ans;
}
signed main() {
  long long C03;
  scanf("%lld", &C03);
  while (C03--) {
    init();
    long long ans = init_ans(mm);
    printf("%lld\n", work(ans));
  }
  return 0;
}
