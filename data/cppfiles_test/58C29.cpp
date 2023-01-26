#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 50, MOD = 998244353, MAXX = 4e5;
struct SegTree {
  int sum[MAXN << 2];
  int ls(int x) { return x << 1; }
  int rs(int x) { return x << 1 | 1; }
  void push_up(int now) { sum[now] = sum[ls(now)] + sum[rs(now)]; }
  void build(int l, int r, int now) {
    if (l == r) {
      sum[now] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls(now));
    build(mid + 1, r, rs(now));
    push_up(now);
  }
  void change(int x, int k, int l, int r, int now) {
    if (x == l && l == r) {
      sum[now] += k;
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
      change(x, k, l, mid, ls(now));
    else
      change(x, k, mid + 1, r, rs(now));
    push_up(now);
  }
  int search(int x, int l, int r, int now) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (x <= sum[ls(now)]) return search(x, l, mid, ls(now));
    return search(x - sum[ls(now)], mid + 1, r, rs(now));
  }
};
int qpow(int x, int y) {
  int res = 1;
  for (; y; x = 1ll * x * x % MOD, y >>= 1)
    if (y & 1) res = 1ll * res * x % MOD;
  return res;
}
int inv(int x) { return qpow(x, MOD - 2); }
SegTree A;
queue<int> q;
int N, M, mul[MAXN], invv[MAXN], Ans = 0;
pair<int, int> a[MAXN];
int C(int n, int m) { return 1ll * mul[n] * invv[m] % MOD * invv[n - m] % MOD; }
void prepare() {
  A.build(1, MAXX, 1);
  mul[0] = invv[0] = 1;
  for (int i = 1; i <= MAXX; ++i) mul[i] = 1ll * mul[i - 1] * i % MOD;
  invv[MAXX] = inv(mul[MAXX]);
  for (int i = MAXX - 1; i >= 1; --i)
    invv[i] = 1ll * invv[i + 1] * (i + 1) % MOD;
}
void Init() {
  while (!q.empty()) q.pop();
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; ++i) scanf("%d%d", &a[i].first, &a[i].second);
}
void Solve() {
  int cnt = 0;
  for (int i = M; i >= 1; --i) {
    int x = A.search(a[i].second, 1, MAXX, 1),
        y = A.search(a[i].second + 1, 1, MAXX, 1);
    if (y == x + 1) ++cnt;
    A.change(x, -1, 1, MAXX, 1);
    q.push(x);
  }
  Ans = C(2 * N - cnt - 1, N);
  while (!q.empty()) {
    A.change(q.front(), 1, 1, MAXX, 1);
    q.pop();
  }
}
void Print() { printf("%d\n", Ans); }
int main() {
  prepare();
  int T;
  cin >> T;
  while (T--) {
    Init();
    Solve();
    Print();
  }
  return 0;
}
