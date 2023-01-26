#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, i;
    cin >> n;
    string s;
    bool b = false;
    cin >> s;
    if (n == 1) {
      cout << "-1 -1";
    } else {
      for (i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
          cout << i + 1 << " " << i + 2;
          b = true;
          break;
        }
      }
    }
    if (!b) cout << "-1 -1";
    cout << "\n";
  }
  return 0;
}
