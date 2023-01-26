#include <bits/stdc++.h>
using namespace std;
void solve() {
  unsigned long long int n;
  cin >> n;
  vector<unsigned long long int> v(n);
  for (unsigned long long int i = 0; i < n; i++) cin >> v[i];
  unsigned long long int a[n], d[n], j = 0;
  for (unsigned long long int i = 0; i < n; i++) {
    unsigned long long int k = min_element(v.begin() + i, v.end()) - v.begin();
    if (k != i) {
      a[j] = i + 1;
      d[j] = k - i;
      j++;
      rotate(v.begin() + i, v.begin() + k, v.end());
    }
  }
  cout << j << "\n";
  for (unsigned long long int i = 0; i < j; i++) {
    cout << a[i] << " " << n << " " << d[i] << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  unsigned long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
