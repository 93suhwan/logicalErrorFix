#include <bits/stdc++.h>
using namespace std;
template <class T>
void Rd(T &x) {
  x = 0;
  char c;
  while (c = getchar(), c < 48)
    ;
  do x = (x << 1) + (x << 3) + (c ^ 48);
  while (c = getchar(), c > 47);
}
template <class T>
void chkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m;
int A[200005];
struct node {
  int l, r;
  node(int _l = 0, int _r = 0) : l(_l), r(_r) {}
} B[200005], C[200005];
set<int> S;
set<int>::iterator it;
long long dp[2][200005];
int L[200005];
int main() {
  int _;
  for (Rd(_); _; _--) {
    Rd(n);
    Rd(m);
    for (int i = 1; i <= n; ++i) cin >> A[i];
    sort(A + 1, A + n + 1);
    int a, b;
    for (int i = 1; i <= m; ++i) {
      cin >> a >> b;
      B[i] = node(a, b);
    }
    sort(B + 1, B + m + 1, [=](node &a, node &b) -> bool {
      if (a.r != b.r) return a.r < b.r;
      return a.l > b.l;
    });
    S.clear();
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
      int pos = lower_bound(A + 1, A + n + 1, B[i].l) - A;
      if (pos <= n && A[pos] <= B[i].r) continue;
      it = S.lower_bound(B[i].l);
      if (it != S.end()) continue;
      C[++cnt] = B[i];
      S.insert(B[i].l);
    }
    if (!cnt) {
      puts("0");
      continue;
    }
    int r = 1;
    A[n + 1] = 2e9;
    int cur = 0;
    L[0] = 1;
    dp[cur][0] = 0;
    for (int i = 1; i <= n; ++i) {
      long long res1 = 9e18, res2 = 9e18;
      if (i == 1) {
        if (C[1].l < A[1]) {
          res1 = A[1] - C[1].r;
          res2 = (long long)2 * (A[1] - C[1].r);
        } else
          res1 = res2 = 0;
        while (r <= cnt && C[r].l < A[1]) r++;
      } else {
        for (int j = L[i - 1]; j < r; ++j) {
          chkmin(res1, dp[cur][j - L[i - 1]] + A[i] - C[j].r);
          chkmin(res2, dp[cur][j - L[i - 1]] + (long long)2 * (A[i] - C[j].r));
        }
        chkmin(res1, dp[cur][r - L[i - 1]]);
        chkmin(res2, dp[cur][r - L[i - 1]]);
      }
      L[i] = r;
      while (r <= cnt && C[r].l < A[i + 1]) r++;
      cur ^= 1;
      dp[cur][0] = res1;
      for (int j = L[i]; j < r; ++j)
        dp[cur][j - L[i] + 1] =
            min(res1 + (long long)2 * (C[j].l - A[i]), res2 + C[j].l - A[i]);
    }
    printf("%lld\n", dp[cur][r - L[n]]);
  }
  return 0;
}
