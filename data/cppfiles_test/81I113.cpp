#include <bits/stdc++.h>
using namespace std;
const int sok = 1e9 + 1;
int n, d, cnt, ert;
vector<pair<int, int> > a, b;
set<pair<int, int> > s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> d;
  s.insert({0, 0}), s.insert({sok, sok});
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    l = i, r = i;
    if (l >= d) {
      if (l >= r) {
        auto it = s.upper_bound({r, sok});
        it--;
        while ((*it).second >= l) {
          s.erase(it);
          it = s.upper_bound({r, sok});
          it--;
        }
        it = s.upper_bound({r, -sok});
        if ((*it).second > l) {
          s.insert({r, l});
        }
        cnt++;
      } else {
        a.push_back({r, l});
      }
    }
  }
  sort(a.begin(), a.end());
  for (auto x : a) {
    int kezd = x.second, veg = x.first;
    auto it = s.upper_bound({kezd, sok});
    if ((*it).second >= veg && kezd >= ert) {
      cnt++;
      ert = veg;
    }
  }
  cout << cnt << "\n";
  return 0;
}
