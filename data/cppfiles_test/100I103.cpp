#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9, M = 1e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;
int32_t main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, a = 0;
    cin >> n;
    if (n == 1) {
      cin >> n;
      cout << n << '\n';
      continue;
    }
    vector<long long> vec(n);
    for (long long i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    long long mn = 0, mx = vec.back(), nn = 0;
    while (vec[mn] < mx - vec[mn]) {
      mx -= vec[mn];
      nn += vec[mn];
      if (mn >= vec.size() - 1) break;
      mn++;
      vec[mn] -= nn;
    }
    cout << min(vec[mn], mx) << '\n';
  }
}
