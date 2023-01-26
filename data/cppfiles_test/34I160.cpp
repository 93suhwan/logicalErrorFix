#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long ans = INT_MIN;
    long long start = max((long long)0, (long long)(n - 200));
    for (int i = start; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        long long newval = ((i + 1) * (j + 1)) - (k * (arr[i] | arr[j]));
        ans = max(ans, newval);
      }
    }
    cout << ans << endl;
  }
}
