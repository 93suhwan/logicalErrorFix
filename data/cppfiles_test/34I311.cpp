#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    long long mx = INT_MIN, s;
    cin >> n >> k;
    int a[n];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; ++i) {
      vp.push_back(make_pair(a[i], i));
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < vp.size() - 1; i++) {
      s = (vp[i].second * vp[i + 1].second) -
          k * (vp[i].first | vp[i + 1].first);
      mx = max(mx, s);
    }
    cout << mx << endl;
  }
  return 0;
}
