#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
bool valid(int i, int j) { return (0 <= i && i < n && 0 <= j && j < m); }
void solve() {
  int k;
  cin >> n >> m >> k;
  vector<string> g(n);
  for (auto &s : g) cin >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '*' || g[i][j] == '^') {
        int offset = 1;
        vector<string> ng = g;
        while (valid(i - offset, j - offset) && valid(i - offset, j + offset)) {
          if ((ng[i - offset][j - offset] != '*' ||
               ng[i - offset][j + offset] != '*') &&
              (ng[i - offset][j - offset] != '^' ||
               ng[i - offset][j + offset] != '*') &&
              (ng[i - offset][j - offset] != '*' ||
               ng[i - offset][j + offset] != '^') &&
              (ng[i - offset][j - offset] != '^' ||
               ng[i - offset][j + offset] != '^'))
            break;
          ng[i - offset][j - offset] = '^';
          ng[i - offset][j + offset] = '^';
          offset++;
        }
        if (offset >= k + 1) {
          ng[i][j] = '^';
          g = ng;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '*') {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
