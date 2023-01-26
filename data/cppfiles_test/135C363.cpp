#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
long long mod = 1000000007;
void solve() {
  long long n;
  cin >> n;
  ;
  long long k;
  cin >> k;
  ;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    v.push_back(a);
  };
  long long s = 0;
  sort((v).begin(), (v).end());
  for (long long i = 0; i < (n - (2 * k)); i++) {
    s += v[i];
  }
  for (long long i = (n - (2 * k)); i < n - k; i++) {
    s += (v[i] / v[i + k]);
  }
  {
    cout << (s) << '\n';
    return;
  };
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long _t = 1;
  cin >> _t;
  long long _h = _t;
  while (_t--) {
    solve();
  }
}
