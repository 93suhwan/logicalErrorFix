#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n, k;
  cin >> n >> k;
  if (n == 1) return 0;
  if (k == 1) return n - 1;
  long long x = 2;
  long long ans = 1;
  while (x < k) {
    x *= 2;
    ans++;
  }
  if (n - x >= 1) {
    long long c = 0;
    long long j = ((n - x) / k);
    if ((n - x) % k != 0) c = 1;
    return (j + c + ans);
  }
  return ans;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
}
