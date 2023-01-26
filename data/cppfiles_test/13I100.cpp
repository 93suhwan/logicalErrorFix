#include <bits/stdc++.h>
using namespace std;
const int MAX = 200;
const int mod = 1e9 + 7;
int t, n, m, k, sol[MAX][MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    bool flip = 0;
    if (n & 1) {
      swap(n, m);
      k = n * m / 2 - k;
      flip = 1;
    }
    if (m & 1) {
      if (k & 1 || k > (m - 1) * n / 2)
        cout << "NO\n";
      else {
        cout << "YES\n";
        int id = 0, id2 = 0, k2 = n * m / 2 - k;
        for (int i = 1; i < m; i += 2) {
          id ^= 1;
          id2 = id;
          for (int j = 1; k > 0 && j <= n; j++) {
            sol[j][i] = sol[j][i + 1] = id2 + 1;
            id2 ^= 1;
            k--;
          }
        }
        id = id2 = 0;
        for (int i = 1; i <= n; i += 2) {
          sol[i][m] = sol[i + 1][m] = id + 3;
          id ^= 1;
          k2--;
        }
        id = 1;
        for (int i = m - 1; i > 0; i -= 2) {
          id2 = id;
          for (int j = n; k2 > 0 && j > 0; j -= 2) {
            k2 -= 2;
            sol[j][i] = sol[j - 1][i] = id2 + 3;
            sol[j][i - 1] = sol[j - 1][i - 1] = 1 - id2 + 3;
            id2 ^= 1;
          }
        }
        if (flip) {
          for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) cout << (char)('a' - 1 + sol[j][i]);
            cout << '\n';
          }
        } else {
          for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cout << (char)('a' - 1 + sol[i][j]);
            cout << '\n';
          }
        }
      }
    } else {
      if (k & 1)
        cout << "NO\n";
      else {
        cout << "YES\n";
        int id = 0, id2 = 0, k2 = n * m / 2 - k;
        for (int i = 1; i < m; i += 2) {
          id ^= 1;
          id2 = id;
          for (int j = 1; k > 0 && j <= n; j++) {
            sol[j][i] = sol[j][i + 1] = id2 + 1;
            id2 ^= 1;
            k--;
          }
        }
        id = 1;
        for (int i = m; i > 0; i -= 2) {
          id2 = id;
          for (int j = n; k2 > 0 && j > 0; j -= 2) {
            k2 -= 2;
            sol[j][i] = sol[j - 1][i] = id2 + 3;
            sol[j][i - 1] = sol[j - 1][i - 1] = 1 - id2 + 3;
            id2 ^= 1;
          }
        }
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) cout << (char)('a' - 1 + sol[i][j]);
          cout << '\n';
        }
      }
    }
  }
}
