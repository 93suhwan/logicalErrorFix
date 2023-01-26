#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const long long INF = 2e9, MOD = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long ind = 0; ind < n; ind++) {
      vector<long long> tmp = a;
      tmp.erase(tmp.begin() + ind);
      if (a[ind] == 0) {
        goto l;
      }
      for (long long i = 0; i < (1 << (n - 1)); i++) {
        long long s = 0;
        vector<long long> left;
        for (long long j = 0; j < n - 1; j++) {
          if (i & (1 << j)) {
            s += tmp[j];
          } else {
            left.push_back(tmp[j]);
          }
        }
        long long cur;
        long long num = (long long)left.size();
        for (long long j = 0; j < (1 << num); j++) {
          cur = 0;
          for (long long x = 0; x < num; x++) {
            if (j & (1 << x)) {
              cur += left[x];
              if (abs(cur - s) == abs(a[ind]) || abs(cur + s) == abs(a[ind])) {
                goto l;
              }
            }
          }
        }
      }
    }
    cout << "NO"
         << "\n";
    continue;
  l:
    cout << "YES"
         << "\n";
  }
  return 0;
}
