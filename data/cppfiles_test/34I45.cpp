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
  for (long long i = 0; i < n - 1; i++) {
    long long kk = arr[i] | arr[i + 1];
    long long yy = (i + 1) * (i + 2);
    long long aa = yy - (k * kk);
    if (aa > ans) {
      ans = aa;
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
