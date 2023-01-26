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
    auto r = lower_bound(v.begin(), v.end(), drag[i].first);
    long long curr;
    if (r == v.begin()) {
      curr = v[0];
    } else if (r == v.end()) {
      curr = v[n - 1];
    } else {
      int idx = r - v.begin();
      if (v[idx] - drag[i].first > drag[i].first - v[idx - 1]) {
        curr = v[idx - 1];
      } else
        curr = v[idx];
    }
    ans = ans + max(long long(0), drag[i].first - curr) +
          max(long long(0), drag[i].second - (sum - curr));
    cout << ans << "\n";
  }
  return 0;
}
