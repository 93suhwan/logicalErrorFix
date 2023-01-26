#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using namespace std;
const int INF = 1e9 + 7;
const unsigned long long MOD = 998244353;
const long long INF64 = 1e18 + 7;
const int MAXN = 1e5 + 2;
const int MAXMAXN = 1e6 + 10;
const double EPS = 1e-4;
const long double PI = 3.14159265358979323846;
template <typename T>
inline T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
long long gcd(long long a, long long b) {
  while (a && b) a > b ? a %= b : b %= a;
  return a + b;
}
long long mypow(long long x, long long y) {
  long long ans = 1;
  x %= MOD;
  while (y) {
    if (y & 1) ans = (ans * x) % MOD;
    y >>= 1;
    x = (x * x) % MOD;
  }
  return ans;
}
struct seg {
  int l, r, w;
};
int n, m;
int sz = 1;
vector<seg> segs;
vector<int> tree;
vector<int> add;
void build() {
  while (sz < m) sz <<= 1;
  tree.resize(2 * sz);
  add.resize(2 * sz);
}
void push(int v) {
  add[2 * v] += add[v];
  add[2 * v + 1] += add[v];
  add[v] = 0;
}
void update(int v) {
  tree[v] = min(tree[2 * v] + add[2 * v], tree[2 * v + 1] + add[2 * v + 1]);
}
void change(int val, int ql, int qr, int l = 0, int r = sz - 1, int v = 1) {
  if (ql <= l && r <= qr)
    add[v] += val;
  else {
    push(v);
    int mid = (l + r) / 2;
    if (ql <= mid) change(val, ql, qr, l, mid, 2 * v);
    if (mid < qr) change(val, ql, qr, mid + 1, r, 2 * v + 1);
    update(v);
  }
}
int get(int ql, int qr, int l = 0, int r = sz - 1, int v = 1) {
  if (ql <= l && r <= qr)
    return tree[v] + add[v];
  else {
    push(v);
    int min_ = INF;
    int mid = (l + r) / 2;
    if (ql <= mid) min_ = min(min_, get(ql, qr, l, mid, 2 * v));
    if (mid < qr) min_ = min(min_, get(ql, qr, mid + 1, r, 2 * v + 1));
    update(v);
    return min_;
  }
}
void write() {
  for (int i = 1; i <= sz; i *= 2) {
    for (int j = i; j < 2 * i; j++)
      cout << "(" << tree[j] << " " << add[j] << ")"
           << " ";
    cout << '\n';
  }
}
int main() {
  cin >> n >> m;
  --m;
  segs = vector<seg>(n);
  for (int i = 0; i < n; i++) {
    cin >> segs[i].l >> segs[i].r >> segs[i].w;
    --segs[i].l;
    --segs[i].r;
  }
  sort(segs.begin(), segs.end(), [](seg a, seg b) { return a.w < b.w; });
  build();
  int r = 0;
  int ans = INF;
  for (int l = 0; l < n; l++) {
    while (r < n && get(0, m - 1) == 0)
      change(1, segs[r].l, segs[r].r - 1), r++;
    if (get(0, m - 1) > 0) ans = min(ans, segs[r - 1].w - segs[l].w);
    if (r == n) break;
    change(-1, segs[l].l, segs[l].r - 1);
  }
  cout << ans << '\n';
  return 0;
}
