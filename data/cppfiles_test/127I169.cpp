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
  for (i = 0, j = s.size() - 1; i < s.size() && j >= 0; ++i, --j) {
    if (s[i] == t[1]) {
      for (j = s.size() - 1; j >= 0; --j) {
        if (s[j] == t[2]) {
          swap(s[i], s[j]);
        }
      }
    }
  }
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
