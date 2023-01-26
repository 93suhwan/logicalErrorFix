#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<int, int> a;
    int tt;
    for (int i = 0; i < n; i++) {
      cin >> tt;
      a[tt]++;
    }
    cout << a[0] << ' ';
    map<int, int> don;
    int ans = 0;
    int mex;
    for (int i = 0; i <= n + 1; i++) {
      if (a.count(i) == 0) {
        mex = i;
      }
    }
    if (a[0] == 0) {
      ans = -1;
    } else {
      if (a[0] > 1) don[0] = (a[0] - 1);
    }
    int fil = 0;
    for (int i = 1; i <= n; i++) {
      int a2 = 0;
      if (ans == -1) {
        cout << -1 << ' ';
        continue;
      }
      if (i == mex) {
        cout << 0 << ' ';
        continue;
      }
      a2 += a[i];
      a2 += fil;
      cout << a2 << ' ';
      if (a[i] > 1) {
        don[i] = (a[i] - 1);
      } else if (a[i] == 0) {
        if (don.size() > 0) {
          auto it = don.end();
          it--;
          fil += (i - it->first);
          it->second--;
          if (it->second == 0) {
            don.erase(it->first);
          }
        } else {
          ans = -1;
        }
      }
    }
    cout << endl;
  }
}
