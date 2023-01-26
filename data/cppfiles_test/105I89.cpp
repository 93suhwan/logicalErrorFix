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
vector<pair<pair<int, int>, pair<int, int>>> f[N];
pair<int, int> Ans[N];
void solve() {
  cin >> n;
  Map.clear();
  m = 0;
  for (int i = 0, x, y, z; i < n; ++i) {
    cin >> x >> y >> z;
    if (!Map.count(x + y - z)) {
      Map[x + y - z] = m;
      f[m++].clear();
    }
    f[Map[x + y - z]].push_back({{x, y}, {z, i}});
  }
  cout << m << "\n";
  for (int i = 0; i < m; ++i) {
    int x = f[i].begin()->first.first + f[i].begin()->first.second -
            f[i].begin()->second.first;
    for (auto &a : f[i]) {
      chkMin(x, a.first.first);
    }
    for (auto &a : f[i]) {
      Ans[a.second.second] = {a.first.first - x,
                              a.second.first - a.first.first + x};
    }
  }
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
