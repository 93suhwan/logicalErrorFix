#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 3e5 + 5;
int n, q, k, a[N], c[N], mi[N], r[N];
struct qry {
  int l, r;
  long long ans;
};
qry qr[N];
vector<int> aqr[N];
void cm() {
  int l = 1, r = 0;
  for (int i = 1; i <= n; i++) {
    while (l <= r && i - c[l] >= k) l++;
    while (l <= r && a[c[r]] >= a[i]) r--;
    c[++r] = i;
    if (i >= k) mi[i - k + 1] = c[l];
  }
}
void cs() {
  int top = -1;
  for (int i = 1; i <= n; i++) {
    while (top >= 0 && a[c[top]] >= a[i]) {
      r[c[top]] = i;
      top--;
    }
    c[++top] = i;
  }
  while (top >= 0) {
    r[c[top]] = n + 1;
    top--;
  }
}
struct segmentTree {
  int l, r;
  long long dat;
  int f;
} t[N * 4];
void pushdown(int p) {
  if (t[p].f != -1) {
    t[p * 2].dat = (long long)t[p].f * (t[p * 2].r - t[p * 2].l + 1);
    t[p * 2 + 1].dat =
        (long long)t[p].f * (t[p * 2 + 1].r - t[p * 2 + 1].l + 1);
    t[p * 2].f = t[p].f;
    t[p * 2 + 1].f = t[p].f;
    t[p].f = -1;
  }
}
void build(int p, int l, int r) {
  t[p].l = l;
  t[p].r = r;
  t[p].f = -1;
  if (l == r) {
    t[p].dat = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  t[p].dat = t[p * 2].dat + t[p * 2 + 1].dat;
}
void change(int p, int l, int r, int d) {
  if (t[p].l >= l && t[p].r <= r) {
    t[p].f = d;
    t[p].dat = (long long)d * (t[p].r - t[p].l + 1);
    return;
  }
  pushdown(p);
  int mid = (t[p].l + t[p].r) >> 1;
  if (l <= mid) change(p * 2, l, r, d);
  if (mid < r) change(p * 2 + 1, l, r, d);
  t[p].dat = t[p * 2].dat + t[p * 2 + 1].dat;
}
long long ask(int p, int l, int r) {
  if (t[p].l >= l && t[p].r <= r) return t[p].dat;
  pushdown(p);
  long long ans = 0;
  int mid = (t[p].l + t[p].r) >> 1;
  if (l <= mid) ans += ask(p * 2, l, r);
  if (mid < r) ans += ask(p * 2 + 1, l, r);
  return ans;
}
void solve() {
  n = read();
  q = read();
  k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= q; i++) {
    qr[i].l = read();
    qr[i].r = read();
    aqr[qr[i].l].push_back(i);
  }
  cm();
  cs();
  build(1, 1, n);
  for (int i = 1; i <= k; i++) {
    for (int j = (n - i) / k + 1; j >= 1; j--) {
      if (i == 2 && j == 1) {
        int xxx = 1;
        xxx++;
      }
      int x = (j - 1) * k + i;
      int y = mi[x];
      int z = r[y];
      change(1, j + 1, min((z - i - 1) / k + 1, n), a[y]);
      change(1, j, j, a[x]);
      for (int l = 0; l < aqr[x].size(); l++) {
        int x1 = aqr[x][l];
        qr[x1].ans = ask(1, j, (qr[x1].r - i) / k + 1);
      }
    }
    change(1, 1, n, 0);
  }
  for (int i = 1; i <= q; i++) cout << qr[i].ans << endl;
}
int main() {
  solve();
  return 0;
}
