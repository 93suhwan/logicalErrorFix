#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    vector<int> z[10];
    string s;
    cin >> s;
    for (int i = 0; i < k; i++) {
      z[s[i] - '0'].push_back(i);
    }
    int ans = 1;
    if (z[2].size() + z[3].size() + z[5].size() + z[7].size() == k) ans++;
    cout << ans << "\n";
    if (ans == 1) {
      for (int i = 1; i < 10; i++) {
        if (i != 2 && i != 3 && i != 5 && i != 7 && !z[i].empty()) {
          cout << i << "\n";
          break;
        }
      }
    } else {
      for (int i = 11; i < 100; i++) {
        int d = 0;
        for (int j = 2; j < i; j++) {
          if (i % j == 0) {
            d++;
            break;
          }
        }
        if (d) {
          int d1 = i % 10;
          int d2 = i / 10;
          if (!z[d1].empty() && !z[d2].empty() && z[d1].back() > z[d2][0]) {
            cout << i << "\n";
            break;
          }
        }
      }
    }
  }
  return 0;
}
