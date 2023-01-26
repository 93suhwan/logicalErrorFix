#include <bits/stdc++.h>
using namespace std;
int n, M;
char s[105][105];
void H(int x, int y) { s[x][y] = (x + y / 2) % 2 == 0 ? 'a' : 'b'; }
void V(int x, int y) { s[x][y] = (x / 2 + y) % 2 == 0 ? 'c' : 'd'; }
char vv(int x, int y) { return (x / 2 + y) % 2 == 0 ? 'c' : 'd'; }
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int tc, m, k;
  cin >> tc;
  while (tc--) {
    cin >> n >> m >> k;
    M = m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) V(i, j);
    if (n % 2) {
      k -= m / 2;
      if (k < 0 || k % 2)
        cout << "NO" << endl;
      else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++) s[i][j] = vv(i - 1, j);
        for (int i = 0; i < m; i++) {
          H(0, i);
        }
        for (int i = 1; i < n && k > 0; i += 2) {
          for (int j = 0; j < m && k > 0; j += 2) {
            k -= 2;
            H(i, j);
            H(i + 1, j);
            H(i + 1, j + 1);
            H(i, j + 1);
          }
        }
      }
      continue;
    } else if (m % 2) {
      m--;
    }
    if (n * m / 2 < k || k % 2)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (int i = 0; i < n && k > 0; i += 2) {
        for (int j = 0; j < m && k > 0; j += 2) {
          k -= 2;
          H(i, j);
          H(i + 1, j);
          H(i + 1, j + 1);
          H(i, j + 1);
        }
      }
    }
  }
  return 0;
}
