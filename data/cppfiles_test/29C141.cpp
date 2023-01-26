#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
void solve() {
  long long n;
  cin >> n;
  long long ones = 0;
  long long zeros = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    ones += (x == 1);
    zeros += (x == 0);
  }
  long long ans = ones;
  for (long long i = 0; i < zeros; i++) {
    ans = ans * 2;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  auto end = chrono::high_resolution_clock::now();
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9;
  cerr << fixed << time_taken << setprecision(9) << " sec" << endl;
  return 0;
}
