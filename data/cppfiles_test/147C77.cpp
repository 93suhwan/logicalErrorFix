#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int ans;
    string s;
    cin >> s;
    int n;
    n = s.length();
    if (s[0] == 'N' && s[n - 1] == 'N') {
      ans = 1;
    } else {
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
          count++;
        }
      }
      if (count == 1) {
        ans = 0;
      } else
        ans = 1;
    }
    if (ans == 0) {
      cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  }
  return 0;
}
