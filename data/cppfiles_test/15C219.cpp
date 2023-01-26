#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int qq;
  cin >> qq;
  while (qq--) {
    int n, m, k;
    cin >> n >> m >> k;
    char gr[n][m];
    bool canp[n][m];
    memset(canp, 0, sizeof(canp));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> gr[i][j];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        bool here = 1;
        for (int h = 0; h <= k; h++)
          here &= (i - h >= 0 && j - h >= 0 && gr[i - h][j - h] == '*' &&
                   i - h >= 0 && j + h < m && gr[i - h][j + h] == '*');
        if (here)
          for (int h = 0; i - h >= 0 && j - h >= 0 && j + h < m &&
                          gr[i - h][j - h] == '*' && gr[i - h][j + h] == '*';
               h++)
            canp[i - h][j - h] = canp[i - h][j + h] = 1;
      }
    }
    bool ok = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (gr[i][j] == '*') ok &= canp[i][j];
    cout << (ok ? "YES" : "NO") << "\n";
  }
  return 0;
}
