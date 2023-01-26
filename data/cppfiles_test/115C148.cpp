#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long lnf = 0x3f3f3f3f3f3f3f3f;
int main(void) {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long h;
    cin >> n >> h;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    long long l = 1;
    long long r = h;
    long long ans = -1;
    while (l <= r) {
      long long m = (l + r) / 2;
      long long d = m;
      for (int i = 2; i <= n; i++) {
        if (arr[i - 1] + m - 1 >= arr[i]) {
          d += arr[i] + m - 1 - (arr[i - 1] + m - 1);
        } else {
          d += m;
        }
      }
      if (d >= h) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
