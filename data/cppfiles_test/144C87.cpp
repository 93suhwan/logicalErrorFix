#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long testCases;
  cin >> testCases;
  while (testCases--) {
    long long n, m, k;
    cin >> n >> m >> k;
    multiset<pair<long long, long long>> s;
    for (long long i = 1; i <= n; ++i) {
      s.insert({0, i});
    }
    while (k--) {
      vector<pair<long long, long long>> v, v2;
      long long x = n / m;
      long long cnt = (n % m) * (x + 1);
      while (cnt--) {
        v.push_back(*s.begin());
        s.erase(s.begin());
      }
      cnt = (m - n % m) * x;
      while (cnt--) {
        v.push_back(*s.begin());
        s.erase(s.begin());
      }
      long long j = 0;
      for (long long i = 0; i < n % m; ++i) {
        cout << x + 1 << " ";
        for (long long y = j; y < j + x + 1; ++y) {
          cout << v[y].second << " ";
          s.insert({v[y].first + 1, v[y].second});
        }
        j += (x + 1);
        cout << "\n";
      }
      for (long long i = n % m; i < m; ++i) {
        cout << x << " ";
        for (long long y = j; y < j + x; ++y) {
          cout << v[y].second << " ";
          s.insert({v[y].first, v[y].second});
        }
        j += x;
        cout << "\n";
      }
    }
    cout << "\n\n";
  }
}
