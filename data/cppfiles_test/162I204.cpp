#include <bits/stdc++.h>
#pragma GCC optimization("O3")
using namespace std;
const long long N = 5005;
const long long M = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> a(n), v;
    for (auto &x : a) cin >> x;
    reverse(a.begin(), a.end());
    long long l = 1, r = M, res = 1;
    while (l <= r) {
      long long mid = (l + r) / 2;
      v = a;
      bool ok = true;
      for (long long i = 0; i < n - 2 && ok; i++) {
        if (v[i] < mid) {
          ok = false;
          continue;
        }
        long long gift = min(a[i], 3ll * ((v[i] - mid) / 3));
        v[i + 1] += gift / 3;
        v[i + 2] += 2ll * gift / 3;
      }
      if (v[n - 1] < mid || v[n - 2] < mid) ok = false;
      if (ok)
        res = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    cout << res << '\n';
  }
}
