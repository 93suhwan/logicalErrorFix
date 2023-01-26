#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
long long mod(long long n, long long m = MOD) {
  n %= m;
  if (n < 0) n += m;
  return n;
}
vector<int> ans;
void comp() {
  int i = 0;
  while (ans.size() < 1000) {
    i++;
    if (i % 3 == 0 || i % 10 == 3) continue;
    ans.push_back(i);
  }
}
void solve() {
  int k;
  cin >> k;
  cout << ans[k - 1] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  comp();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
