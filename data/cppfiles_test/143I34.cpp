#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> freq(n + 1);
    for (auto x : a) freq[x]++;
    set<int> rem;
    vector<int> extras;
    int sum = 0;
    bool skip = false;
    for (int i = 0; i <= n; i++) {
      if (skip) {
        cout << -1 << " ";
        continue;
      }
      int ans = sum + freq[i];
      if (rem.size()) ans = -1;
      if (ans == -1) skip = true;
      cout << ans << " ";
      if (!freq[i]) {
        rem.insert(i);
      } else {
        while (freq[i] > 1) {
          extras.push_back(i);
          freq[i]--;
        }
      }
      while (rem.size() && extras.size()) {
        int x = *rem.rbegin();
        rem.erase(x);
        int y = extras.back();
        extras.pop_back();
        sum += x - y;
      }
    }
    cout << "\n";
  }
  return 0;
}
