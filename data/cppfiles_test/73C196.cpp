#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, a[N];
bool check() {
  for (int i = 1; i <= n; i++)
    if (a[i] != i) return false;
  return true;
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int k = 0;; k++) {
      if (check()) {
        ans = k;
        break;
      }
      if (k & 1) {
        for (int i = 2; i + 1 <= n; i += 2)
          if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
      } else
        for (int i = 1; i + 1 <= n; i += 2)
          if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
