#include <bits/stdc++.h>
using namespace std;
int dt[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const long long N = 1e4 + 6;
long long a[N];
bool dp1[N], dp2[N];
long long n;
bool ck(long long x) {
  for (long long i = (0); i <= (x); ++i) dp1[i] = 1;
  for (long long i = (0); i <= (n - 1); ++i) {
    for (long long j = (0); j <= (x); ++j) dp2[j] = dp1[j], dp1[j] = 0;
    for (long long j = (0); j <= (x); ++j) {
      if (dp2[j]) {
        if (j + a[i] <= x) dp1[j + a[i]] = 1;
        if (j - a[i] >= 0) dp1[j - a[i]] = 1;
      }
    }
  }
  for (long long i = (0); i <= (x); ++i)
    if (dp1[i]) return true;
  return false;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (long long i = (0); i <= (n - 1); ++i) cin >> a[i];
    long long l = 0, r = 2000;
    while (l < r) {
      long long mid = l + r >> 1;
      if (ck(mid))
        r = mid;
      else
        l = mid + 1;
    }
    cout << l << endl;
  }
}
