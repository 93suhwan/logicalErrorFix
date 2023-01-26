#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k, a;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> a;
      arr[i] = pow(10, a);
    }
    k++;
    int i = 0;
    long long ans = 0, cnt, dig;
    while (k > 0) {
      cout << k << " : " << ans << "\n";
      if (i < n - 1)
        cnt = min(k, arr[i + 1] / arr[i] - 1);
      else {
        cnt = k;
      }
      ans += long long(cnt * arr[i]);
      k -= cnt;
      i++;
    }
    cout << ans << "\n";
  }
}
