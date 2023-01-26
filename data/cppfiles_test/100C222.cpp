#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 9;
const long long inf = 0x3f3f3f3f;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[maxn];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long s = 0;
    long long ans = a[0];
    a[n] = a[0] - 1;
    for (long long i = 0; i < n; i++) {
      long long x = a[i] + s;
      s = s - x;
      ans = max(ans, x);
    }
    cout << ans << endl;
  }
}
