#include <bits/stdc++.h>
using namespace std;
void testcase() {
  string s;
  cin >> s;
  unordered_set<char> r, g;
  for (auto c : s) {
    if (r.size() == g.size()) {
      if (!r.count(c))
        r.insert(c);
      else if (!g.count(c))
        g.insert(c);
    } else if (r.size() < g.size()) {
      if (!r.count(c))
        r.insert(c);
      else if (!g.count(c))
        g.insert(c);
    } else if (r.size() > g.size()) {
      if (!g.count(c))
        g.insert(c);
      else if (!r.count(c))
        r.insert(c);
    }
  }
  long long ans = (r.size() + g.size()) / 2;
  cout << ans << endl;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) testcase();
}
