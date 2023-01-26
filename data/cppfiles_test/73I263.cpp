#include <bits/stdc++.h>
using namespace std;
void swap(long long &a, long long &b) {
  long long p = a;
  a = b;
  b = p;
}
void soln() {
  long long n;
  cin >> n;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  bool change = false;
  long long ans = 0;
  for (long long k = 0; k < n; k++) {
    for (long long i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) {
        ans++;
        long long v;
        if (i % 2 == 0)
          v = 2;
        else
          v = 1;
        for (long long j = v; j < n; j += 2) {
          if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
        break;
      }
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) soln();
}
