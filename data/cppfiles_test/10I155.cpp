#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using ll = long long;
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vector<pair<int, int>> s2;
  set<pair<int, int>> d;
  vector<int> res(n, 0);
  for (int i = 0; i < k; i++) {
    d.insert(make_pair(0, i));
  }
  for (int i = 0; i < n; i++) {
    s2.push_back(make_pair(s[i], i));
  }
  sort(s2.begin(), s2.end());
  int mx = 0;
  vector<int> cls_usd(k + 1, 0);
  vector<int> usd(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pair<int, int> q = *(d.begin()), w = s2[i];
    d.erase(d.begin());
    usd[w.first]++;
    if (usd[w.first] <= k) {
      q.first++;
      mx = max(mx, q.first);
      res[w.second] = q.second + 1;
      cls_usd[q.second]++;
    }
    d.insert(q);
  }
  set<int> fch;
  for (int i = 0; i < k; i++) {
    if (cls_usd[i] != 0 && cls_usd[i] != mx) {
      fch.insert(i);
      cout << i << endl;
    }
  }
  for (int i = 0; i < n; i++) {
    if (fch.find(res[i] - 1) == fch.end()) {
      fch.insert(res[i] - 1);
      res[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) cout << res[i] << ' ';
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}
