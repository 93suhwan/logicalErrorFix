#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t, n, k, ans = 0, num;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long num = 1, l = -1, l2 = -1;
    if (n == 1) {
      cout << 0 << '\n';
    }
    for (long long i = 0; i < 8 * sizeof(long long); i++) {
      long long curr = 1 << i;
      if (curr > k) break;
      l++;
      num = curr;
    }
    for (long long i = 0; i < 8 * sizeof(long long); i++) {
      long long curr = 1 << i;
      if (curr > n) break;
      l2++;
    }
    if (num >= n) {
      cout << l2;
    } else if (num * 2 >= n) {
      cout << l2 + 1;
    } else {
      ans = l + 1;
      n -= 2 * num;
      if (n % k == 0) {
        ans += n / k;
      } else {
        ans += n / k + 1;
      }
      cout << ans;
    }
    cout << '\n';
  }
}
