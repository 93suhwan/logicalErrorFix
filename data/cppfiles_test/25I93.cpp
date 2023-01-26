#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    string a, b;
    bool f = 0;
    for (int i = 0; i < t.size(); i++) {
      a = "";
      b = "";
      for (int j = 0; j <= i; j++) {
        a += t[j];
      }
      for (int k = i; k < t.size(); k++) {
        b += t[k];
      }
      reverse(b.begin(), b.end());
      if (s.find(a) != s.npos && s.find(b) != s.npos) {
        f = 1;
        cout << "YES\n";
        break;
      }
    }
    if (f == 0) {
      cout << "NO\n";
    }
  }
}
