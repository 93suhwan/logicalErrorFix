#include <bits/stdc++.h>
using namespace std;
const long long MaxM = 9 * 1e15;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  string s[n];
  for (auto &i : s) {
    cin >> i;
  }
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        int p = i, q = j, c = 0, d = 0;
        while (p >= 0 && q < m) {
          if (s[p][q] == '*') {
            c++;
          } else {
            break;
          }
          p--;
          q++;
        }
        p = i;
        q = j;
        while (p >= 0 && q >= 0) {
          if (s[p][q] == '*') {
            d++;
          } else {
            break;
          }
          p--;
          q--;
        }
        c = min(c, d);
        if (c > k) {
          p = i;
          q = j;
          d = 0;
          while (p >= 0 && q >= 0) {
            vis[p][q] = true;
            d++;
            p--;
            q--;
            if (c == d) {
              break;
            }
          }
          p = i;
          q = j;
          d = 0;
          while (p >= 0 && q < m) {
            d++;
            vis[p][q] = true;
            p--;
            q++;
            if (c == d) {
              break;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*' && vis[i][j] == false) {
        no();
        return;
      }
    }
  }
  yes();
}
int main() {
  fast();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
