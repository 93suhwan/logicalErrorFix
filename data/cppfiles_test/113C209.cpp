#include <bits/stdc++.h>
using namespace std;
bool sum_bits(int x, int y, int k) {
  int cnt = 0;
  int q = x | y;
  while (q) {
    if ((x & 1) != (y & 1)) {
      cnt += 1;
    }
    x = x >> 1;
    y = y >> 1;
    q = q >> 1;
  }
  if (cnt > k) {
    return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    long long a, b, c, m, n;
    cin >> n;
    long long arr[n];
    long long sm = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sm += arr[i];
    }
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
      long long x, y;
      cin >> x >> y;
      long long ans = 0;
      auto it = lower_bound(arr, arr + n, x);
      if (it == arr + n) {
        sm -= arr[n - 1];
        ans += (x - arr[n - 1]);
        if (sm < y) {
          ans += (y - sm);
        }
        cout << ans << endl;
        sm += arr[n - 1];
      } else {
        sm -= *(it);
        if (sm < y) {
          ans += (y - sm);
        }
        sm += *(it);
        long long ans2 = 0;
        if (it != arr) {
          sm -= *(it - 1);
          ans2 += (x - *(it - 1));
          if (sm < y) {
            ans2 += (y - sm);
          }
          ans = min(ans, ans2);
          sm += *(it - 1);
        }
        cout << ans << endl;
      }
    }
  }
}
