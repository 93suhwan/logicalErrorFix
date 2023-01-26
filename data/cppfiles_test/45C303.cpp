#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t;
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) solve();
  return 0;
}
void solve() {
  int k = 1, n = 0;
  cin >> n;
  bool cur = true, pre = false, flag = true;
  for (int i = 0; i < n; i++) {
    cin >> cur;
    if (flag) {
      if (cur) {
        if (!pre) {
          k++;
        } else
          k += 5;
      } else {
        if (!pre && i != 0) {
          cout << -1 << endl;
          flag = false;
        }
      }
    }
    pre = cur;
  }
  if (flag) cout << k << endl;
}
