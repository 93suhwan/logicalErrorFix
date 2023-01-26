#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
set<string> solve(set<string> ans, int n) {
  set<string> ret;
  for (auto it = ans.begin(); it != ans.end(); it++) {
    for (int j = 0; j < n; j++) {
      string s = *it;
      s.insert(j, "()");
      ret.insert(s);
    }
    if (ret.size() == n) break;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "()" << '\n';
      continue;
    }
    set<string> s;
    s.insert("()");
    for (int i = 2; i <= n; i++) s = solve(s, i);
    for (auto it = s.begin(); it != s.end() && n > 0; it++, n--) {
      cout << *it << '\n';
    }
  }
}
