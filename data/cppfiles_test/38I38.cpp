#include <bits/stdc++.h>
using namespace std;
const long long int M = (int)1e8;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  char grid[n][m];
  vector<int> cnt(m);
  vector<int> pref(m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> grid[i][j];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.') {
        if (i && j) {
          if (grid[i - 1][j] == 'X' && (grid[i][j - 1] == 'X')) {
            cnt[j] = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    pref[i] = cnt[i];
    if (i) pref[i] += pref[i - 1];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (a == b)
      cout << "YES"
           << "\n";
    else {
      int x = pref[b] - pref[a];
      if (x)
        cout << "NO"
             << "\n";
      else
        cout << "YES"
             << "\n";
    }
  }
}
