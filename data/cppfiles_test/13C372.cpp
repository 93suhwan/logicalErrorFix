#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  map<char, int> cnt;
  for (auto i : s) {
    cnt[i] += 1;
  }
  if (cnt['B'] == cnt['A'] + cnt['C']) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
