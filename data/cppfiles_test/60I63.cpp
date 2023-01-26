#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]]++;
      sum += v[i];
    }
    int k = sum / n;
    k *= 2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += mp[k - v[i]];
      if (k - v[i] == v[i]) {
        ans--;
      }
    }
    cout << ans / 2 << endl;
  }
}
