#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long ans = 1;
    long long m = 1;
    for (long long i = 0; i < n - 1; i++) {
      if (arr[i] * arr[i + 1] > ans) ans = arr[i] * arr[i + 1];
    }
    cout << ans << "\n";
  }
  return 0;
}
