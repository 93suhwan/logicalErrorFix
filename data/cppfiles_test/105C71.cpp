#include <bits/stdc++.h>
using namespace std;
template <class T, class G>
bool chkMax(T &x, G y) {
  return y > x ? x = y, 1 : 0;
}
template <class T, class G>
bool chkMin(T &x, G y) {
  return y < x ? x = y, 1 : 0;
}
const int N = 2e5 + 5;
int n, m;
map<int, int> Map;
vector<pair<pair<int, int>, pair<int, int>>> f[N], v;
pair<int, int> Ans[N];
pair<int, int> a[N];
void solve() {
  cin >> n;
  Map.clear();
  m = 0;
  for (int i = 0, x, y, z; i < n; ++i) {
    cin >> x >> y >> z;
    a[i] = {x, y};
    if (!Map.count(x + y - z)) {
      Map[x + y - z] = m;
      f[m++].clear();
    }
    f[Map[x + y - z]].push_back({{x, y}, {z, i}});
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    v.clear();
    for (auto &a : f[i]) {
      v.push_back(
          {{max(0, a.first.first - a.second.first),
            min(a.first.first,
                a.first.first + a.first.second - a.second.first)},
           {a.first.first + a.first.second - a.second.first, a.second.second}});
    }
    sort((v).begin(), (v).end());
    int p = -1, lst;
    for (int i = 0; i < (int)v.size(); ++i) {
      auto x = v[i];
      if (x.first.first > p) {
        ++ans;
        for (int j = lst; j < i; ++j) {
          int id = v[j].second.second;
          Ans[id] = {a[id].first - p, a[id].second - (v[j].second.first - p)};
        }
        lst = i;
        p = x.first.second;
      } else if (x.first.second < p)
        p = x.first.second;
    }
    for (int j = lst; j < (int)v.size(); ++j) {
      int id = v[j].second.second;
      Ans[id] = {a[id].first - p, a[id].second - (v[j].second.first - p)};
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; ++i)
    cout << Ans[i].first << " " << Ans[i].second << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int Case;
  cin >> Case;
  while (Case--) solve();
  return 0;
}
