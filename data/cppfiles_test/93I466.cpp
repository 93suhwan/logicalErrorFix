#include <bits/stdc++.h>
using namespace std;
long long p2(long long n) {
  long long res = 1;
  for (long long i = 0; i < 8 * sizeof(long long); i++) {
    long long curr = 1 << i;
    if (curr > n) break;
    res = curr;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t, n, k, ans = 0, num;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    num = p2(k);
    if (num >= n) {
      cout << log2(num);
    } else if (num * 2 >= n) {
      cout << log2(num) + 1;
    } else {
      ans = log2(num) + 1;
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
