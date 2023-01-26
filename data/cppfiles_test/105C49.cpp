#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int res = n;
  map<int, multimap<pair<int, int>, int>> mp;
  vector<pair<int, int>> w(n);
  for (int i = 0; i < n; i++) {
    int a, b, m;
    cin >> a >> b >> m;
    w[i].first = a;
    w[i].second = m;
    int sm = a + b - m;
    auto it = mp.find(sm);
    if (it == mp.end()) {
      it = mp.emplace(sm, multimap<pair<int, int>, int>()).first;
    }
    it->second.emplace(make_pair(max(0, a - m), min(a, sm)), i);
  }
  for (auto& st : mp) {
    int min_cls;
    vector<int> mmb;
    for (auto& pr : st.second) {
      if (mmb.empty()) {
        min_cls = pr.first.second;
        mmb.push_back(pr.second);
      } else {
        if (min_cls >= pr.first.first) {
          mmb.push_back(pr.second);
          min_cls = min(min_cls, pr.first.second);
        } else {
          res -= (int)mmb.size() - 1;
          for (int mb : mmb) {
            w[mb].first = w[mb].first - min_cls;
            w[mb].second = w[mb].second - w[mb].first;
          }
          mmb.clear();
          min_cls = pr.first.second;
          mmb.push_back(pr.second);
        }
      }
    }
    res -= (int)mmb.size() - 1;
    for (int mb : mmb) {
      w[mb].first = w[mb].first - min_cls;
      w[mb].second = w[mb].second - w[mb].first;
    }
  }
  cout << res << endl;
  for (auto& rp : w) {
    cout << rp.first << " " << rp.second << endl;
  }
}
int main() {
  int ncases;
  cin >> ncases;
  for (int i = 0; i < ncases; i++) {
    solve();
  }
}
