#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    char ch[3][n + 5];
    for (int i = 1; i <= 2; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> ch[i][j];
      }
    }
    bool found = true;
    for (int i = 1; i <= n; ++i) {
      if (i == n) continue;
      if (ch[1][i + 1] == ch[2][i + 1] && ch[1][i + 1] == '1') {
        found = false;
        break;
      }
    }
    cout << (found ? "YES" : "NO") << '\n';
  }
}
