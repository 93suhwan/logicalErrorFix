#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long arr[100005], dp1[100005], dp2[100005];
vector<long long> vec1, vec2;
long long ceil(long long a, long long b) { return (a + b - 1) / b; }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, solve = 0, x;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    for (auto i : vec2) dp2[i] = 0;
    vec2.clear(), dp2[arr[n]] = 1, vec2.push_back(arr[n]);
    for (long long i = n - 1; i >= 1; i--) {
      dp1[arr[i]] = 1, vec1.push_back(arr[i]);
      for (auto j : vec2) {
        x = arr[i] / ceil(arr[i], j);
        if (!dp1[x]) vec1.push_back(x);
        dp1[x] += dp2[j],
            solve = (solve + (i * dp2[j] % mod * (ceil(arr[i], j) - 1) % mod)) %
                    mod;
      }
      for (auto j : vec2) dp2[j] = 0;
      vec2.clear(), vec2 = vec1;
      for (auto j : vec2) dp2[j] = dp1[j], dp1[j] = 0;
      vec1.clear();
    }
    cout << solve << "\n";
  }
  return 0;
}
