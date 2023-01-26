#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct UPD {
  int a, pos;
} sta[maxn];
int top = 0;
int n, m;
int a[maxn], b[maxn], t[maxn << 1];
int mn[maxn << 2], lz[maxn << 2];
bool clr[maxn << 2];
inline void pushup(int id) { mn[id] = min(mn[id << 1], mn[id << 1 | 1]); }
inline void change(int id, int v) {
  lz[id] += v;
  mn[id] += v;
}
inline void pushdown(int id) {
  if (clr[id]) {
    mn[id << 1] = mn[id << 1 | 1] = lz[id << 1] = lz[id << 1 | 1] = 0;
    clr[id << 1] = true;
    clr[id << 1 | 1] = true;
    clr[id] = false;
  }
  if (lz[id]) {
    change(id << 1, lz[id]);
    change(id << 1 | 1, lz[id]);
  }
  lz[id] = 0;
}
inline void update(int id, int l, int r, int x, int y, int v) {
  if (x <= l && r <= y) {
    change(id, v);
    return;
  }
  pushdown(id);
  int mid = (l + r) >> 1;
  if (x <= mid) update(id << 1, l, mid, x, y, v);
  if (y > mid) update(id << 1 | 1, mid + 1, r, x, y, v);
  pushup(id);
}
bool cmp(UPD A, UPD B) { return A.a < B.a; }
int mm;
inline void init() {
  scanf("%d%d", &n, &m);
  int cnt = 0;
  for (int i = 1; i <= n; i++) scanf("%d", a + i), t[++cnt] = a[i];
  for (int i = 1; i <= m; i++) scanf("%d", b + i), t[++cnt] = b[i];
  sort(t + 1, t + cnt + 1);
  mm = unique(t + 1, t + cnt + 1) - t - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(t + 1, t + mm + 1, a[i]) - t;
  for (int i = 1; i <= m; i++) b[i] = lower_bound(t + 1, t + mm + 1, b[i]) - t;
  top = 0;
  for (int i = 1; i <= n; i++) sta[++top].a = a[i], sta[top].pos = i;
  sort(sta + 1, sta + top + 1, cmp);
}
long long c[maxn << 1];
inline void upd(int x, int v) {
  for (int i = x; i <= mm + 1; i += (i & (-i))) c[i] += v;
}
inline long long qur(int x) {
  long long res = 0;
  for (int i = x; i > 0; i -= (i & (-i))) res += c[i];
  return res;
}
inline long long init_ans(int mm) {
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i - 1 - qur(a[i]);
    upd(a[i], 1);
  }
  for (int i = 1; i <= n; i++) {
    upd(a[i], -1);
  }
  return ans;
}
inline void prt_tr() {
  for (int i = 1; i <= 7; i++) {
    cout << mn[i] << ' ';
  }
  cout << endl;
  for (int i = 1; i <= 7; i++) {
    cout << lz[i] << ' ';
  }
  cout << endl;
}
inline long long work(long long ans) {
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++) update(1, 1, n + 1, i + 1, n + 1, +1);
  for (int i = 1, j = 1; i <= top, j <= m; j++) {
    while (i <= top && sta[i].a < b[j]) {
      update(1, 1, n + 1, sta[i].pos + 1, n + 1, -1);
      update(1, 1, n + 1, 1, sta[i].pos, +1);
      i++;
      if (i > top) break;
    }
    int ii = i;
    while (i <= top && sta[i].a == b[j]) {
      update(1, 1, n + 1, sta[i].pos + 1, n + 1, -1);
      i++;
      if (i > top) break;
      if (j == m) break;
    }
    ans += mn[1];
    while (ii <= top && sta[ii].a == b[j]) {
      update(1, 1, n + 1, 1, sta[ii].pos, +1);
      ii++;
      if (ii > top) break;
      if (j == m) break;
    }
  }
  clr[1] = true;
  mn[1] = lz[1] = 0;
  return ans;
}
int main() {
  int C03;
  scanf("%d", &C03);
  while (C03--) {
    init();
    long long ans = init_ans(mm);
    printf("%lld\n", work(ans));
  }
  return 0;
}
