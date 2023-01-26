#include <bits/stdc++.h>
using namespace std;
class config {
 public:
  int hi;
  int lo;
  int last_value;
  config* last_node;
  bool operator<=(config& c) {
    if (hi != c.hi) return hi < c.hi;
    if (lo != c.lo) return (lo < c.lo);
    return true;
  }
};
bool comp(config* c1, config* c2) {
  if (c1->hi != c2->hi) return c1->hi < c2->hi;
  if (c1->lo != c2->lo) return (c1->lo < c2->lo);
  return true;
}
int p[1000001];
int ans[1000001];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    vector<config*> configs;
    configs.push_back(new config{-1000001, -1000002, 0, 0});
    for (int k = 0; k < n; k++) {
      int i = p[k];
      vector<config*> next;
      for (auto c : configs) {
        if (i > c->hi)
          next.push_back(new config{i, c->lo, i, c});
        else if (i > c->lo)
          next.push_back(new config{c->hi, i, i, c});
        if (-i > c->hi)
          next.push_back(new config{-i, c->lo, -i, c});
        else if (-i > c->lo)
          next.push_back(new config{c->hi, -i, -i, c});
      }
      sort(next.begin(), next.end(), comp);
      configs.clear();
      for (config* c : next) {
        if (configs.size() == 0 || configs.back()->hi == c->hi)
          configs.push_back(c);
      }
    }
    if (configs.size()) {
      cout << "YES" << endl;
      config c = *configs.back();
      for (int i = n - 1; i >= 0; i--) {
        ans[i] = c.last_value;
        c = *c.last_node;
      }
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
