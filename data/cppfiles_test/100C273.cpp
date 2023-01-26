#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9, M = 1e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;
int32_t main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    int mnn = 1e9;
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
      mnn = min(vec[i], mnn);
    }
    if (n == 1) {
      cout << vec[0] << '\n';
      continue;
    }
    int mxxrr = mnn;
    sort(vec.rbegin(), vec.rend());
    for (int i = 1; i <= n; i++) {
      int x = vec[n - i];
      x -= mnn;
      mnn += x;
      mxxrr = max(mxxrr, x);
    }
    cout << mxxrr << '\n';
  }
}
