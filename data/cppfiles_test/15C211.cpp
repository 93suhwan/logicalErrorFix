#include <bits/stdc++.h>
using namespace std;
int dx[] = {+1, -1, +0, +0};
int dy[] = {+0, +0, +1, -1};
int vis[20][20];
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long n, m, k;
    cin >> n >> m >> k;
    string res = "YES", s[n + 1];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = k - 1; i < n; i++) {
      for (int j = k - 1; j <= m - k; j++) {
        if (s[i][j] != '.') {
          int l = j, r = j, cnt = 0, h = i;
          vector<pair<int, int> > v1;
          while (l >= 0 && s[h][l] != '.' && s[h][r] != '.' && r < m &&
                 h >= 0) {
            v1.push_back({h, l});
            v1.push_back({h, r});
            l--;
            r++;
            h--;
            if (h < 0 || r >= m || l < 0) break;
          }
          if (v1.size() > 2 * k) {
            for (auto x : v1) {
              s[x.first][x.second] = '#';
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '*') res = "NO";
      }
    }
    cout << res << endl;
  }
  return 0;
}
