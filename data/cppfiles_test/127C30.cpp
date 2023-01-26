#include <bits/stdc++.h>
using namespace std;
void solve() {
  string S, T;
  cin >> S >> T;
  int cnt[26] = {};
  for (char c : S) cnt[c - 'a']++;
  if (T != "abc" || cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)
    sort(S.begin(), S.end());
  else {
    map<char, int> m{{'b', 'c'}, {'c', 'b'}};
    sort(S.begin(), S.end(), [&m](char &a, char &b) {
      int na = (m.count(a) ? m[a] : a);
      int nb = (m.count(b) ? m[b] : b);
      return na < nb;
    });
  }
  cout << S << "\n";
}
void _pre() {}
int main() {
  _pre();
  int _ = 1;
  cin >> _;
  for (int t = 1; t <= _; t++) {
    solve();
  }
  return 0;
}
