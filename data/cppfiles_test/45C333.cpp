#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
    }
    int len = 1;
    bool alive = true;
    for (int i = 0; i < n && alive; i++) {
      if (i == 0) {
        if (a[i] == 1)
          len++;
        else
          continue;
      } else if (a[i] == 1) {
        if (a[i - 1] == 1)
          len += 5;
        else
          len++;
      } else {
        if (a[i - 1] == 0) {
          alive = false;
          break;
        }
      }
    }
    cout << (alive ? len : -1) << '\n';
  }
}
