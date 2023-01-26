#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    multiset<int> s;
    int ans = 0;
    for (int i = 0; i < m; i++) {
      s.insert(a[i]);
      auto it = s.lower_bound(a[i]);
      ans += distance(s.begin(), it);
    }
    cout << ans << endl;
  }
}
