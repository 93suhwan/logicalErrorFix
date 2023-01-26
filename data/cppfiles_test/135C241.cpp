#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int64_t test;
  cin >> test;
  while (test--) {
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for (int64_t r = 0; r < n; r++) {
      cin >> a[r];
    }
    sort(a.begin(), a.end());
    int64_t sum = 0;
    for (int64_t r = 0; r < (n - 2 * k); r++) {
      sum += a[r];
    }
    map<int64_t, int64_t> s;
    int64_t summ = 0, maxn = 0;
    for (int64_t r = 0; r < k; r++) {
      s[a[n - 2 * k + r]]++;
      s[a[n - r - 1]]++;
      maxn = max(maxn, max(s[a[n - 2 * k + r]], s[a[n - r - 1]]));
      summ += 2;
    }
    summ -= maxn;
    sum += max(int64_t(0), (maxn - summ) / 2);
    cout << sum << '\n';
  }
}
