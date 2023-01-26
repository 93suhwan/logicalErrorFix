#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long res = 0;
    int n, k, ex = 0;
    cin >> n >> k;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
      int v;
      cin >> v;
      if (v > 0)
        a.push_back(v);
      else
        b.push_back(-1 * v);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = a.size() - 1; i >= 0; i = i - k) {
      res += a[i] * 2;
      ex = max(ex, a[i]);
      if (!i) break;
    }
    for (int i = b.size() - 1; i >= 0; i = i - k) {
      res += b[i] * 2;
      ex = max(ex, b[i]);
      if (!i) break;
    }
    cout << res - ex << "\n";
  }
  return 0;
}
