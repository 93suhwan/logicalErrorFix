#include <bits/stdc++.h>
using namespace std;
const int NN = 305 * 305;
int c[NN];
inline int lb(int x) { return x & -x; }
void add(int x, int d) {
  for (; x < NN; x += lb(x)) c[x] += d;
}
int getsum(int x) {
  int r = 0;
  for (; x; x -= lb(x)) r += c[x];
  return r;
}
int n, m, sz, A[NN], S[NN], a[NN], s[NN];
int solve(int n, int m, int* a, int* s) {
  ;
  sz = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      ++sz;
      s[sz] = sz;
      ;
    }
  }
  sort(s + 1, s + 1 + n * m, [&](int i, int j) {
    if (a[i] != a[j]) return a[i] < a[j];
    return i > j;
  });
  int ans = 0;
  for (int i = 1; i <= n * m; ++i) {
    ;
    ans += getsum(s[i]);
    ;
    add(s[i], 1);
  }
  for (int i = 1; i <= n * m; ++i) add(s[i], -1);
  return ans;
}
void solve(int Case) {
  scanf("%d %d", &n, &m);
  sz = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &A[++sz]);
      S[sz] = sz;
    }
  }
  sort(S + 1, S + n * m + 1, [&](int i, int j) -> bool {
    if (A[i] != A[j]) return A[i] < A[j];
    return i < j;
  });
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    sort(S + (i - 1) * m + 1, S + i * m + 1,
         [&](int i, int j) -> bool { return i < j; });
    for (int j = 1; j <= m; ++j) a[j] = A[S[(i - 1) * m + j]];
    ans += solve(1, m, a, s);
  }
  printf("%d\n", ans);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) solve(t);
  return 0;
}
