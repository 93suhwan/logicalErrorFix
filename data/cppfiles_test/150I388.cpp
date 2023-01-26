#include <bits/stdc++.h>
using namespace std;
vector<long long> dp(1 << 12, INT_MAX);
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long& x : a) {
    cin >> x;
  }
  long long mx = *max_element(a.begin(), a.end());
  long long mask = 0;
  for (long long x : a) {
    mask |= (1 << (x % 12));
  }
  cout << dp[mask] + mx / 12 * 4 - 1 << '\n';
}
void prebuild() {
  for (long long i = 0; i <= 6; ++i) {
    for (long long j = 0; j <= 6; ++j) {
      for (long long k = 0; k <= 4; ++k) {
        vector<long long> v;
        for (long long o = 0; o < i; ++o) v.push_back(1);
        for (long long o = 0; o < j; ++o) v.push_back(2);
        for (long long o = 0; o < k; ++o) v.push_back(3);
        assert(v.size() == i + j + k);
        long long cmask = 0;
        do {
          long long sum = 0;
          for (long long x : v) {
            if (sum < 12)
              cmask |= (1 << sum);
            else
              break;
            sum += x;
          }
        } while (next_permutation(v.begin(), v.end()));
        for (long long mask = 0; mask < (1 << 12); ++mask) {
          if ((cmask & mask) == mask) {
            dp[mask] = min(dp[mask], i + j + k);
          }
        }
      }
    }
  }
}
int main() {
  prebuild();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
