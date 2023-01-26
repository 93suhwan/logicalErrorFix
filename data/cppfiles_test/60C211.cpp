#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, s = 0;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> make_pair;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      make_pair[a[i]]++;
      s += a[i];
    }
    if ((2 * s) % n) {
      cout << 0 << endl;
      continue;
    } else {
      long long ans = 0;
      long long val = (2 * s) / n;
      sort(a.begin(), a.end());
      for (long long i = 0; i < n; i++) {
        if (binary_search(a.begin(), a.end(), val - a[i]))
          ans += make_pair[val - a[i]];
        if (2 * a[i] == val) {
          ans--;
        }
      }
      cout << ans / 2 << endl;
    }
  }
  return 0;
}
