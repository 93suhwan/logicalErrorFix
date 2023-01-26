#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, m, k;
bool inv = 0;
char mp[110][110];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    inv = 0;
    if (n % 2 == 1) {
      swap(n, m);
      k = m * n / 2 - k;
      inv = 1;
    }
    int max = m / 2 * n;
    if (k % 2 == 0 && k <= max)
      cout << "YES" << endl;
    else {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 1; i <= n; i += 2) {
      for (int j = 1; j <= m; j++) {
        mp[i][j] = (j + i * 8) % 26 + 'a';
        mp[i + 1][j] = (j + i * 8) % 26 + 'a';
      }
    }
    for (int i = 1; i <= n; i += 2) {
      for (int j = 1; j + 1 <= m; j += 2) {
        if (k) {
          swap(mp[i][j + 1], mp[i + 1][j]);
          k -= 2;
        }
      }
    }
    if (inv == 0) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) putchar(mp[i][j]);
        putchar('\n');
      }
    } else {
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) putchar(mp[j][i]);
        putchar('\n');
      }
    }
  }
  return 0;
}
