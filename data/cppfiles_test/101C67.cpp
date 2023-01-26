#include <bits/stdc++.h>
using namespace std;
int ttt = 1, n, m, k, x;
template <class myType>
void print_arr(myType &arr, long long L, string sep) {
  for (long long(i) = (0); (i) < (L); ++(i)) {
    cout << arr[i];
    if (i < L - 1) cout << sep;
  }
  cout << "\n";
  return;
}
void solve() {
  cin >> n >> m >> k;
  vector<int> x_streets(n), y_streets(m), x, y;
  map<int, int> x_map, y_map;
  map<int, vector<int> > x_pts, y_pts;
  for (long long(i) = (0); (i) < (n); ++(i)) {
    cin >> x_streets[i];
    x_map[x_streets[i]] = 1;
  }
  for (long long(i) = (0); (i) < (m); ++(i)) {
    cin >> y_streets[i];
    y_map[y_streets[i]] = 1;
  }
  for (long long(i) = (0); (i) < (k); ++(i)) {
    int a, b;
    cin >> a >> b;
    if (x_map[a] && y_map[b]) continue;
    if (x_map[a]) {
      y.push_back(b);
      x_pts[a].push_back(b);
    } else {
      x.push_back(a);
      y_pts[b].push_back(a);
    }
  }
  long long ans = 0;
  sort(x_streets.begin(), x_streets.end());
  sort(y_streets.begin(), y_streets.end());
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  map<int, vector<int> >::iterator it = x_pts.begin();
  while (it != x_pts.end()) {
    int q = it->first;
    sort(x_pts[q].begin(), x_pts[q].end());
    int i = 0, j = 0;
    while (i < x_pts[q].size()) {
      auto lb = lower_bound(y_streets.begin(), y_streets.end(), x_pts[q][i]);
      while (j < x_pts[q].size() &&
             lower_bound(y_streets.begin(), y_streets.end(), x_pts[q][j]) ==
                 lb) {
        j++;
      }
      ans += j - i - 1;
      i++;
    }
    it++;
  }
  it = y_pts.begin();
  while (it != y_pts.end()) {
    int q = it->first;
    sort(y_pts[q].begin(), y_pts[q].end());
    int i = 0, j = 0;
    while (i < y_pts[q].size()) {
      auto lb = lower_bound(x_streets.begin(), x_streets.end(), y_pts[q][i]);
      while (j < y_pts[q].size() &&
             lower_bound(x_streets.begin(), x_streets.end(), y_pts[q][j]) ==
                 lb) {
        j++;
      }
      ans += j - i - 1;
      i++;
    }
    it++;
  }
  int i = 0, j = 0;
  while (i < x.size()) {
    auto lb = lower_bound(x_streets.begin(), x_streets.end(), x[i]);
    while (j < x.size() &&
           lower_bound(x_streets.begin(), x_streets.end(), x[j]) == lb) {
      j++;
    }
    ans -= j - i - 1;
    i++;
  }
  i = 0, j = 0;
  while (i < y.size()) {
    auto lb = lower_bound(y_streets.begin(), y_streets.end(), y[i]);
    while (j < y.size() &&
           lower_bound(y_streets.begin(), y_streets.end(), y[j]) == lb) {
      j++;
    }
    ans -= j - i - 1;
    i++;
  }
  cout << -ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> ttt;
  while (ttt--) solve();
  return 0;
}
