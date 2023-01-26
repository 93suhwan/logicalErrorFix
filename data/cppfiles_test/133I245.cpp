#include <bits/stdc++.h>
using namespace std;
const int N = 7;
int t, n;
string s[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    n -= 2;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    cout << s[0][0];
    for (int i = 0; i < n - 1; ++i) {
      if (s[i][1] != s[i + 1][0]) {
        for (int j = 0; j < n; ++j) {
          if (i + 1 == j) {
            cout << s[j];
            continue;
          }
          cout << s[j][1];
        }
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << s[i][1];
    }
  }
  return 0;
}
