#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    sum = 2 * sum;
    if (sum % n) {
      cout << 0 << '\n';
      continue;
    }
    sum /= n;
    long long ans = 0;
    unordered_map<long long, long long, custom_hash> mp1;
    for (long long i = 0; i < n; i++) {
      ans += mp1[sum - arr[i]];
      mp1[arr[i]]++;
    }
    cout << ans << '\n';
  }
}
