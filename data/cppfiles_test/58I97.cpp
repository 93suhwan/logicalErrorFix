#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0];
    cin >> s[1];
    bool x = 1;
    for (int i = 0; i < n - 1; i++) {
      if (s[0][i] == '1' && s[0][i + 1] == '1' && s[1][i] == '1' &&
          s[1][i + 1] == '1') {
        x = 0;
      }
    }
    if (x) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
