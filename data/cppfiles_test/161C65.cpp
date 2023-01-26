#include <bits/stdc++.h>
using namespace std;
void solve(long long nn) {
  long long n;
  cin >> n;
  vector<pair<pair<long long, long long>, pair<long long, long long>>> vp;
  long long a[n], b[n];
  map<long long, long long> mp;
  set<pair<long long, long long>> second;
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    vp.push_back({{b[i] - a[i], i}, {a[i], b[i]}});
    mp[a[i]]++;
    mp[b[i]]++;
    second.insert({a[i], b[i]});
  }
  long long ans[n];
  sort(vp.begin(), vp.end());
  reverse(vp.begin(), vp.end());
  for (long long i = 0; i < n; i++) {
    long long l = vp[i].second.first;
    long long r = vp[i].second.second;
    long long id = vp[i].first.second;
    if (l == r) {
      ans[id] = l;
      second.erase({l, r});
      continue;
    }
    for (long long d = l; d <= r; d++) {
      if (d == l) {
        if (second.find({l + 1, r}) != second.end()) {
          ans[id] = d;
          break;
        }
      } else if (d == r) {
        if (second.find({l, r - 1}) != second.end()) {
          ans[id] = d;
          break;
        }
      } else {
        if (second.find({l, d - 1}) != second.end() and
            second.find({d + 1, r}) != second.end()) {
          ans[id] = d;
          break;
        }
      }
    }
    second.erase({l, r});
  }
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " " << b[i] << " " << ans[i] << "\n";
  }
  return;
}
int main() {
  std::cout << std::fixed;
  std::cout << std::setprecision(15);
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
