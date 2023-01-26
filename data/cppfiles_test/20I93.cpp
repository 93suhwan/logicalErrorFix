#include <bits/stdc++.h>
using namespace std;
const int N = 400 + 5, INF = 1e9 + 5;
int t, n, m, ans;
char arr[N][N];
int check(int x, int y) {
  int cnt = 0;
  for (int i = 1; i <= 2; i++)
    if (arr[x][y + i] != '1') cnt++;
  for (int i = 1; i <= 2; i++)
    if (arr[x + 4][y + i] != '1') cnt++;
  for (int i = 1; i <= 3; i++)
    if (arr[x + i][y] != '1') cnt++;
  for (int i = 1; i <= 3; i++)
    if (arr[x + i][y + 3] != '1') cnt++;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 2; j++) {
      if (arr[x + i][y + j] != '0') cnt++;
    }
  }
  return cnt;
}
void solve() {
  ans = INF;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 1; i <= n - 5 + 1; i++) {
    for (int j = 1; j <= m - 4 + 1; j++) {
      ans = min(ans, check(i, j));
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    solve();
  }
}
