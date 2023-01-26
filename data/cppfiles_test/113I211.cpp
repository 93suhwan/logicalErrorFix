#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const long long int MOD = 1e9 + 7;
const long long int mod = 998244353;
void solve() {
  int n, m;
  cin >> n;
  vector<long long int> v(n);
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  sort(v.begin(), v.end());
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    int r = 0, l = v.size() - 1;
    while (r <= l) {
      int mid = (l + r) / 2;
      if (v[mid] > a)
        l = mid - 1;
      else
        r = mid + 1;
    }
    vector<int> v1;
    int ans;
    if (l >= 0) {
      ans = max(0ll, a - v[l]) + max(0ll, b - (sum - v[l]));
      v1.push_back(ans);
    }
    if (l + 1 < v.size()) {
      ans = max(0ll, a - v[l + 1]) + max(0ll, b - (sum - v[l + 1]));
      v1.push_back(ans);
    }
    sort(v1.begin(), v1.end());
    cout << v1[0] << "\n";
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
