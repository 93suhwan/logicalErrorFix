#include <bits/stdc++.h>
using namespace std;
namespace Input {
inline char Sc() {
  static const int LEN = 100000;
  static char Buf[LEN], *OP = Buf, *ED = Buf;
  if (OP == ED) {
    ED = (OP = Buf) + fread(Buf, 1, LEN, stdin);
    if (OP == ED) return -1;
  }
  return *OP++;
}
template <class T>
inline bool rd(T &x) {
  static char c, f;
  f = 1;
  for (x = 0, c = Sc(); c < 48; c = Sc()) {
    if (!~c) return 0;
    if (!(c ^ '-')) f = -1;
  }
  for (; c > 47; c = Sc()) x = (x << 1) + (x << 3) + (c ^ 48);
  x *= f;
  return 1;
}
}  // namespace Input
int A[1000010], B[1000010], C[1000010 << 1], E[1000010 << 1];
int n, m, h;
struct edge {
  int nxt, t;
} e[1000010 << 1];
int head[1000010 << 1], edge_cnt;
void add_edge(int x, int y) {
  e[edge_cnt] = (edge){head[x], y};
  head[x] = edge_cnt++;
}
struct Segment_Tree {
  int Mn[1000010 << 2], Upd[1000010 << 2];
  void build(int l, int r, int p) {
    Upd[p] = 0;
    Mn[p] = l - 1;
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, (p << 1));
    build(mid + 1, r, (p << 1 | 1));
  }
  void Update(int l, int r, int p, int pl, int pr, int x) {
    if (pl > pr) {
      return;
    }
    if (l == pl && r == pr) {
      Upd[p] += x;
      Mn[p] += x;
      return;
    }
    int mid = (l + r) >> 1;
    if (Upd[p]) {
      Upd[(p << 1)] += Upd[p];
      Upd[(p << 1 | 1)] += Upd[p];
      Mn[(p << 1)] += Upd[p];
      Mn[(p << 1 | 1)] += Upd[p];
      Upd[p] = 0;
    }
    if (pr <= mid) {
      Update(l, mid, (p << 1), pl, pr, x);
    } else if (pl > mid) {
      Update(mid + 1, r, (p << 1 | 1), pl, pr, x);
    } else {
      Update(l, mid, (p << 1), pl, mid, x);
      Update(mid + 1, r, (p << 1 | 1), mid + 1, pr, x);
    }
    Mn[p] = min(Mn[(p << 1)], Mn[(p << 1 | 1)]);
  }
} T;
struct Binary_Indexed_Tree {
  int bit[1000010 << 1];
  void Add(int i) {
    while (i > 0) {
      bit[i]++;
      i -= i & -i;
    }
  }
  int Query(int i) {
    int res = 0;
    while (i <= h) {
      res += bit[i];
      i += i & -i;
    }
    return res;
  }
} BIT;
int main() {
  int Case;
  Input::rd(Case);
  while (Case--) {
    Input::rd(n);
    Input::rd(m);
    int i, j;
    for (i = 1; i <= n; i++) {
      Input::rd(A[i]);
      C[i] = A[i];
    }
    for (i = 1; i <= m; i++) {
      Input::rd(B[i]);
      C[i + n] = B[i];
    }
    sort(C + 1, C + 1 + n + m);
    h = unique(C + 1, C + 1 + n + m) - C - 1;
    for (i = 1; i <= h; i++) {
      E[i] = 0;
    }
    memset(head + 1, -1, sizeof(int) * h);
    edge_cnt = 0;
    for (i = 1; i <= n; i++) {
      A[i] = lower_bound(C + 1, C + 1 + h, A[i]) - C;
      add_edge(A[i], i);
    }
    for (i = 1; i <= m; i++) {
      B[i] = lower_bound(C + 1, C + 1 + h, B[i]) - C;
      E[B[i]]++;
    }
    long long Ans = 0;
    memset(BIT.bit + 1, 0, sizeof(int) * h);
    for (i = 1; i <= n; i++) {
      Ans += BIT.Query(A[i]);
      BIT.Add(A[i] - 1);
    }
    T.build(1, n, 1);
    for (i = 1; i <= h; i++) {
      for (j = head[i]; ~j; j = e[j].nxt) {
        int x = e[j].t;
        T.Update(1, n, 1, x + 1, n, -1);
      }
      Ans += 1LL * E[i] * T.Mn[1];
      for (j = head[i]; ~j; j = e[j].nxt) {
        int x = e[j].t;
        T.Update(1, n, 1, 1, x - 1, 1);
      }
    }
    printf("%lld\n", Ans);
  }
  return 0;
}
