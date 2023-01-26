#include <bits/stdc++.h>
using namespace std;
int t, k;
long long solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  queue<pair<long long, long long> > q;
  set<long long> myset;
  for (long long i = 0; i < n; i++) {
    queue<pair<long long, long long> > t;
    while (q.size()) {
      pair<long long, long long> top = q.front();
      q.pop();
      t.push(top);
      if (top.second == -1 || a[top.second] < a[i]) {
        t.push({top.first ^ a[i], i});
      }
    }
    q = t;
    q.push({a[i], i});
  }
  while (q.size()) {
    myset.insert(q.front().first);
    q.pop();
  }
  cout << myset.size() << endl;
  for (auto it = myset.begin(); it != myset.end(); ++it) cout << ' ' << *it;
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  t = 1;
  for (; t--; cout << endl) {
    solve();
  }
  return 0;
}
