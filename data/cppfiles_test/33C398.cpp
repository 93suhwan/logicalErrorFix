#include <bits/stdc++.h>
using namespace std;
static bool compare(long long a, long long b) { return a > b; }
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n, 0);
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  long long ans = LONG_MIN;
  for (long long i = 0; i < n - 1; ++i) {
    ans = max(ans, v[i] * v[i + 1]);
  }
  cout << ans << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
