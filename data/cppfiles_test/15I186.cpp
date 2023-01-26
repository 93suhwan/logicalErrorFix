#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, s;
  cin >> n >> m >> s;
  vector<vector<char>> v(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long int count = 0, pount = 0;
      if (v[i][j] == '*') {
        int z = j;
        for (int k = i - 1; k >= 0 and z - 1 >= 0; k--) {
          if (v[k][z - 1] != '*' and v[k][z - 1] != '1') {
            break;
          }
          count++;
          z--;
        }
        z = j;
        for (int k = i - 1; k >= 0 and z + 1 < m; k--) {
          if (v[k][z + 1] != '*' and v[k][z - 1] != '1') {
            break;
          }
          pount++;
          z++;
        }
        if (count >= s and pount >= s) {
          int z = j;
          v[i][j] = '1';
          for (int k = i - 1; k >= 0 and z - 1 >= 0; k--) {
            if (v[k][z - 1] != '*' and v[k][z - 1] != '1') {
              break;
            }
            v[k][z - 1] = '1';
            z--;
          }
          z = j;
          for (int k = i - 1; k >= 0 and z + 1 < m; k--) {
            if (v[k][z + 1] != '*' and v[k][z + 1] != '1') {
              break;
            }
            v[k][z + 1] = '1';
            z++;
          }
        }
      }
    }
  }
  for (auto it : v) {
    for (auto pt : it) {
      if (pt == '*') {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
