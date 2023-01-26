#include <bits/stdc++.h>
using namespace std;
char c[110][110];
void smain() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k > m / 2 * n) {
    cout << "NO\n";
    return;
  }
  if (k && m == 1) {
    cout << "NO\n";
    return;
  }
  if (n % 2 == 0) {
    if (k % 2) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    int q = k / (m / 2 * 2);
    int w = k % (m / 2 * 2);
    for (int i = 0; i < q; i++) {
      for (int j = 0; j < m; j += 4) {
        c[i + i][j] = c[i + i][j + 1] = c[i + i + 1][j + 2] =
            c[i + i + 1][j + 3] = 'a';
        c[i + i + 1][j] = c[i + i + 1][j + 1] = c[i + i][j + 2] =
            c[i + i][j + 3] = 'b';
      }
      if (m / 2 % 2) c[i + i][m / 4 * 4] = c[i + i][m / 4 * 4 + 1] = 'a';
      if (m / 2 % 2)
        c[i + i + 1][m / 4 * 4] = c[i + i + 1][m / 4 * 4 + 1] = 'b';
      if (m % 2) c[i + i][m - 1] = 'c' + i % 2;
      if (m % 2) c[i + i + 1][m - 1] = 'c' + i % 2;
    }
    for (int i = 0; i < w / 2; i++) {
      c[q + q][i] = c[q + q][i + 1] = 'a';
      c[q + q + 1][i] = c[q + q + 1][i + 1] = 'b';
    }
    for (int i = w; i < m; i++) {
      c[q + q][i] = 'e' + i % 2;
      c[q + q + 1][i] = 'e' + i % 2;
    }
    for (int j = q + 1; j <= n / 2; j++) {
      for (int i = 0; i < m; i++) {
        c[j + j][i] = 'e' + ((i % 2) != ((j - q) % 2));
        c[j + j + 1][i] = 'e' + ((i % 2) != ((j - q) % 2));
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << c[i][j];
      cout << endl;
    }
    return;
  } else {
    if (k < m / 2) {
      cout << "NO\n";
      return;
    };
    k -= m / 2;
    if (k % 2) {
      cout << "NO\n";
      return;
    };
    cout << "YES\n";
    int q = k / (m / 2 * 2);
    int w = k % (m / 2 * 2);
    for (int i = 0; i < m; i += 4)
      c[0][i] = c[0][i + 1] = 'b', c[0][i + 2] = c[0][i + 3] = 'a';
    for (int i = 0; i < q; i++) {
      for (int j = 0; j < m; j += 4) {
        c[i + i + 1][j] = c[i + i + 1][j + 1] = c[i + i + 2][j + 2] =
            c[i + i + 2][j + 3] = 'x';
        c[i + i + 2][j] = c[i + i + 2][j + 1] = c[i + i + 1][j + 2] =
            c[i + i + 1][j + 3] = 'y';
      }
      if (m / 2 % 2)
        c[i + i + 1][m / 4 * 4] = c[i + i + 1][m / 4 * 4 + 1] = 'a';
      if (m / 2 % 2)
        c[i + i + 2][m / 4 * 4] = c[i + i + 2][m / 4 * 4 + 1] = 'b';
    }
    for (int i = 0; i <= w / 2; i++) {
      c[q + q + 1][i] = c[q + q + 1][i + 1] = 'h';
      c[q + q + 2][i] = c[q + q + 2][i + 1] = 'i';
    }
    for (int i = w; i < m; i++) {
      c[q + q + 1][i] = 'e' + i % 2;
      c[q + q + 2][i] = 'e' + i % 2;
    }
    for (int j = q; j <= n / 2 + 1; j++) {
      for (int i = 0; i < m; i++) {
        c[j + j + 3][i] = 'e' + ((i % 2) != ((j - q) % 2));
        c[j + j + 4][i] = 'e' + ((i % 2) != ((j - q) % 2));
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << c[i][j];
      cout << endl;
    }
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    smain();
  }
}
