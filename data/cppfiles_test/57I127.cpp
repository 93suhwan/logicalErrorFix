#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
  ll s, n, k;
  cin >> s >> n >> k;
  n++;
  ll full = s / (2 * k);
  ll tot = full * k;
  ll rem = s - full * 2 * k + 1;
  tot += min(k, rem);
  cout << (tot >= n ? "NO" : "YES") << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int tests;
  cin >> tests;
  while (tests--) solve();
}
