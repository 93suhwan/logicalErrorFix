#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, k, vis[N][N], a[N][N], res[N][N];
int x[] = {-1, 0, 1, 0};
int y[] = {-1, 1, 0, -1};
int Solve(int i, int j) {
  if (i == n) return j;
  if (vis[i][j] >= 3) return res[i][j];
  vis[i][j]++;
  int who = a[i][j];
  a[i][j] = 2;
  return res[i][j] = Solve(i + x[who], j + y[who]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int j = 0; j < k; j++) {
    int c;
    cin >> c;
    cout << 1 + Solve(0, c - 1) << " ";
  }
  return 0;
}
