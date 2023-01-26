#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const long long int MOD = 1e9 + 7;
const long long int mod = 998244353;
void solve() {
  int n, q;
  cin >> n;
  vector<long long int> ar(n);
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    sum += ar[i];
  }
  sort(ar.begin(), ar.end());
  cin >> q;
  while (q--) {
    vector<long long int> res;
    long long int x, y;
    cin >> x >> y;
    int l = 0, r = n - 1, mid;
    while (l <= r) {
      mid = l + (r - l) / 2;
      if (ar[mid] > x)
        r = mid - 1;
      else
        l = mid + 1;
    }
    if (ar[r] >= 0) {
      int t = max(0ll, x - ar[r]) + max(0ll, y - (sum - ar[r]));
      res.push_back(t);
    }
    if (r + 1 < n) {
      int t = max(0ll, x - ar[r + 1]) + max(0ll, y - (sum - ar[r + 1]));
      res.push_back(t);
    }
    sort(res.begin(), res.end());
    cout << res[0] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
