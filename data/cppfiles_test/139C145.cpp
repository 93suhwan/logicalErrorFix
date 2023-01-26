#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l = s.length();
    if (l % 2 != 0) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < l / 2; i++) {
      if (s[i] != s[i + l / 2]) {
        cout << "NO\n";
        break;
      } else if (i == l / 2 - 1)
        cout << "YES\n";
    }
  }
  return 0;
}
