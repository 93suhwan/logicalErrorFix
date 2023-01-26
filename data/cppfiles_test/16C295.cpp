#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string s2 = s;
  sort(s.begin(), s.end());
  int ct = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != s2[i]) ct++;
  }
  cout << ct << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
