#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int oo = 2 * 1e9;
char a[N][N];
void paintH(int i, int j) {
  char c = 'a' + i % 4 + j % 4;
  a[i][j] = a[i][j + 1] = c;
}
void paintV(int i, int j) {
  char c = 'a' + i % 4 + j % 4;
  a[i][j] = a[i + 1][j] = c;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= m + 1; ++j) a[i][j] = '#';
  if (n & 1) {
    k -= m / 2;
    for (int j = 1; j <= m; j += 2) paintH(n, j);
  }
  if (k < 0 || k & 1) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i < n; i += 2)
    for (int j = 1; j < m; j += 2)
      if (k) {
        paintH(i, j);
        paintH(i + 1, j);
        k -= 2;
      } else {
        paintV(i, j);
        paintV(i, j + 1);
      }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] == '#') paintV(i, j);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cout << a[i][j];
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
