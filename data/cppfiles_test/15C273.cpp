#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> t1(n, vector<char>(m)), t2(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> t1[i][j];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int h = 0;
        while (i - h >= 0 && j + h < m && j - h >= 0 &&
               t1[i - h][j - h] == t1[i - h][j + h] &&
               t1[i - h][j - h] == '*') {
          h++;
        }
        if (h - 1 >= k) {
          h = 0;
          while (i - h >= 0 && j + h < m && j - h >= 0 &&
                 t1[i - h][j - h] == t1[i - h][j + h] &&
                 t1[i - h][j - h] == '*') {
            t2[i - h][j - h] = t2[i - h][j + h] = '*';
            h++;
          }
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) ok &= (t1[i][j] == t2[i][j]);
    cout << (ok ? "YES" : "NO") << endl;
  }
}
