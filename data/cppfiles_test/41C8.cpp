#include <bits/stdc++.h>
using namespace std;
long long get(long long a, long long b, long long k) {
  long long ans = 1;
  long long st = k;
  while (a / st != b / st) {
    ++ans;
    st *= k;
  }
  return ans;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  long long st = 1;
  while (st < n) {
    ++ans;
    st *= k;
  }
  cout << ans << '\n';
  for (long long i = 0; i < n; ++i)
    for (long long j = i + 1; j < n; ++j) cout << get(i, j, k) << ' ';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
