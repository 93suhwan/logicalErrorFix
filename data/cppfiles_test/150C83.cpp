#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int mx = 0;
    vector<int> a(n, 0);
    bool o = false, tw = false;
    bool one = false, minus_one = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(a[i], mx);
      if (a[i] % 3 == 1) {
        o = true;
        if (a[i] == 1) {
          one = true;
        }
      } else if (a[i] % 3 == 2) {
        tw = true;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == mx - 1) {
        minus_one = true;
      }
    }
    if (mx % 3 == 0) {
      cout << mx / 3 + (o || tw) << '\n';
    } else if (mx % 3 == 1) {
      cout << mx / 3 + 1 + (tw && (one || minus_one)) << '\n';
    } else {
      cout << mx / 3 + 1 + o << '\n';
    }
  }
  return 0;
}
