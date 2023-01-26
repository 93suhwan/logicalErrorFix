#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a')
        a++;
      else
        b++;
      if (a == b) ans++;
    }
    if (a == 0 || b == 0) {
      cout << -1 << " " << -1 << "\n";
    } else {
      size_t found = s.find("ab");
      size_t found2 = s.find("ba");
      if (found != string::npos) {
        if (found == 0) {
          cout << found + 1 << " " << found + 2 << "\n";
        } else {
          cout << found << " " << found + 1 << "\n";
        }
      } else if (found2 != string::npos) {
        if (found2 == 0) {
          cout << found2 + 1 << " " << found2 + 2 << "\n";
        } else
          cout << found2 << " " << found2 + 1 << "\n";
      } else
        cout << -1 << " " << -1 << "\n";
    }
  }
  return 0;
}
