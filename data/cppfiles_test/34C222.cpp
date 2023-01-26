#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  long long t;
  cin >> t;
  for (long long h = 0; h < t; h++) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = -1e9;
    for (long long i = n - 1; i >= n - min(n, (long long)200); i--) {
      for (long long j = n - 1; j >= n - min(n, (long long)200); j--) {
        if (i != j) {
          ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
