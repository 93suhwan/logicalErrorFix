#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long N = 5e5 + 5;
long long a[N], n;
vector<long long> ans;
vector<pair<long long, pair<long long, long long> > > q;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < N; ++i) a[i] = i;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    long long b;
    cin >> b;
    if (b == 1) {
      long long c;
      cin >> c;
      q.push_back({b, {c, -1}});
    } else {
      long long c, d;
      cin >> c >> d;
      q.push_back({b, {c, d}});
    }
  }
  reverse(q.begin(), q.end());
  for (long long i = 0; i < n; ++i) {
    if (q[i].first == 1) {
      ans.push_back(a[q[i].second.first]);
    } else {
      a[q[i].second.first] = a[q[i].second.second];
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto i : ans) cout << i << " ";
  return 0;
}
