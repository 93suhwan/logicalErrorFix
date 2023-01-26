#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int lena = 0, lenb = 0;
    vector<int> a;
    vector<int> b;
    int mx = -1;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x > 0) {
        a.push_back(x);
        lena++;
      } else if (x < 0) {
        b.push_back(-1 * x);
        lenb++;
      }
      mx = max(mx, abs(x));
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    if (!a.empty() && a[0] == mx) {
      long long ans = 0;
      for (int i = 0; i < lenb; i += k) {
        ans += 2 * b[i];
      }
      if (!a.empty()) {
        ans += a[0];
        for (int i = k; i < lena; i += k) {
          ans += 2 * a[i];
        }
      }
      cout << ans << endl;
    } else {
      long long ans = 0;
      for (int i = 0; i < lena; i += k) {
        ans += 2 * a[i];
      }
      if (!b.empty()) {
        ans += b[0];
        for (int i = k; i < lenb; i += k) {
          ans += 2 * b[i];
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
