#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
void solve() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  int i = 0, j = 0, a = 0, b = 0;
  for (i = 0, j = 0; i < s.size() && j < t.size(); ++i) {
    if (s[i] == t[j]) {
      j++;
    }
  }
  if (j != t.size()) {
    cout << s << endl;
    return;
  }
  for (i = 0; i < s.size(); ++i) {
    if (s[i] == t[1]) {
      a = i;
      break;
    }
  }
  for (i = s.size() - 1; i >= 0; --i) {
    if (s[i] == t[2]) {
      b = i;
      break;
    }
  }
  swap(s[a], s[b]);
  cout << s << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
