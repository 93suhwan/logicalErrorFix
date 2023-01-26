#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1, n;
  vector<long long> _all;
  for (long long i = 1; i <= 100000; i++) {
    if (i % 3 && i % 10 != 3) _all.push_back(i);
  }
  cin >> t;
  while (t--) {
    cin >> n;
    cout << _all[n - 1] << '\n';
  }
  return 0;
}
