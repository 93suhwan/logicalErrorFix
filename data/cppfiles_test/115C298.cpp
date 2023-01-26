#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n, h;
    cin >> n >> h;
    vector<long long> v;
    for (long long j = 0; j < n; j++) {
      long long c;
      cin >> c;
      v.push_back(c);
    }
    long long l = 1, r = 1e18, m, sum, ans;
    while (l <= r) {
      m = (l + r) / 2;
      sum = m;
      for (long long p = 0; p < n - 1; p++) {
        sum = sum + (min(m, v[p + 1] - v[p]));
      }
      if (sum < h) {
        l = m + 1;
        continue;
      } else {
        r = m - 1;
      }
    }
    cout << r + 1 << '\n';
  }
}
