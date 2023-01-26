#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
long long inf = 1e9 + 10;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  long long can_increase = 0;
  long long in_order = 0;
  long long counted = 0;
  vector<long long> save;
  bool ok = true;
  for (long long i = 0; i <= n; i++) {
    long long ans = 0;
    if (!ok) {
      cout << -1 << " ";
      continue;
    }
    if (mp[i] == 0) {
      ans = counted;
      if (((long long)(save).size())) {
        counted += i - save.back();
        save.pop_back();
      } else {
        ok = false;
      }
    } else {
      ans += mp[i];
      ans += counted;
      for (long long j = 1; j < mp[i]; j++) {
        save.push_back(i);
      }
    }
    cout << ans << " ";
  }
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
