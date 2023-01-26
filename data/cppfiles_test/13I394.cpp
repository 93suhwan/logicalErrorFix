#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e9;
char c[101][101];
void filmap(int n, int m, int hc) {
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; j += 2) {
      char fc, sc;
      if ((i + j) % 4 == 0) {
        fc = 'a';
        sc = 'b';
      } else {
        fc = 'c';
        sc = 'd';
      }
      if (hc) {
        c[i][j] = c[i][j + 1] = fc;
        c[i + 1][j] = c[i + 1][j + 1] = sc;
        hc -= 2;
      } else {
        c[i][j] = c[i + 1][j] = fc;
        c[i][j + 1] = c[i][j + 1] = sc;
      }
    }
  }
}
void coutmap(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << c[i][j];
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int hc = k;
    int vc = n * m / 2 - k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) c[i][j] = 60;
    if (n % 2 == 0 && m % 2 == 0) {
      if (hc & 1)
        cout << "NO\n";
      else
        cout << "YES\n";
      filmap(n, m, hc);
      coutmap(n, m);
      continue;
    } else if (n % 2 == 1) {
      if (hc < m / 2)
        cout << "NO\n";
      else if ((hc % 2) != ((m / 2) % 2))
        cout << "NO\n";
      else {
        cout << "YES\n";
        hc -= (m / 2);
        for (int j = 0; j < m; j += 2) {
          if ((j / 2) % 2 == 0)
            c[n - 1][j] = c[n - 1][j + 1] = 'z';
          else
            c[n - 1][j] = c[n - 1][j + 1] = 'y';
        }
        filmap(n, m, hc);
        coutmap(n, m);
      }
    } else {
      if (vc < n / 2)
        cout << "NO\n";
      else if ((vc % 2) != ((n / 2) % 2))
        cout << "NO\n";
      else {
        cout << "YES\n";
        for (int i = 0; i < n; i += 2) {
          if ((i / 2) % 2)
            c[i][m - 1] = c[i + 1][m - 1] = 'z';
          else
            c[i][m - 1] = c[i + 1][m - 1] = 'y';
        }
        filmap(n, m, hc);
        coutmap(n, m);
      }
    }
  }
}
