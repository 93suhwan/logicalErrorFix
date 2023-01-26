#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
char mat[105][105];
void solve() {
  int n, m, horizontal;
  cin >> n >> m >> horizontal;
  int vertical = n * m / 2 - horizontal;
  int oxe = 0, nte = 0;
  if (n % 2 != m % 2) {
    if (n % 2 == 0) {
      for (int i = 0; i < n; i += 2) {
        mat[i][m - 1] = mat[i + 1][m - 1] = 'z';
      }
      vertical -= n / 2;
      m--;
      nte = 1;
    } else {
      for (int j = 0; j < m; j += 2) {
        mat[n - 1][j] = mat[n - 1][j + 1] = 'z';
      }
      horizontal -= m / 2;
      n--;
      oxe = 1;
    }
  }
  assert(n % 2 == 0 && m % 2 == 0);
  int puth = n * m / 2;
  int putv = 0;
  char mofio[] = {'a', 'b'};
  int cur = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j += 2) {
      mat[i][j] = mat[i][j + 1] = mofio[cur];
      cur ^= 1;
    }
    if (m % 4 == 0) cur ^= 1;
  }
  mofio[0] = 'c', mofio[1] = 'd';
  cur = 0;
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; j += 2) {
      if (puth == horizontal && putv == vertical) {
        cout << "YES\n";
        for (int ii = 0; ii < n + oxe; ii++) {
          for (int jj = 0; jj < m + nte; jj++) {
            cout << mat[ii][jj];
          }
          cout << '\n';
        }
        return;
      }
      mat[i][j] = mat[i + 1][j] = mofio[cur];
      mat[i][j + 1] = mat[i + 1][j + 1] = mofio[cur ^ 1];
      puth -= 2;
      putv += 2;
    }
    cur ^= 1;
  }
  if (puth == horizontal && putv == vertical) {
    cout << "YES\n";
    for (int ii = 0; ii < n + oxe; ii++) {
      for (int jj = 0; jj < m + nte; jj++) {
        cout << mat[ii][jj];
      }
      cout << '\n';
    }
    return;
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
