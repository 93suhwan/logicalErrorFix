#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, t;
  pair<long long, long long> pi, pj;
  priority_queue<pair<long long, long long> > q;
  vector<pair<long long, long long> > ans;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> t;
    if (t) q.push({t, i});
  }
  while (q.size() > 1) {
    pi = q.top();
    q.pop();
    pj = q.top();
    q.pop();
    ans.push_back({pi.second, pj.second});
    if (--pi.first) q.push(pi);
    if (--pj.first) q.push(pj);
  }
  cout << ans.size() << endl;
  for (pair<long long, long long> &p : ans)
    cout << p.first << ' ' << p.second << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long tcs;
  cin >> tcs;
  while (tcs--) solve();
  return 0;
}
