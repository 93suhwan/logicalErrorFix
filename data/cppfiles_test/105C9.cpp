#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  map<int, vector<pair<pair<int, int>, int>>> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    m[a[i] + b[i] - c[i]].push_back({{a[i], b[i]}, i});
  }
  int count = 0;
  int sum, amin, amax, boun;
  vector<pair<pair<int, int>, int>> p;
  int kmm;
  vector<int> ans(n);
  for (auto x : m) {
    sum = x.first;
    ;
    ;
    p.clear();
    for (auto y : x.second) {
      kmm = y.first.first + y.first.second - sum;
      amin = y.first.first - min(kmm, y.first.first);
      amax = y.first.first + min(kmm, y.first.second) - kmm;
      p.push_back({{amin, amax}, y.second});
    }
    sort(p.begin(), p.end());
    boun = p[0].first.second;
    count++;
    ;
    int prev = 0;
    for (int i = 0; i < p.size(); i++) {
      ;
      ;
      if (p[i].first.first <= boun) {
        boun = min(boun, p[i].first.second);
      } else {
        count++;
        for (int j = prev; j < i; j++) {
          ans[p[j].second] = boun;
        }
        prev = i;
        boun = p[i].first.second;
      }
    }
    for (int j = prev; j < p.size(); j++) {
      ans[p[j].second] = boun;
    }
  }
  cout << count << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] - ans[i] << " " << c[i] - (a[i] - ans[i]) << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
