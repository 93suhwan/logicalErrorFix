#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int k = n / 2;
  int rem = n - (2 * k - 1);
  string ans = "";
  for (int i = 0; i < k; i++) {
    ans.push_back('a');
  }
  for (int i = 0; i < rem; i++) ans.push_back('b' + i);
  for (int i = 0; i < k - 1; i++) ans.push_back('a');
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
