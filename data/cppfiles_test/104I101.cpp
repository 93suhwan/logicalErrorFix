#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  for (; t--;) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    auto oper = [&](int i) {
      int x = 0;
      for (int j = 0; j < 3; j++) x ^= a[i + j];
      for (int j = 0; j < 3; j++) a[i + j] = x;
    };
    vector<int> ans;
    for (int i = 0; i < n - 2;) {
      int cnt = 0;
      for (int j = 0; j < 3; j++) cnt += a[i + j];
      if (cnt & 1) {
        if (cnt == 1 && !a[i]) {
          i++;
        } else {
          if (cnt == 1) {
            oper(i);
            ans.push_back(i + 1);
          }
          i += 2;
        }
      } else {
        i += 3;
      }
    }
    for (int i = n - 3; i >= 0; i--) {
      int cnt = 0;
      for (int j = 0; j < 3; j++) cnt += a[i + j];
      if (cnt == 2) {
        ans.push_back(i + 1);
        oper(i);
      }
    }
    for (int i = 0; i < n - 2; i++) {
      int cnt = 0;
      for (int j = 0; j < 3; j++) cnt += a[i + j];
      if (cnt == 2) {
        ans.push_back(i + 1);
        oper(i);
      }
    }
    bool ok = 1;
    for (int i : a)
      if (i) ok = 0;
    if (ok) {
      cout << "YES\n";
      cout << ans.size() << '\n';
      for (int i : ans) cout << i << ' ';
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
