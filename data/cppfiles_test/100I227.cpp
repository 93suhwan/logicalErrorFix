#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = (int)a.size();
    int ans = a[0];
    for (int i = 1; i < n; i++) ans = max(ans, a[i] - a[i - 1]);
    cout << ans << "\n";
  }
}
