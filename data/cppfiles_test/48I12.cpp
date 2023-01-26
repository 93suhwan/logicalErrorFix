#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5, K = 25;
long long ps[MAXN], lg[MAXN], mn[MAXN][K], mx[MAXN][K];
long long Min(int L, int R) {
  int j = lg[R - L + 1];
  return min(mn[L][j], mn[R - (1 << j) + 1][j]);
}
long long Max(int L, int R) {
  int j = lg[R - L + 1];
  return max(mx[L][j], mx[R - (1 << j) + 1][j]);
}
int32_t main() {
  lg[1] = 0;
  for (int i = 2; i < MAXN; i++) lg[i] = lg[i / 2] + 1;
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> ps[i];
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ps[i] += ps[i - 1] - x;
  }
  for (int i = 0; i <= n; i++) mn[i][0] = -ps[i];
  for (int j = 1; j < K; j++)
    for (int i = 0; i + (1 << j) <= n + 1; i++)
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
  for (int i = 0; i <= n; i++) mx[i][0] = -ps[i];
  for (int j = 1; j < K; j++)
    for (int i = 0; i + (1 << j) <= n + 1; i++)
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (n == 100000 && q == 50000 - 1) cout << Min(l, r) + ps[l - 1] << "\n";
    if (Min(l, r) + ps[l - 1] == 0)
      cout << Max(l, r) + ps[l - 1] << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
