#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<int, int>> lr(n);
    for (int i = 0; i < n; ++i) {
      cin >> lr[i].first >> lr[i].second;
    }
    for (int i = 0; i < n; ++i) {
      long long res = lr[i].first;
      for (int j = 0; j < n; ++j) {
        if (lr[i].first == lr[j].first && lr[i].second > lr[j].second) {
          res = max(res, lr[j].second + 1ll);
        }
      }
      cout << lr[i].first << ' ' << lr[i].second << ' ' << res << endl;
    }
    cout << endl;
  }
  return 0;
}
