#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int Q;
  cin >> Q;
  while (Q-- > 0) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int l = *max_element(a.begin(), a.end()), r = l << 1, res = r;
    while (l <= r) {
      int m = l + r >> 1;
      bitset<2001> dp, aux;
      for (int i = 0; i <= m; ++i) aux[i] = 1;
      dp = aux;
      for (int i = 0; i < n; ++i) {
        dp = (dp << a[i]) | (dp >> a[i]);
        dp &= aux;
      }
      if (dp.count()) {
        res = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
