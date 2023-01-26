#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  vector<long long> k1;
  vector<long long> k2;
  for (long long d = 0; d <= 9; d++) {
    for (long long m = 1; m <= 10; m++) {
      long long z = 0;
      for (long long i = 0; i < m; i++) {
        z = z * 10 + d;
      }
      k1.push_back(z);
    }
  }
  for (long long m = 0; m <= 10; m++) {
    for (long long d1 = 0; d1 <= 9; d1++) {
      for (long long d2 = 0; d2 <= 9; d2++) {
        for (long long mask = 0; mask < (1 << m); mask++) {
          long long z = 0;
          for (long long i = 0; i < m; i++) {
            if (mask & (1 << i))
              z = z * 10 + d1;
            else
              z = z * 10 + d2;
          }
          k2.push_back(z);
        }
      }
    }
  }
  sort(k1.begin(), k1.end());
  sort(k2.begin(), k2.end());
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    if (k == 1)
      cout << *lower_bound(k1.begin(), k1.end(), n) << '\n';
    else
      cout << *lower_bound(k2.begin(), k2.end(), n) << '\n';
  }
  return 0;
}
