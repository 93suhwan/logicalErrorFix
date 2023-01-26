#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, m, k, i, j, cnt;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long a[n];
    long long b[n];
    long long low, high;
    cnt = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    for (i = 0; i < n - 1; i++) {
      cnt++;
      bool ok = 0;
      high = upper_bound(b, b + n, a[i]) - b;
      while (high < n and i < n - 1 and a[i + 1] == b[high]) {
        i++;
        high++;
      }
    }
    if (n >= 2) {
      high = upper_bound(b, b + n, a[n - 2]) - b;
      if (a[n - 1] != b[high]) {
        ++cnt;
      }
    }
    if (cnt <= k) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
