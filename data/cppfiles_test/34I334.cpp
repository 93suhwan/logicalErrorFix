#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastio();
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    long long i, j;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n <= 5000) {
      long long ans = INT_MIN;
      for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
          ans = max(ans, i * j - k * (a[i - 1] | a[j - 1]));
        }
      }
      cout << ans << "\n";
    } else {
      long long ans = INT_MIN;
      for (i = n; i >= 2; i--) {
        ans = max(ans, i * (i - 1) - k * (a[i - 2] | a[i - 1]));
      }
      cout << ans << "\n";
    }
  }
}
