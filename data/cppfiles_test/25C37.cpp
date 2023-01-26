#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    bool ok = 0;
    for (int i = 0; i < s.size(); i++) {
      string a = s.substr(0, i), b = s.substr(0, i + 1);
      reverse(a.begin(), a.end());
      b += a;
      if (b.find(t) != b.npos) {
        ok = 1;
        break;
      }
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
