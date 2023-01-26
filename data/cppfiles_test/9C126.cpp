#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using LL = __int128;
int n, m, k;
int a[1000][1000];
void solve() {
  cin >> n >> m >> k;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> a[r][c];
    }
  }
  for (int t = 0; t < k; t++) {
    int c;
    cin >> c;
    c--;
    int r = 0;
    while (1) {
      if (a[r][c] == 1) {
        a[r][c] = 2;
        c++;
      } else if (a[r][c] == 3) {
        a[r][c] = 2;
        c--;
      } else {
        r++;
      }
      if (r == n) {
        cout << c + 1 << " ";
        break;
      }
    }
  }
  cout << endl;
}
int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
