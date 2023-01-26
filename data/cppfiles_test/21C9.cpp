#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int f[N][N][N];
int C[N][N];
int n, m, k, M;
int fc[N];
int sum(int x, int y) { return (x + y) % M; }
int mult(long long x, long long y) { return (x * y) % M; }
int calc(int len, int m, int k) {
  if (m == 1) {
    return (k == 1 ? fc[len] : 0);
  }
  if (k > len) {
    return 0;
  }
  if (len == 1) {
    return (k == 0);
  }
  if (f[len][m][k] != -1) {
    return f[len][m][k];
  }
  f[len][m][k] = mult(2, calc(len - 1, m - 1, k));
  for (int ps = 2; ps < len; ps++) {
    int cnt = 0;
    int cur = 0;
    for (; cnt * 2 < k && cnt < ps; cnt++) {
      cur = sum(cur,
                mult(calc(ps - 1, m - 1, cnt), calc(len - ps, m - 1, k - cnt)));
    }
    cur = mult(cur, 2);
    if (cnt * 2 == k) {
      cur = sum(cur,
                mult(calc(ps - 1, m - 1, cnt), calc(len - ps, m - 1, k - cnt)));
    }
    f[len][m][k] = sum(f[len][m][k], mult(C[len - 1][ps - 1], cur));
  }
  return f[len][m][k];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> M;
  if (M == 1) {
    cout << "0";
    return 0;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int K = 0; K <= k; K++) {
        f[i][j][K] = -1;
      }
    }
  }
  C[0][0] = 1;
  fc[0] = 1;
  for (int i = 1; i <= n; i++) {
    fc[i] = mult(fc[i - 1], i);
  }
  for (int i = 1; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j]);
    }
  }
  cout << calc(n, m, k) << '\n';
}
