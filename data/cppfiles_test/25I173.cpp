#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s, k;
    cin >> s >> k;
    string a, b;
    int pt;
    bool f = 0;
    bool h = 0;
    for (int i = 0; i < s.size(); i++) {
      if (k[0] == s[i]) {
        pt = i;
        f = 1;
        break;
      }
    }
    if (f == 0) {
      cout << "NO\n";
      continue;
    }
    f = 0;
    for (int i = 1; i < k.size(); i++) {
      if (k[i] == s[pt + 1] && f == 0) {
        pt++;
        continue;
      } else if (k[i] == s[pt - 1]) {
        pt--;
        f = 1;
      } else {
        cout << "NO\n";
        h = 1;
        break;
      }
    }
    if (h == 0) {
      cout << "YES\n";
    }
  }
}
