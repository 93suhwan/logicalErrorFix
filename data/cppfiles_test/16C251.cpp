#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt = 1;
  cin >> tt;
  while (tt--) {
    long long int n;
    cin >> n;
    long long int a[n + 1];
    for (long long int i = 1; i <= n; i++) cin >> a[i];
    set<pair<long long int, long long int> > s;
    for (long long int i = 1; i <= n; i++)
      if (a[i] != 0) s.insert({a[i], i});
    vector<pair<long long int, long long int> > v;
    while (s.size() > 1) {
      long long int x = (*s.begin()).first, y = (*s.rbegin()).first,
                    z = (*s.begin()).second, w = (*s.rbegin()).second;
      s.erase(s.begin());
      auto it = s.end();
      it--;
      s.erase(it);
      if (x > 0 && y > 0) v.push_back({z, w});
      x--, y--;
      if (x > 0) s.insert({x, z});
      if (y > 0) s.insert({y, w});
    }
    cout << v.size() << "\n";
    for (auto it : v) cout << it.first << " " << it.second << "\n";
  }
  return 0;
}
