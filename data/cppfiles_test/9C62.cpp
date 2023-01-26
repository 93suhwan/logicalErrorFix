#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
void prec() {}
int g[1000][1000];
int f[1000];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      if (g[i][j] == 2) f[j]++;
    }
  while (k--) {
    int y;
    cin >> y;
    --y;
    if (f[y] != n) {
      int x = 0;
      while (x < n) {
        int &v = g[x][y];
        if (g[x][y] == 2)
          x++;
        else {
          f[y]++;
          y += (g[x][y] == 1) ? 1 : -1;
        }
        v = 2;
      }
    }
    cout << (y + 1) << ' ';
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  prec();
  int t = 1;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
