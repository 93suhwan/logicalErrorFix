#include <bits/stdc++.h>
using namespace std;
void solve() {
  string n, s;
  cin >> n >> s;
  vector<int> a;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < n.size(); ++j) {
      if (s[i] == n[j]) {
        a.push_back(j);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < a.size() - 1; ++i) {
    ans += abs(a[i] - a[i + 1]);
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
