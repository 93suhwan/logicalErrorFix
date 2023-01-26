#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    long long i = 0;
    while (i < n - 1 && a[i + 1] >= 2 * a[i]) {
      i++;
    }
    if (i == 0) {
      cout << a[0] << '\n';
    } else {
      cout << a[i] - a[i - 1] << '\n';
    }
  }
  return 0;
}
