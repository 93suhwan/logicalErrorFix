#include <bits/stdc++.h>
using namespace std;
int n, d[200000 + 5], G[200000 + 5], F[200000 + 5], k, Id[200000 + 5], R, B, W,
    x, y, fa[200000 + 5];
struct yyy {
  int to, z;
} tmp;
struct ljb {
  int head, h[200000 + 5];
  yyy f[200000 + 5 << 1];
  inline void add(int x, int y) {
    f[++head] = (yyy){y, h[x]};
    h[x] = head;
  }
} s;
struct Ques {
  int id, w;
  bool operator<(const Ques &B) const { return w < B.w; };
} now;
priority_queue<Ques> Q;
inline void dfs(int x, int La) {
  d[x] = d[La] + 1;
  fa[x] = La;
  yyy tmp;
  Id[x] = x;
  F[x] = d[x];
  for (register int i = s.h[x]; i; i = tmp.z)
    tmp = s.f[i],
    tmp.to ^ La && (dfs(tmp.to, x),
                    F[tmp.to] > F[x] && (F[x] = F[tmp.to], Id[x] = Id[tmp.to]));
}
inline long long calc(int W, int R, int B) { return 1ll * W * (R - B); }
int main() {
  register int i, j;
  scanf("%d%d", &n, &k);
  for (i = 1; i < n; i++) scanf("%d%d", &x, &y), s.add(x, y), s.add(y, x);
  dfs(1, 0);
  Q.push((Ques){1, F[1]});
  while (R < k) {
    if (Q.empty()) break;
    now = Q.top();
    Q.pop();
    W += now.w - 1;
    R++;
    x = Id[now.id];
    y = 0;
    while (y ^ now.id) {
      for (j = s.h[x]; j; j = tmp.z)
        tmp = s.f[j], tmp.to ^ y && tmp.to ^ fa[x] &&
                          (Q.push((Ques){tmp.to, F[tmp.to] - d[x]}), 0);
      y = x;
      x = fa[x];
    }
  }
  B = n - W - R;
  while (R < k && calc(W, R, B) < calc(W - 1, R + 1, B)) W--, R++;
  while (B && calc(W, R, B) > calc(W + 1, R, B - 1)) B--, W++;
  printf("%lld\n", calc(W, R, B));
}
