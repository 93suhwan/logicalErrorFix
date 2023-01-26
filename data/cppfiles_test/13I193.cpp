#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 1 && m % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    if (n % 2 == 1 && k < m / 2) {
      cout << "NO\n";
      continue;
    }
    int memo_k = k;
    int memo_n = n;
    if (n % 2 == 1) {
      --n;
      k -= m / 2;
    }
    if (k % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    if (k > m / 2 * n) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    k = memo_k;
    n = memo_n;
    vector<vector<char>> ans(n, vector<char>(m, '#'));
    if (n % 2 == 1) {
      for (int i = 1, x = 1; i < m; i += 2, x ^= 1) {
        if (x % 2 == 1) {
          ans[0][i] = 'a';
          ans[0][i - 1] = 'a';
        } else {
          ans[0][i] = 'b';
          ans[0][i - 1] = 'b';
        }
      }
      k -= m / 2;
      --n;
      for (int i = 2; i < n && k > 0; i += 2) {
        for (int j = 1; j < m && k > 0; j += 2) {
          if (ans[i - 2][j] == 'a') {
            ans[i][j] = 'a';
            ans[i][j - 1] = 'a';
            ans[i - 1][j] = 'b';
            ans[i - 1][j - 1] = 'b';
          } else {
            ans[i][j] = 'b';
            ans[i][j - 1] = 'b';
            ans[i - 1][j] = 'a';
            ans[i - 1][j - 1] = 'a';
          }
          k -= 2;
        }
      }
    } else {
      for (int i = 1, x = 1; i < n && k > 0; i += 2, x ^= 1) {
        char c1 = 'a', c2 = 'b';
        if (x % 2 == 0) {
          swap(c1, c2);
        }
        for (int j = 1; j < m && k > 0; j += 2) {
          ans[i][j] = c1;
          ans[i][j - 1] = c1;
          ans[i - 1][j] = c2;
          ans[i - 1][j - 1] = c2;
          k -= 2;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0, x = 1; j < m; ++j, x ^= 1) {
        if (ans[i][j] == '#') {
          set<char> exists;
          if (i) {
            exists.insert(ans[i - 1][j]);
          }
          if (j) {
            exists.insert(ans[i][j - 1]);
          }
          for (char c : {'c', 'd', 'e'}) {
            if (!exists.count(c)) {
              ans[i][j] = c;
              ans[i + 1][j] = c;
            }
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << ans[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
