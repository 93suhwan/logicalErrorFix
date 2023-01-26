#include <bits/stdc++.h>
using namespace std;
const long long maxn = 300007;
const long long mod = 998244353;
long long n;
long long a[maxn], b[maxn], c[maxn];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>>
    pq;
vector<long long> reach[maxn];
vector<long long> ans;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.precision(15), cerr.precision(10);
  cin >> n;
  for (long long i = 1; i <= (long long)(n); ++i) cin >> a[i];
  for (long long i = 1; i <= (long long)(n); ++i) cin >> b[i];
  for (long long i = 1; i <= (long long)(n); ++i) {
    c[b[i] + i] = max(c[b[i] + i], i);
  }
  for (long long i = 1; i <= (long long)(n); ++i) {
    reach[max(0ll, i - a[i])].push_back(i);
  }
  long long cur = 0;
  for (auto d : reach[0]) {
    pq.push({c[d], d});
  }
  while ((long long)(pq).size() && cur < n - a[n]) {
    auto [u, v] = pq.top();
    pq.pop();
    if (u <= cur) continue;
    for (long long i = cur + 1; i <= u; ++i) {
      for (auto idx : reach[i]) {
        pq.push({c[idx], idx});
      }
    }
    ans.push_back(u);
    cur = u;
  }
  if (cur < n - a[n])
    cout << -1;
  else {
    reverse(begin(ans), end(ans));
    ans.push_back(0);
    cout << (long long)(ans).size() << "\n";
    for (auto c : ans) cout << c << " ";
  }
  return 0;
}
