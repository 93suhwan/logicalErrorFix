#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e14;
struct T {
  long long lf;
  long long ri;
  long long off;
};
signed main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a) cin >> i;
    vector<T> ans;
    for (long long i = n - 1; i > 0; i--) {
      long long mx = LLONG_MIN;
      long long idx = -1;
      for (long long j = 0; j <= i; j++) {
        if (mx < a[j]) {
          mx = a[j];
          idx = j;
        }
      }
      if (idx != i) {
        vector<long long> t2(n);
        for (long long j = 0; j <= i; j++) {
          t2[j] = a[(j + idx + 1) % (i + 1)];
        }
        a = t2;
        ans.push_back({1, i + 1, idx + 1});
      }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x.lf << ' ' << x.ri << ' ' << x.off << '\n';
    }
  }
}
