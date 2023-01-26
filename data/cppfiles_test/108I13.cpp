#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int ma = max_element(a.begin(), a.end()) - a.begin();
    int mb = max_element(b.begin(), b.end()) - b.begin();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      if (b[i] >= b[ma] || a[i] >= a[mb]) {
        ans[i] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
}
