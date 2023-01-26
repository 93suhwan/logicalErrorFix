#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2) {
      cout << "NO" << endl;
    } else {
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
          count++;
        }
      }
      if (count == n / 2) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
