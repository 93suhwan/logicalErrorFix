#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, unsigned long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) {
      res = res * x;
    }
    y = y >> 1;
    x = x * x;
  }
  return res;
}
long long int powermod(long long int x, unsigned long long int y,
                       long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T;
  cin >> T;
  while (T--) {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> v, f(n + 1), diff[n + 1];
    v.push_back(0);
    for (long long int i = (long long int)(0); i < (long long int)(n); i++) {
      long long int t;
      cin >> t;
      v.push_back(t);
      f[t] = i + 1;
    }
    for (long long int i = (long long int)(1); i < (long long int)(n + 1);
         i++) {
      long long int val = v[i];
      if (i >= v[i]) {
        diff[i - v[i]].push_back(v[i]);
      } else {
        long long int d = (n - v[i]);
        d += i;
        diff[d].push_back(v[i]);
      }
    }
    vector<long long int> ans;
    for (long long int i = (long long int)(0); i < (long long int)(n); i++) {
      long long int val = diff[i].size();
      long long int rem = (n - val);
      if (rem <= 2 * m) ans.push_back(i);
    }
    cout << ans.size() << " ";
    for (const auto itr : ans) {
      cout << itr << ' ';
    }
    cout << "\n";
    ;
  }
  return 0;
}
