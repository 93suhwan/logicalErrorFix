#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const long long biginf = 1e18;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  set<char> set;
  for (char i : s) {
    set.insert(i);
  }
  int m = set.size();
  int ans = min(m, n / 2);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solve();
  }
  return 0;
}
