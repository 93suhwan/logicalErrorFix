#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, S_INF = 1e7;
void solve() {
  int n, k;
  cin >> n >> k;
  int x;
  vector<long long int> neg, pos;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x < 0)
      neg.push_back(-1 * x);
    else
      pos.push_back(x);
  }
  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end());
  long long int ans = 0LL;
  for (int i = (int)pos.size() - 1; i >= 0; i -= k) {
    ans += pos[i] * 2;
  }
  for (int i = (int)neg.size() - 1; i >= 0; i -= k) {
    ans += neg[i] * 2;
  }
  if (pos.empty()) pos.push_back(0);
  if (neg.empty()) neg.push_back(0);
  ans -= max(pos.back(), neg.back());
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
