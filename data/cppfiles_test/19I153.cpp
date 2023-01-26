#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int a[20];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      if (a[0] == 0)
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
      continue;
    }
    bool found = 0;
    for (int mask1 = 1; mask1 < (1 << n); mask1++) {
      s.clear();
      for (int i = 0; i < n; i++) s.insert(a[i]);
      int sum1 = 0;
      for (int i = 0; i < n; i++) {
        if ((1 << i) & mask1) {
          sum1 += a[i];
          s.erase(s.find(a[i]));
        }
      }
      for (int mask2 = 1; mask2 < (1 << n); mask2++) {
        if (mask1 & mask2) continue;
        int sum2 = 0;
        for (int i = 0; i < n; i++) {
          if ((1 << i) & mask2) {
            sum2 += a[i];
            s.erase(s.find(a[i]));
          }
        }
        if (s.find(sum1 - sum2) != s.end()) {
          found = 1;
          break;
        }
        for (int i = 0; i < n; i++) {
          if ((1 << i) & mask2) s.insert(a[i]);
        }
      }
      if (found) break;
      for (int mask2 = 0; mask2 < (1 << n); mask2++) {
        if (n == 1) cerr << "mask2" << '=' << mask2 << '\n';
        ;
        if ((mask1 & mask2) != mask2) continue;
        int sum2 = 0;
        for (int i = 0; i < n; i++) {
          if ((1 << i) & mask2) {
            sum2 += a[i];
          }
        }
        if (s.find(sum1 - sum2) != s.end()) {
          found = 1;
          break;
        }
      }
      if (found) break;
    }
    if (found)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
