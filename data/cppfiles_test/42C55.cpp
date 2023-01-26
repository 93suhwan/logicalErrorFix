#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int N, M;
pair<int, int> A[202020];
pair<int, int> B[202020];
long long D[202020];
struct Node {
  long long x = 0;
  int l = 0, r = 0;
};
struct PST {
  Node T[20 * 202020];
  int rt[202020];
  int id = 0;
  int tid = 0;
  int build(int bef, int s, int e, int p, long long x) {
    if (p < s || e < p) return bef;
    int now = ++id;
    if (s == e) {
      T[now].x = (T[bef].x + x) % MOD;
      return now;
    }
    int m = s + e >> 1;
    T[now].l = build(T[bef].l, s, m, p, x);
    T[now].r = build(T[bef].r, m + 1, e, p, x);
    T[now].x = (T[T[now].l].x + T[T[now].r].x) % MOD;
    return now;
  }
  void upd(int x, long long y) {
    tid++;
    rt[tid] = build(rt[tid - 1], 1, 2 * N, x, y);
  }
  long long get(int idx, int s, int e, int p, int q) {
    if (q < p || q < s || e < p) return 0;
    if (p <= s && e <= q) return T[idx].x;
    int m = s + e >> 1;
    return (get(T[idx].l, s, m, p, q) + get(T[idx].r, m + 1, e, p, q)) % MOD;
  }
  long long query(int x, int p, int q) { return get(rt[x], 1, 2 * N, p, q); }
} pst;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", &A[i].second, &A[i].first);
  }
  scanf("%d", &M);
  for (int i = 1; i <= M; i++) {
    int t;
    scanf("%d", &t);
    B[i] = A[t];
  }
  sort(A + 1, A + N + 1);
  sort(B + 1, B + M + 1);
  for (int i = 1; i <= N; i++) {
    D[i] = (1 + pst.query(i - 1, A[i].second + 1, A[i].first - 1)) % MOD;
    pst.upd(A[i].second, D[i]);
  }
  long long ans = 0;
  int t = lower_bound(A + 1, A + N + 1, B[M]) - A;
  for (int i = 1; i < t; i++) ans = (ans + D[i]) % MOD;
  ans = (ans + 1) % MOD;
  int l = B[M].second + 1;
  t--;
  while (t) {
    if (B[t].second < l) {
      t--;
      continue;
    }
    ans = (ans + 1) % MOD;
    int tmp = lower_bound(A + 1, A + N + 1, B[t]) - A;
    ans = (ans + pst.query(tmp - 1, l, B[t].first - 1)) % MOD;
    l = B[t].second + 1;
    t--;
  }
  printf("%lld\n", ans);
  return 0;
}
