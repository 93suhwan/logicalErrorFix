#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool reversible(const string &s, int idx) {
  int n = s.length();
  int i = idx - 1, j = idx + 1;
  while (i >= 0 && j < n) {
    if (s[i] != s[j]) return false;
    --i;
    ++j;
  }
  return true;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    int sz = t.length();
    bool ok = false;
    for (int i = 0; i < sz; ++i) {
      if (reversible(t, i)) {
        string x;
        if (i + 1 >= sz - i) {
          x = t.substr(0, i + 1);
        } else {
          x = t.substr(i);
          reverse(x.begin(), x.end());
        }
        if (s.find(x) != string::npos) {
          ok = true;
          break;
        }
      }
    }
    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
