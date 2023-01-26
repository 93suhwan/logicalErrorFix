#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      if (s1[i + 1] == '1' && s2[i + 1] == '1') {
        ok = true;
        break;
      }
    }
    if (ok)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
