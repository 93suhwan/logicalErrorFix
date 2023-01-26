#include <bits/stdc++.h>
using namespace std;
struct LiChaoNode {
  long long l, r, a, b;
};
struct UndoNode {
  int n;
  long long a, b;
};
struct LiChao {
  vector<LiChaoNode> seg;
  vector<vector<UndoNode> > undo;
  vector<pair<int, bool> > undo2;
  int P;
  long long L, R;
  LiChao() {}
  LiChao(int q, long long l, long long r) {
    seg = vector<LiChaoNode>(q + 2, {0, 0, 0, 8000000000000000000});
    P = 2;
    L = l;
    R = r;
  }
  void Update(long long a, long long b, int n, long long l, long long r) {
    long long &sa = seg[n].a, &sb = seg[n].b;
    if (a * l + b < sa * l + sb) {
      swap(a, sa), swap(b, sb);
    }
    if (a * r + b > sa * r + sb) return;
    if (l == r) return;
    long long m = l + r >> 1;
    if (a * m + b < sa * m + sb) {
      swap(a, sa), swap(b, sb);
      if (seg[n].l == 0) {
        seg[n].l = P++;
      }
      Update(a, b, seg[n].l, l, m);
    } else {
      if (seg[n].r == 0) {
        seg[n].r = P++;
      }
      Update(a, b, seg[n].r, m + 1, r);
    }
  }
  void Update(long long a, long long b) { return Update(a, b, 1, L, R); }
  long long Query(long long x, int n, long long l, long long r) {
    if (n == 0) return 8000000000000000000;
    long long &sa = seg[n].a, &sb = seg[n].b;
    long long m = l + r >> 1;
    if (x <= m) return min(sa * x + sb, Query(x, seg[n].l, l, m));
    return min(sa * x + sb, Query(x, seg[n].r, m + 1, r));
  }
  long long Query(long long x) { return Query(x, 1, L, R); }
  void Undo() {
    for (int i = (int)undo.back().size() - 1; i >= 0; i--) {
      auto &it = undo.back()[i];
      seg[it.n].a = it.a;
      seg[it.n].b = it.b;
    }
    if (undo2.back().first) {
      if (undo2.back().second == false)
        seg[undo2.back().first].l = 0;
      else
        seg[undo2.back().first].r = 0;
      P--;
    }
    undo.pop_back();
    undo2.pop_back();
  }
};
int N, M;
string s[2020];
int A[2020];
long long res[2020][2020];
int main() {
  memset(res, 0x3f, sizeof(res));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  cin >> N >> M;
  N++;
  M++;
  for (int i = 0; i < N; i++) cin >> s[i];
  memset(A, -1, sizeof(A));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      if (s[i][j] == '1') A[j] = i;
    LiChao tree(M, 0, 2000);
    for (int j = 0; j < M; j++) {
      if (A[j] != -1) {
        int xj = j, yj = A[j], yi = i;
        tree.Update(-2 * xj, xj * xj - 2 * yi * yj + yj * yj);
      }
    }
    for (int j = 0; j < M; j++) {
      int xi = j, yi = i;
      res[i][j] = min(res[i][j], tree.Query(xi) + xi * xi + yi * yi);
    }
  }
  memset(A, -1, sizeof(A));
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < M; j++)
      if (s[i][j] == '1') A[j] = i;
    LiChao tree(M, 0, 2000);
    for (int j = 0; j < M; j++) {
      if (A[j] != -1) {
        int xj = j, yj = A[j], yi = i;
        tree.Update(-2 * xj, xj * xj - 2 * yi * yj + yj * yj);
      }
    }
    for (int j = 0; j < M; j++) {
      int xi = j, yi = i;
      res[i][j] = min(res[i][j], tree.Query(xi) + xi * xi + yi * yi);
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) ans += res[i][j];
  cout << ans << "\n";
  return 0;
}
