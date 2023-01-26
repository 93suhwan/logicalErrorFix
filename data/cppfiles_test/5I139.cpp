#include <bits/stdc++.h>
using namespace std;
int t;
int n;
char c[2][200005];
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; cas++) {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> c[0][i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> c[1][i];
    }
    for (int i = 1; i <= n; i++) {
      if (c[1][i] == '1') {
        if (c[0][i] == '0') {
          ans++;
        } else if (c[0][i - 1] == '1') {
          ans++;
          c[0][i - 1] = '0';
        } else if (c[0][i + 1] == '1') {
          ans++;
          c[0][i + 1] = '0';
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
