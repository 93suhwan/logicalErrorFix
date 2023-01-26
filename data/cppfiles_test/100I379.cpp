#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long fac(long long ans) {
  if (ans == 1) return 1;
  return ans * fac(ans - 1) % MOD;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    if (v[n - 2] == v[n - 1])
      cout << fac(n) % MOD << "\n";
    else {
      if (v[n - 1] - v[n - 2] >= 2)
        cout << "0\n";
      else {
        long long cnt = 1;
        for (int i = n - 3; i >= 0; i--)
          if (v[i] == v[n - 2]) cnt++;
        long long c = n - cnt;
        cout << fac(n) * c / (c + 1) % MOD << "\n";
      }
    }
  }
  return 0;
}
