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
    int val;
    cin >> val;
    v.push_back(val);
    sum += val;
  }
  int m;
  cin >> m;
  vector<pair<long long, long long>> drag;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    drag.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    long long ans = 0;
    long long temp = sum;
    auto r = lower_bound(v.begin(), v.end(), drag[i].first);
    long long curr;
    if (r == v.begin()) {
      curr = v[0];
      ans += max(long long(0), drag[i].first - curr);
      ans += max(long long(0), drag[i].second - (sum - curr));
    } else if (r == v.end()) {
      curr = v[n - 1];
      ans += (drag[i].first - curr);
      ans += max(long long(0), drag[i].second - (sum - curr));
    } else {
      long long prev = 0, now = 0;
      int idx = r - v.begin();
      curr = v[idx - 1];
      prev = max(long long(0), drag[i].first - curr) +
             max(long long(0), drag[i].second - (sum - curr));
      curr = v[idx];
      now = max(long long(0), drag[i].first - curr) +
            max(long long(0), drag[i].second - (sum - curr));
      ans += min(prev, now);
    }
    cout << ans << "\n";
  }
  return 0;
}
