#include <bits/stdc++.h>
using namespace std;
int mat[50][50];
bool check(vector<int> v) {
  int cnt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (mat[v[i]][v[j]]) cnt++;
    }
  }
  if (cnt == 10 || cnt == 0) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (x > 48 || y > 48) continue;
    mat[x][y] = mat[y][x] = 1;
  }
  n = min(48, n);
  for (int a = 1; a <= n; a++) {
    for (int b = a + 1; b <= n; b++) {
      for (int c = b + 1; c <= n; c++) {
        for (int d = c + 1; d <= n; d++) {
          for (int e = d + 1; e <= n; e++) {
            if (check({a, b, c, d, e})) {
              cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
              return 0;
            }
          }
        }
      }
    }
  }
  cout << -1 << "\n";
  return 0;
}
