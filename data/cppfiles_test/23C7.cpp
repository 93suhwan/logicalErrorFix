#include <bits/stdc++.h>
using namespace std;
const int NMAX = 4000;
int N, M, a[NMAX + 2];
int m[NMAX + 2][NMAX + 2];
int sz[NMAX + 2];
int ls[NMAX + 2], lw[NMAX + 2];
int rs[NMAX + 2], rw[NMAX + 2];
long long dp[NMAX + 2][NMAX + 2];
void dfs(int node) {
  sz[node] = 1;
  if (ls[node] != 0) {
    dfs(ls[node]);
    for (int i = min(M, sz[node]); i >= 0; i--) {
      for (int j = min(M, sz[ls[node]]); j >= 0; j--) {
        dp[node][i + j] =
            max(dp[node][i + j],
                dp[node][i] + dp[ls[node]][j] + 1LL * j * (M - j) * lw[node]);
      }
    }
    sz[node] += sz[ls[node]];
  }
  if (rs[node] != 0) {
    dfs(rs[node]);
    for (int i = min(M, sz[node]); i >= 0; i--) {
      for (int j = min(M, sz[rs[node]]); j >= 0; j--) {
        dp[node][i + j] =
            max(dp[node][i + j],
                dp[node][i] + dp[rs[node]][j] + 1LL * j * (M - j) * rw[node]);
      }
    }
    sz[node] += sz[rs[node]];
  }
}
void build_tree(int l, int r) {
  if (l == r) {
    return;
  }
  int v = m[l][r];
  if (m[l][v - 1] != 0) {
    ls[v] = m[l][v - 1];
    lw[v] = a[m[l][v - 1]] - a[v];
    build_tree(l, v - 1);
  }
  if (m[v + 1][r] != 0) {
    rs[v] = m[v + 1][r];
    rw[v] = a[m[v + 1][r]] - a[v];
    build_tree(v + 1, r);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  if (M == 1) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 1; i <= N; i++) {
    m[i][i] = i;
  }
  for (int l = 2; l <= N; l++) {
    for (int i = 1; i + l - 1 <= N; i++) {
      if (a[m[i][i + l - 2]] < a[m[i + 1][i + l - 1]]) {
        m[i][i + l - 1] = m[i][i + l - 2];
      } else {
        m[i][i + l - 1] = m[i + 1][i + l - 1];
      }
    }
  }
  build_tree(1, N);
  dfs(m[1][N]);
  cout << dp[m[1][N]][M] << '\n';
  return 0;
}
