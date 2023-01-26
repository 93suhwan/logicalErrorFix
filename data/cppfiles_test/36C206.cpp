#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, i, x, y, m, p, q, sum, ans, cnt, mx, mn, j, k;
  cin >> t;
  while (t--) {
    sum = 0;
    cnt = 0;
    ans = 0;
    mx = INT_MIN;
    mn = 1e18;
    cin >> n;
    vector<long long int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    for (i = 2; i < sum; i++) {
      if (sum % i == 0) {
        cnt++;
        break;
      }
    }
    if (cnt) {
      cout << n << "\n";
      for (i = 0; i < n; i++) cout << i + 1 << " ";
      cout << "\n";
    } else {
      cout << n - 1 << "\n";
      for (i = 0; i < n; i++) {
        if (a[i] % 2 && cnt == 0) {
          cnt++;
          continue;
        } else
          cout << i + 1 << " ";
      }
      cout << "\n";
    }
  }
}
