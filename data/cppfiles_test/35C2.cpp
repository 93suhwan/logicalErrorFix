#include <bits/stdc++.h>
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = getchar();
  return f * x;
}
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
template <typename T>
bool umin(T& a, T t) {
  if (a > t) return a = t, 1;
  return 0;
}
template <typename T>
bool umax(T& a, T t) {
  if (a < t) return a = t, 1;
  return 0;
}
const int MAXN = 1000011, INF = 1.233e9;
int pri[MAXN], cnt = 0;
int minp[MAXN];
bool vis[MAXN];
void sieve(int n) {
  vis[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) pri[++cnt] = i, minp[i] = i;
    for (int j = 1; j <= cnt && i * pri[j] <= n; ++j) {
      vis[i * pri[j]] = 1, minp[i * pri[j]] = pri[j];
      if (i % pri[j] == 0) break;
    }
  }
}
int n;
int stk[MAXN], sum[MAXN];
struct Segment_Tree_II {
  int t[MAXN << 2 | 1];
  Segment_Tree_II() { memset(t, 0x3f, sizeof t); }
  void Chkmin(unsigned ql, unsigned qr, int val, unsigned l = 1,
              unsigned r = n + 1, unsigned num = 1) {
    if (ql > qr) return;
    if (ql <= l && r <= qr) {
      umin(t[num], val);
      return;
    }
    unsigned mid = (l + r) >> 1;
    if (ql <= mid) Chkmin(ql, qr, val, l, mid, num << 1);
    if (qr > mid) Chkmin(ql, qr, val, mid + 1, r, num << 1 | 1);
  }
  void pushall(int* res, unsigned l = 1, unsigned r = n + 1, unsigned num = 1) {
    if (l == r) {
      res[l] = t[num];
      return;
    }
    unsigned mid = (l + r) >> 1;
    umin(t[num << 1], t[num]), umin(t[num << 1 | 1], t[num]);
    pushall(res, l, mid, num << 1), pushall(res, mid + 1, r, num << 1 | 1);
  }
} T;
int a[MAXN], f[MAXN];
char op[MAXN];
std::vector<std::pair<int, int> > seq[MAXN];
int main() {
  sieve(1e6);
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), f[i] = n + 1;
  scanf("%s", op + 1);
  for (int i = 1; i <= cnt; ++i)
    seq[pri[i]].emplace_back(std::pair<int, int>(0, 0));
  for (int i = 1; i <= n; ++i) {
    int x = a[i], sgn = (op[i] == '*' ? 1 : -1);
    while (x > 1) {
      int c = 0, fir = minp[x];
      while (minp[x] == fir) x /= fir, ++c;
      seq[fir].emplace_back(std::pair<int, int>(i, c * sgn));
    }
  }
  T.Chkmin(1, n, n);
  for (int w = 1; w <= cnt; ++w) {
    int p = pri[w];
    if (seq[p].size() == 1) continue;
    for (int i = 1; i < seq[p].size(); ++i) {
      sum[i] = sum[i - 1] + seq[p][i].second;
    }
    int top = 0;
    for (int i = int(seq[p].size()) - 1; i >= 0; --i) {
      while (top && sum[stk[top]] >= sum[i]) --top;
      if (top) {
        T.Chkmin(seq[p][i].first + 1, seq[p][stk[top]].first,
                 seq[p][stk[top]].first - 1);
      }
      stk[++top] = i;
    }
  }
  T.pushall(f);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += f[i] - i + 1;
  printf("%lld\n", ans);
  return 0;
}
