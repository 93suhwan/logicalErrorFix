#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string ans = "";
    int n;
    cin >> n;
    bool added = false;
    for (int i = 0; i < n - 2; i++) {
      string b;
      cin >> b;
      if (i == 0) {
        ans += b;
      } else {
        if (ans.back() == b[0]) {
          ans += b[1];
        } else {
          added = true;
          ans += b;
        }
      }
    }
    if (!added) {
      ans += "a";
    }
    cout << ans << "\n";
  }
}
