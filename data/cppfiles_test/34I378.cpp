#include <bits/stdc++.h>
using namespace std;
void play() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long ans = -1000000000000000000;
  for (long long i = 1; i <= n; i++) {
    long long yy = n - 300;
    long long yg = 1;
    long long jj = max(yg, yy);
    for (long long j = jj + i; j <= n; j++) {
      long long aa = (i * j) - ((k) * (arr[i - 1] | arr[j - 1]));
      ans = max(aa, ans);
    }
  }
  cout << ans << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    play();
  }
  return 0;
}
