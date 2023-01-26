#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, k, vis[N][N], a[N][N];
int x[] = {-1, 0, 1, 0};
int y[] = {-1, 1, 0, -1};
pair<int, int> res[N][N];
pair<int, int> root(pair<int, int> A) {
  int i = A.first;
  int j = A.second;
  if (i == n) return A;
  if (res[i][j].first + 1) return res[i][j];
  if (a[i][j] != 2) return res[i][j] = A;
  A.first++;
  return res[i][j] = root(A);
}
int Solve(int i, int j) {
  if (i == n) return j;
  int who = a[i][j];
  a[i][j] = 2;
  if (who != 2) return Solve(i + x[who], j + y[who]);
  return root({i, j}).second;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) res[i][j] = {-1, -1};
  for (int j = 0; j < k; j++) {
    int c;
    cin >> c;
    cout << 1 + Solve(0, c - 1) << " ";
  }
  return 0;
}
