#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  ;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<long long>> a(n, vector<long long>(2));
    map<long long, vector<long long>> m1;
    map<long long, long long> m2;
    for (long long i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      m1[x].push_back(y);
      m2[y]++;
    }
    long long res = 0;
    res = (n * (n - 1) * (n - 2)) / 6;
    long long ans = 0;
    for (auto i : m1) {
      for (long long j = 0; j < i.second.size(); j++)
        ans += (i.second.size() - 1) * (m2[i.second[j]] - 1);
    }
    cout << res - ans << endl;
  }
  return 0;
}
