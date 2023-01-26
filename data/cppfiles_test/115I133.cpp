#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long int n, h;
vector<long long int> v;
bool check(long long int k) {
  long long int damage = 0;
  for (int i = 0; i < n; i++) {
    damage += min(v[i + 1] - v[i], k);
  }
  return (damage >= h);
}
void solve() {
  cin >> n >> h;
  v.clear();
  for (int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    v.push_back(x);
  }
  v.push_back(1e18 + 100);
  long long int lo = 0ll, hi = 1e18 + 1e18;
  long long int ans = -1;
  while (lo < hi) {
    long long int mid = (lo + hi + 1) / 2ll;
    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  cout << max(1ll, ans) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  for (int testcase = 1; testcase <= T; testcase++) {
    solve();
  }
  return 0;
}
