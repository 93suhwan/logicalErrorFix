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
  long long ans = 0;
  while (!is_sorted(a + 1, a + n + 1)) {
    for (long long i = 1 + ans % 2; i < n; i += 2) {
      if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    }
    ans++;
  }
  cout << ans << "\n";
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) soln();
}
