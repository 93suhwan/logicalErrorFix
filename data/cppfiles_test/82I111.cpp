#include <bits/stdc++.h>
long long read() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = getchar();
  return f ? -x : x;
}
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
template <typename T>
inline bool umin(T& a, T b) {
  if (b < a) return a = b, 1;
  return 0;
}
template <typename T>
inline bool umax(T& a, T b) {
  if (b > a) return a = b, 1;
  return 0;
}
const int MAXN = 300011, INF = 1.233e9;
int n, L;
int a[MAXN], b[MAXN];
struct Segment_Tree_Min {
  int t[MAXN << 2 | 1];
  void init(int* a, unsigned l = 1, unsigned r = n, unsigned num = 1) {
    if (l == r) {
      t[num] = a[l];
      return;
    }
    unsigned mid = (l + r) >> 1;
    init(a, l, mid, num << 1), init(a, mid + 1, r, num << 1 | 1);
    t[num] = min(t[num << 1], t[num << 1 | 1]);
  }
  int Qmin(unsigned ql, unsigned qr, unsigned l = 1, unsigned r = n,
           unsigned num = 1) {
    if (ql <= l && r <= qr) return t[num];
    unsigned mid = (l + r) >> 1;
    int res = INF;
    if (ql <= mid) umin(res, Qmin(ql, qr, l, mid, num << 1));
    if (qr > mid) umin(res, Qmin(ql, qr, mid + 1, r, num << 1 | 1));
    return res;
  }
} Tmin;
struct Segment_Tree_Sum {
  struct node {
    long long sum, tag;
  } t[MAXN << 2 | 1];
  void pushdown(unsigned l, unsigned r, unsigned num) {
    if (t[num].tag == 0) return;
    unsigned mid = (l + r) >> 1;
    t[num << 1].sum = (mid - l + 1) * t[num].tag, t[num << 1].tag = t[num].tag;
    t[num << 1 | 1].sum = (r - mid) * t[num].tag,
                 t[num << 1 | 1].tag = t[num].tag;
    t[num].tag = 0;
  }
  void init(unsigned l = 1, unsigned r = L, unsigned num = 1) {
    t[num].sum = t[num].tag = 0;
    if (l == r) return;
    unsigned mid = (l + r) >> 1;
    init(l, mid, num << 1), init(mid + 1, r, num << 1 | 1);
  }
  void Cover(unsigned ql, unsigned qr, int k, unsigned l = 1, unsigned r = L,
             unsigned num = 1) {
    if (ql <= l && r <= qr) {
      t[num].sum = (r - l + 1) * k, t[num].tag = k;
      return;
    }
    pushdown(l, r, num);
    unsigned mid = (l + r) >> 1;
    if (ql <= mid) Cover(ql, qr, k, l, mid, num << 1);
    if (qr > mid) Cover(ql, qr, k, mid + 1, r, num << 1 | 1);
    t[num].sum = t[num << 1].sum + t[num << 1 | 1].sum;
  }
  long long Qsum(unsigned ql, unsigned qr, unsigned l = 1, unsigned r = L,
                 unsigned num = 1) {
    if (ql <= l && r <= qr) return t[num].sum;
    pushdown(l, r, num);
    unsigned mid = (l + r) >> 1;
    long long res = 0;
    if (ql <= mid) res += Qsum(ql, qr, l, mid, num << 1);
    if (qr > mid) res += Qsum(ql, qr, mid + 1, r, num << 1 | 1);
    return res;
  }
} Tsum;
struct one {
  int l, r, dex;
};
std::vector<one> Q1[MAXN];
std::vector<std::pair<int, int> > Q2[MAXN];
int s[MAXN], val[MAXN], top;
long long res[MAXN];
int main() {
  n = read();
  int m = read(), k = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  Tmin.init(a);
  for (int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    Q1[l % k].emplace_back(
        one{(l - 1) / k + 1, (l - 1) / k + 1 + (r - l) / k, i});
  }
  for (int r = 0; r < k; ++r) {
    L = 0;
    for (int i = r ? r : k; i <= n; i += k) b[++L] = i, Q2[L].clear();
    for (auto x : Q1[r]) {
      Q2[x.l].emplace_back(std::pair<int, int>(x.r, x.dex));
    }
    top = 0;
    s[0] = L + 1;
    for (int i = L; i; --i) {
      int v = Tmin.Qmin(b[i], min(b[i] + k - 1, n)), flag = 0;
      while (top && val[top] > v) {
        Tsum.Cover(i + 1, s[top - 1] - 1, v), --top;
        flag = 1;
      }
      Tsum.Cover(i, i, a[b[i]]);
      if (flag) s[++top] = i + 1, val[top] = v;
      s[++top] = i, val[top] = a[b[i]];
      for (auto x : Q2[i]) res[x.second] = Tsum.Qsum(i, x.first);
    }
  }
  for (int i = 1; i <= m; ++i) printf("%lld\n", res[i]);
  return 0;
}
