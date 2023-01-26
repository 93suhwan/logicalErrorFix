#include <bits/stdc++.h>
using namespace std;
const long double scale = 1e+6;
const long long mod = 1000000007;
int ispower(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
const long long N = 100001;
using namespace std;
long long t;
cin >> t;
while (t--) {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort((a).begin(), (a).end());
  long long m = a[n - 1] / 3, ans = INT_MAX;
  for (long long i = 0; i <= 1; i++) {
    for (long long j = 0; j <= 2; j++) {
      for (long long k = max(1ll * 0, m - 4); k <= m; k++) {
        long long t = i + j + k, c = 0;
        long long f = 0;
        for (auto it : a) {
          long long flag = 0;
          for (long long x = 0; x <= i; x++)
            for (long long y = 0; y <= j; y++) {
              long long s = it - x - 2 * y;
              if (s >= 0 && s % 3 == 0 && s / 3 <= k) {
                c++;
                flag = 1;
                break;
              }
            }
          if (flag == 0) {
            f = 1;
            break;
          }
        }
        if (f == 0) ans = min(ans, t);
      }
    }
  }
  cout << ans << endl;
}
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(25);
  cerr << fixed << setprecision(10);
  auto start = std::chrono::high_resolution_clock::now();
  solve();
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  return 0;
}
