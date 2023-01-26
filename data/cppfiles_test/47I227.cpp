#include <bits/stdc++.h>
using namespace std;
int binexp(int x, int y) {
  if (y == 0) return 1;
  if (y % 2 == 0) {
    int temp = binexp(x, y / 2);
    return temp * temp;
  }
  return x * binexp(x, y / 2) * binexp(x, y / 2);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long int ans = (long long)0;
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      if (k > 0)
        pos.push_back(k);
      else
        neg.push_back((-1 * k));
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int single = 0;
    if (pos.size() && neg.size())
      single = max(pos[pos.size() - 1], neg[neg.size() - 1]);
    else if (pos.size())
      single = pos[pos.size() - 1];
    else
      single = neg[neg.size() - 1];
    for (int i = pos.size() - 1; i >= 0; i -= k) ans += 2 * (pos[i]);
    for (int i = neg.size() - 1; i >= 0; i -= k) ans += 2 * (neg[i]);
    ans = ans - single;
    cout << ans << "\n";
    return 0;
  }
}
