#include <bits/stdc++.h>
using namespace std;
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n + 1), pf(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++) {
    pf[i] = pf[i - 1] + v[i];
  }
  long long ans = (long long)1e18;
  for (long long B = 0; B < n; B++) {
    long long A = ceil_div((B * v[1] - k + pf[n - B]), (B + 1));
    ans = min(ans, B + max(A, 0ll));
  }
  cout << ans << "\n";
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
