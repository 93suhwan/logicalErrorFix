#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;
const long long M = 1e18 + 7;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<long long> v(n);
  int mn = 32;
  vector<int> d(n);
  int f = 0;
  for (long long i = 1; i < (n); ++i) {
    if (v[i] != v[i - 1]) {
      f = 1;
      break;
    }
  }
  if (f == 0) {
    cout << v[0] << endl;
    return;
  }
  for (long long i = 0; i < (n); ++i) {
    cin >> v[i];
    for (long long j = 0; j < (31); ++j) {
      if (((1ll << j) & v[i]) == 0) {
        d[i] = j;
        mn = min(mn, d[i]);
        break;
      }
    }
  }
  cout << ((1 << mn) - 1) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
