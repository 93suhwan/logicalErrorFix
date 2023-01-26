#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, m, k, i, j, cnt;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long> v(n);
    for (i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<long long> b;
    b = v;
    sort(b.begin(), b.end());
    cnt = 1;
    for (i = 1; i < n; i++) {
      auto it = lower_bound(b.begin(), b.end(), v[i]);
      if (*it == v[i - 1] + 1) {
        ;
      } else {
        cnt++;
      }
    }
    if (cnt <= k) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
