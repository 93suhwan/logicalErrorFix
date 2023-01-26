#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 0;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<pair<pair<long long, long long>, long long> > a(n);
    long long sa = 0, sb = 0, l = 0, r = 0, mxb = 0;
    for (auto& x : a) {
      cin >> x.first.first >> x.first.second;
      sa += x.first.first;
      sb += x.first.second;
      r += min(m, x.first.first);
      mxb += min(m, x.first.second);
    }
    for (long long i = 0; i < n; i++) a[i].second = i;
    while (r - l > 3) {
      long long m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
      if (m * n - m1 > mxb) {
        l = m1;
        continue;
      }
      if (m * n - m2 > mxb) {
        r = m2;
        continue;
      }
      long long bal1 = abs((sa - m1) - (sb - (n * m - m1))),
                bal2 = abs((sa - m2) - (sb - (n * m - m2)));
      if (bal1 < bal2)
        r = m2;
      else
        l = m1;
    }
    vector<pair<long long, long long> > av;
    for (long long i = l; i <= r; i++) {
      if (m * n - i > mxb) continue;
      long long bal = abs((sa - i) - (sb - (n * m - i)));
      av.push_back(make_pair(bal, i));
    }
    sort((av).begin(), (av).end());
    cout << av[0].first << '\n';
    long long lefta = av[0].second;
    vector<pair<long long, long long> > ans(n);
    for (long long i = 0; i < n; i++) {
      long long mn = max(0ll, m - a[i].first.second);
      ans[i].first += mn;
      lefta -= mn;
      mn = max(0ll, m - a[i].first.first);
      ans[i].second += mn;
    }
    for (long long i = 0; i < n; i++) {
      long long mn =
          min(m - ans[i].first - ans[i].second, min(lefta, a[i].first.first));
      ans[i].first += mn;
      lefta -= mn;
      ans[i].second = m - ans[i].first;
    }
    for (auto& x : ans) cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}
