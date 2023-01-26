#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long a[n], d[n], j = 0;
  for (long long i = 0; i < n; i++) {
    long long k = min_element(v.begin() + i, v.end()) - v.begin();
    if (k != i) {
      a[j] = i + 1;
      d[j] = k - i;
      j++;
      rotate(v.begin() + i, v.begin() + k, v.end());
    }
  }
  cout << j << "\n";
  for (long long i = 0; i < j; i++) {
    cout << a[i] << " " << n << " " << d[i] << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
