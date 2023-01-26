#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  long long a, b, c, m;
  cin >> a >> b >> c >> m;
  vector<long long> v{a, b, c};
  sort((v).begin(), (v).end());
  long long total = a + b + c - 3;
  if (total < m) {
    cout << "NO" << endl;
  } else {
    long long k = v[2] - (v[1] + v[0] + 1);
    if (m >= k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
