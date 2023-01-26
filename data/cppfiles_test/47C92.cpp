#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> pa, na;
    int ma = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a > 0) pa.push_back(a);
      if (a < 0) na.push_back(-a);
      ma = max(ma, abs(a));
    }
    sort(pa.begin(), pa.end());
    sort(na.begin(), na.end());
    long long sol = -ma;
    for (int i = pa.size() - 1; i >= 0; i -= k) {
      sol += 2 * pa[i];
    }
    for (int i = na.size() - 1; i >= 0; i -= k) {
      sol += 2 * na[i];
    }
    cout << sol << endl;
  }
  return 0;
}
