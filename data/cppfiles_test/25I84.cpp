#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    string s, t, res;
    cin >> s >> t;
    int i, p;
    for (i = 1; i <= t.size(); ++i) {
      int tmp = s.find(t.substr(0, i));
      if (tmp == -1)
        break;
      else
        p = tmp;
    }
    if (i == 1)
      cout << "NO"
           << "\n";
    else {
      bool kt = true;
      --i;
      t.erase(0, i);
      p += i - 1;
      s.erase(p, 1);
      i = 0;
      while (i < t.size()) {
        --p;
        if (s[p] != t[i]) {
          kt = false;
          break;
        }
        ++i;
      }
      if (kt == 1)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
  return 0;
}
