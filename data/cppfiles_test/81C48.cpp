#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, d, f[N], c[N], bt[N], tr[N << 2], tg[N << 2], t, l, p = 1;
pair<int, int> a[N], b[N];
long long s;
void pd(int k) {
  tr[k << 1] += tg[k];
  tg[k << 1] += tg[k];
  tr[k << 1 | 1] += tg[k];
  tg[k << 1 | 1] += tg[k];
  tg[k] = 0;
}
void upd1(int k, int l, int r, int a, int b, int v) {
  if (a > b) return;
  if (l == a && r == b) {
    tr[k] += v;
    tg[k] += v;
    return;
  }
  pd(k);
  int mid = l + r >> 1;
  if (b <= mid)
    upd1(k << 1, l, mid, a, b, v);
  else if (a > mid)
    upd1(k << 1 | 1, mid + 1, r, a, b, v);
  else
    upd1(k << 1, l, mid, a, mid, v),
        upd1(k << 1 | 1, mid + 1, r, mid + 1, b, v);
  tr[k] = max(tr[k << 1], tr[k << 1 | 1]);
}
bool cmp(pair<int, int> x, pair<int, int> y) { return x.second < y.second; }
void upd2(int k, int l, int r, int x, int v) {
  if (l == r) {
    tr[k] = v;
    return;
  }
  pd(k);
  int mid = l + r >> 1;
  if (x <= mid)
    upd2(k << 1, l, mid, x, v);
  else
    upd2(k << 1 | 1, mid + 1, r, x, v);
  tr[k] = max(tr[k << 1], tr[k << 1 | 1]);
}
int ask(int k, int l, int r, int a, int b) {
  if (a > b) return 0;
  if (l == a && r == b) return tr[k];
  pd(k);
  int mid = l + r >> 1;
  if (b <= mid)
    return ask(k << 1, l, mid, a, b);
  else if (a > mid)
    return ask(k << 1 | 1, mid + 1, r, a, b);
  else
    return max(ask(k << 1, l, mid, a, mid),
               ask(k << 1 | 1, mid + 1, r, mid + 1, b));
}
void add(int x, int v) {
  for (int i = x; i; i -= i & (-i)) bt[i] += v;
}
int qu(int x) {
  int v = 0;
  for (int i = x; i <= n; i += i & (-i)) v += bt[i];
  return v;
}
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++)
    if (a[i].second <= d) l = i;
  for (int i = 1; i <= l; i++)
    if (a[i].first >= d) f[l]++;
  a[0].second = d;
  upd2(1, 0, n, l, f[l] + n - l);
  for (int i = l + 1; i <= n; i++) {
    t++;
    b[t] = {a[i].first, i};
    add(i, 1);
  }
  for (int i = 0; i <= n; i++) c[i] = max(a[i].second, d);
  sort(b, b + t + 1);
  for (int i = l + 1; i <= n; i++) {
    while (p <= t && b[p].first < a[i].second) {
      add(b[p].second, -1);
      if (n > 114514191) {
        while (1) {
          puts("dvj5307 is a very very big sb");
        }
        for (int j = 1; j <= d * n * n; j++) {
          int x = 1, y = 233333;
          for (int k = 1; k <= 99999; k--) x ^= (y + k);
          cout << x << endl;
        }
      }
      upd1(1, 0, n, l, b[p].second - 1, -1);
      p++;
    }
    int m = min(i, (int)(upper_bound(c, c + n + 1, a[i].first) - c));
    f[i] = max(ask(1, 0, n, l, m - 1) + 1, ask(1, 0, n, m, i - 1)) - qu(i);
    upd2(1, 0, n, i, f[i] + qu(i + 1));
  }
  printf("%d\n", f[n]);
  return 0;
}
