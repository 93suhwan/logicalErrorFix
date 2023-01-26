#include <bits/stdc++.h>
using namespace std;
void solve(long long nn) {
  long long n;
  cin >> n;
  vector<pair<pair<long long, long long>, pair<long long, long long>>> vp;
  long long a[n], b[n];
  map<long long, long long> mp;
  set<long long> second;
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    vp.push_back({{b[i] - a[i], i}, {a[i], b[i]}});
    mp[a[i]]++;
    mp[b[i]]++;
  }
  long long ans[n];
  sort(vp.begin(), vp.end());
  reverse(vp.begin(), vp.end());
  for (long long i = 1; i <= n; i++) {
    if (mp[i] == 0) {
      second.insert(i);
    }
  }
  for (long long i = 0; i < n; i++) {
    mp[vp[i].second.second]--;
    mp[vp[i].second.first]--;
    if (mp[vp[i].second.second] == 0) {
      second.insert(vp[i].second.second);
    }
    if (mp[vp[i].second.first] == 0) {
      second.insert(vp[i].second.first);
    }
    long long id = vp[i].first.second;
    long long val = *(second.begin());
    ans[id] = val;
    second.erase(val);
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
