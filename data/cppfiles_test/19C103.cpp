#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int A = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      A = max(A, a[i]);
    }
    vector<int> lst_r(2 * A, 2 * A), r(2 * A);
    lst_r[0] = 0;
    for (int i = 0; i < n; i++) {
      fill(r.begin(), r.end(), 2 * A);
      for (int l = 0; l < 2 * A; l++)
        if (lst_r[l] != 2 * A) {
          if (l + a[i] < 2 * A)
            r[l + a[i]] = min(r[l + a[i]], max(lst_r[l] - a[i], 0));
          r[max(l - a[i], 0)] = min(r[max(l - a[i], 0)], lst_r[l] + a[i]);
        }
      lst_r = r;
    }
    int mi = 0 + r[0];
    for (int i = 1; i < 2 * A; i++) {
      mi = min(mi, i + r[i]);
    }
    cout << mi << '\n';
  }
  return 0;
}
