#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  cin >> t;
  while (t--) {
    bool p = true;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n - 1; i++) {
      if (s1[i] == '1' && s2[i] == '1') {
        p = false;
        break;
      }
    }
    if (p)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
