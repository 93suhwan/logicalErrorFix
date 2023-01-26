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
    bool p = false;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) {
        cout << i + 1 << " " << i + 2 << endl;
        p = true;
        break;
      }
    }
    if (!p) {
      cout << -1 << " " << -1 << endl;
    }
  }
}
