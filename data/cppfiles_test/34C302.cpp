#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
void runtime() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  for (long long i = 1; i < n + 1; i++) cin >> a[i];
  long long ans = n * (n - 1) - k * (a[n] | a[n - 1]);
  for (long long i = max(1LL, n - 2 * k - 2); i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      ans = max(ans, i * j - k * (a[i] | a[j]));
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    runtime();
    cout << "\n";
  }
  return 0;
}
