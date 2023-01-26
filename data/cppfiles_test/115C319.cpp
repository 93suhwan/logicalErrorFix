#include <bits/stdc++.h>
using namespace std;
long long binMultiply(long long a, long long b) {
  long long ans = 0;
  while (b) {
    if (b & 1) {
      ans = (ans + a) % 1000000007;
    }
    a = (a + a) % 1000000007;
    b >>= 1;
  }
  return ans;
}
long long binExIter(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = binMultiply(ans, a);
    }
    a = binMultiply(a, a);
    b >>= 1;
  }
  return ans;
}
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long lo = 1;
  long long hi = h;
  long long k = h;
  while (lo <= hi) {
    long long mid = lo + (hi - lo) / 2;
    long long attack = 0;
    for (long long i = 0; i < n; i++) {
      long long current = mid;
      if (i < n - 1) {
        long long d = v[i + 1] - v[i];
        if (d < mid) {
          current = d;
        }
      }
      attack += current;
    }
    if (attack >= h) {
      k = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << k << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
