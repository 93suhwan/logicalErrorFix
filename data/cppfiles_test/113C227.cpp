#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long sum = 0;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long val;
    cin >> val;
    v.push_back(val);
    sum += val;
  }
  long long m;
  cin >> m;
  vector<pair<long long, long long>> drag;
  for (int i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    drag.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    long long ans = 0;
    auto r = lower_bound(v.begin(), v.end(), drag[i].first);
    long long curr;
    if (r == v.begin()) {
      curr = *r;
      ans += max(long long(0), drag[i].second - (sum - curr));
    } else if (r == v.end()) {
      r--;
      curr = *r;
      ans += (drag[i].first - curr);
      ans += max(long long(0), drag[i].second - (sum - curr));
    } else {
      long long prev = 0, now = 0;
      curr = *r;
      now = max(long long(0), drag[i].second - (sum - curr));
      r--;
      long long curr2 = *r;
      prev = drag[i].first - curr2 +
             max(long long(0), drag[i].second - (sum - curr2));
      ans += min(prev, now);
    }
    cout << ans << "\n";
  }
  return 0;
}
