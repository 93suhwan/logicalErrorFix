#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int inf = 1000000000;
const long long inf_ll = (long long)1 << 60;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long readll() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long tx, ty;
    long long d = exgcd(b, a % b, tx, ty);
    x = ty;
    y = tx - (a / b) * ty;
    return d;
  }
}
long long power(long long x, long long y) {
  long long t = 1;
  for (; y; y >>= 1, x = x * x % (1000000007))
    if (y & 1) t = t * x % (1000000007);
  return t;
}
struct segment_tree {
  struct seg {
    int l, r;
    int mi, mx, sum;
  } t[4 * (500000 + 5)];
  void pushup(int k) {
    t[k].mi = min(t[k << 1].mi, t[k << 1 | 1].mi);
    t[k].mx = max(t[k << 1].mx, t[k << 1 | 1].mx);
    t[k].sum = t[k << 1].sum + t[k << 1 | 1].sum;
  }
  inline void build(int k, int l, int r) {
    t[k].l = l;
    t[k].r = r;
    int mid = (l + r) >> 1;
    t[k].mi = inf;
    if (l == r) {
      t[k].mi = t[k].mx = t[k].sum = 0;
      return;
    }
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    pushup(k);
  }
  inline void change_point(int k, int x, int y) {
    int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
    if (l == x && r == y) {
      t[k].mi = t[k].mx = t[k].sum = y;
      return;
    }
    if (x <= mid)
      change_point(k << 1, x, y);
    else
      change_point(k << 1 | 1, x, y);
    pushup(k);
  }
  inline int query_sum(int k, int x, int y) {
    int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
    if (l == x && r == y) return t[k].sum;
    if (y <= mid)
      return query_sum(k << 1, x, y);
    else if (x > mid)
      return query_sum(k << 1 | 1, x, y);
    else
      return query_sum(k << 1, x, mid) + query_sum(k << 1 | 1, mid + 1, y);
  }
  inline int query_min(int k, int x, int y) {
    int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
    if (l == x && r == y) return t[k].mi;
    if (y <= mid)
      return query_min(k << 1, x, y);
    else if (x > mid)
      return query_min(k << 1 | 1, x, y);
    else
      return min(query_min(k << 1, x, mid), query_min(k << 1 | 1, mid + 1, y));
  }
  inline int query_max(int k, int x, int y) {
    int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
    if (l == x && r == y) return t[k].mx;
    if (y <= mid)
      return query_max(k << 1, x, y);
    else if (x > mid)
      return query_max(k << 1 | 1, x, y);
    else
      return max(query_max(k << 1, x, mid), query_max(k << 1 | 1, mid + 1, y));
  }
};
void solve() {
  long long n, k;
  cin >> n >> k;
  k++;
  long long b[15];
  b[0] = 1;
  for (int i = 1; i < 15; i++) b[i] = b[i - 1] * 10;
  long long a[15];
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long now = 0;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    long long x = b[a[i + 1] - a[i]] - 1;
    if (x < k) {
      ans += x * b[a[i]];
      k -= x;
    } else {
      ans += k * b[a[i]];
      k = 0;
    }
  }
  ans += k * b[a[n]];
  cout << ans << endl;
}
int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}
