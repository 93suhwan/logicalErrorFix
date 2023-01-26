#include <bits/stdc++.h>
using namespace std;
const int maxint = 20;
vector<string> powsof2;
int N;
int subans(string s, string t) {
  int tp = 0, sp = 0, taken = 0;
  while (sp < s.size() && tp < t.size()) {
    if (s[sp] == t[tp]) {
      taken++;
      tp++;
    }
    sp++;
  }
  return s.size() + t.size() - 2 * taken;
}
void solve() {
  int themin = maxint;
  string meh;
  cin >> meh;
  for (auto u : powsof2) {
    themin = min(subans(meh, u), themin);
  }
  cout << themin << "\n";
}
int main() {
  int t;
  cin >> t;
  long long curr = 1;
  while (curr <= (long long)1e18) {
    powsof2.push_back(to_string(curr));
    curr *= 2;
  }
  while (t--) solve();
}
