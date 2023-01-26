#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int m, n;
    cin >> m >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b.begin(), b.end());
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int val = a[i], ind;
      auto it = find(b.begin(), b.end(), a[i]);
      ind = it - b.begin();
      for (int j = 0; j < n; j++) {
        if (j == ind) {
          v[j] = val;
          break;
        } else if (v[j] != 0)
          ans++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
