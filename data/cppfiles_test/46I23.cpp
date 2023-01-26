#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      mp[a[i]] = -1;
    }
    vector<int> b = a;
    sort(b.rbegin(), b.rend());
    int ans = 1e9 + 7;
    for (int i = 0; i < n; ++i) {
      if (mp[b[i]] == -1) {
        mp[b[i]] = i;
      }
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      ans = min(ans, i + mp[a[i]]);
    }
    cout << ans << "\n";
  }
  return 0;
}
