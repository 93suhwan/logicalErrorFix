#include <bits/stdc++.h>
using namespace std;
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int nn = n - (n % 2 == 1);
    int mm = m - (m % 2 == 1);
    long long maxx = (nn / 2) * (mm / 2) * 2;
    if (n != nn) {
      maxx += m / 2;
      if (m / 2 > k || (k - m / 2) % 2 == 1) {
        cout << "NO" << endl;
        continue;
      }
    } else {
      if (k % 2 == 1) {
        cout << "NO" << endl;
        continue;
      }
    }
    if (maxx < k) {
      cout << "NO" << endl;
      continue;
    }
    vector<vector<char>> l = {{'a', 'b', 'c', 'd'}, {'x', 'y', 'z', 'w'}};
    vector<char> let = {'m', 'n'};
    int q = 0;
    vector<vector<char>> ans(n, vector<char>(m));
    if (n != nn) {
      for (int i = 0; i < m; i += 2) {
        k--;
        ans[n - 1][i] = let[q];
        ans[n - 1][i + 1] = let[q];
        q = (q + 1) % 2;
      }
    }
    q = 0;
    if (m != mm) {
      for (int i = 0; i < n; i += 2) {
        ans[i][m - 1] = let[q];
        ans[i + 1][m - 1] = let[q];
        q = (q + 1) % 2;
      }
    }
    q = 0;
    for (int i = 0; i < nn; i += 2) {
      int f = (i % 4 == 0);
      q = 0;
      for (int j = 0; j < mm; j += 2) {
        if (k > 0) {
          ans[i][j] = l[f][q];
          ans[i][j + 1] = l[f][q];
          q = (q + 1) % 4;
          ans[i + 1][j] = l[f][q];
          ans[i + 1][j + 1] = l[f][q];
          q = (q + 1) % 4;
          k -= 2;
        } else {
          ans[i][j] = l[f][q];
          ans[i + 1][j] = l[f][q];
          q = (q + 1) % 4;
          ans[i][j + 1] = l[f][q];
          ans[i + 1][j + 1] = l[f][q];
          q = (q + 1) % 4;
        }
      }
    }
    cout << "YES" << endl;
    for (int i = int(0); i < int(n); i++) {
      for (int j = int(0); j < int(m); j++) cout << ans[i][j];
      cout << endl;
    }
  }
}
