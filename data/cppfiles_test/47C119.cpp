#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> po, ne;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a > 0) {
        po.push_back(a);
      } else {
        ne.push_back(a);
      }
    }
    sort(po.begin(), po.end(), greater<int>());
    sort(ne.begin(), ne.end());
    long long ans = 0;
    int i = 0;
    for (; i < po.size(); i += k) {
      ans += 2 * po[i];
    }
    int aa, bb;
    i = 0;
    for (; i < ne.size(); i += k) {
      ans -= 2 * ne[i];
    }
    if (po.empty()) {
      if (!ne.empty()) {
        ans += ne[0];
      }
    } else if (ne.empty()) {
      ans -= po[0];
    } else {
      ans -= max(po[0], -ne[0]);
    }
    cout << ans << "\n";
  }
  return 0;
}
