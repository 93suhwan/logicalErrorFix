#include <bits/stdc++.h>
using namespace std;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 31607;
const long long INF = 2e18;
double getTime() { return clock() / (double)CLOCKS_PER_SEC; }
void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  for (int _ = 0; _ < (2); ++_) {
    int j = 0;
    int cur = _;
    for (int i = 0; i < ((int)s.size()); ++i) {
      if ((cur ^ i) & 1) {
        if (t[j] == s[i]) {
          j++;
          cur ^= 1;
        }
      }
      if (j == (int)t.size()) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tests = 1;
  cin >> tests;
  for (int _ = 0; _ < (tests); ++_) {
    solve();
  }
  return 0;
}
