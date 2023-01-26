#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long N = 4e5 + 10;
const long long MOD = 998244353;
const long long inf = 1e10;
const long double eps = 1e-12;
const long double EPS = 1e-10;
long long rx[] = {1, -1, 0, 0};
long long ry[] = {0, 0, 1, -1};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      a[i]--;
    }
    vector<long long> pos[n];
    long long m = 0;
    for (long long i = 0; i < n; ++i) {
      if (pos[a[i]].size() == k) continue;
      pos[a[i]].push_back(i);
      m++;
    }
    m -= m % k;
    long long cl = 1;
    vector<long long> ans(n, 0);
    for (long long i = 0; i < n && m > 0; ++i) {
      for (auto to : pos[i]) {
        if (m == 0) break;
        if (cl == 1 + k) cl = 1;
        ans[to] = cl;
        cl++;
        m--;
      }
    }
    for (auto to : ans) cout << to << ' ';
    cout << '\n';
  }
  return 0;
}
