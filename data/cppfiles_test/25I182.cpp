#include <bits/stdc++.h>
using namespace std;
string xauchung(string s, string t) {
  int i = 0;
  while (s[i] != t[0])
    if (i < s.size())
      ++i;
    else
      return t;
  while (t[0] == s[i]) {
    ++i;
    t.erase(0, 1);
  }
  return t;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    string s, t, res;
    cin >> s >> t;
    t = xauchung(s, t);
    reverse(t.begin(), t.end());
    s.erase(s.size() - 1, 1);
    t = xauchung(s, t);
    if (t.empty())
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
