#include <bits/stdc++.h>
using namespace std;
template <class T>
struct fenwick_tree {
 private:
  int _n;
  vector<T> arr;
  T query(long long x) {
    long long ans = 0;
    for (long long i = x; i >= 0; i = (i & (i + 1)) - 1) {
      ans += arr[i];
    }
    return ans;
  }

 public:
  fenwick_tree() : _n(0) {}
  fenwick_tree(int n) : _n(n), arr(n) {}
  void update(long long x, T val) {
    long long ans = 0;
    for (long long i = x; i < arr.size(); i = (i | (i + 1))) {
      arr[i] += (long long)(val);
    }
  }
  T query(int l, int r) { return query(r) - query(l - 1); }
  void clear() {
    for (int i = 0; i < _n; i++) arr[i] = 0;
  }
};
void unique(vector<int> &arr) {
  vector<int> t;
  for (int i = 0; i < int(arr.size());) {
    int v = arr[i];
    while (i < int(arr.size()) and arr[i] == v) i++;
    t.push_back(v);
  }
  arr = t;
  return;
}
void solve() {
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> arr(1, {-1, d});
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr.push_back({x, y});
    if (arr[i].first < d) arr.pop_back();
  }
  n = int(arr.size());
  vector<pair<int, int>> sorted(n);
  for (int i = 0; i < n; i++) sorted[i] = {arr[i].second, i};
  sort(sorted.begin(), sorted.end());
  vector<int> skills;
  for (int i = 0; i < n; i++) skills.push_back(arr[i].first);
  sort(skills.begin(), skills.end());
  unique(skills);
  int Len = int(skills.size());
  fenwick_tree<int> f(Len);
  map<int, int> skills_id;
  for (int i = 0; i < Len; i++) skills_id[skills[i]] = i;
  vector<pair<int, int>> left(n);
  for (int i = 0; i < n; i++) {
    int j = sorted[i].second;
    int s = arr[j].first;
    int l =
        lower_bound(sorted.begin(), sorted.end(), pair<int, int>{s, INT_MAX}) -
        sorted.begin();
    l--;
    l = min(l, i - 1);
    left[i] = {l, i};
  }
  sort(left.begin(), left.end());
  vector<int> pref(n);
  for (int i = 0, j = -1; i < n; i++) {
    int l = left[i].first;
    while (j < l) {
      j++;
      int id = sorted[j].second;
      int s = arr[id].first;
      id = skills_id[s];
      f.update(id, 1);
    }
    int id = left[i].second;
    int neat = sorted[id].first;
    int j2 = lower_bound(skills.begin(), skills.end(), neat) - skills.begin();
    if (j2 != Len) pref[id] = f.query(j2, Len - 1);
  }
  f.clear();
  vector<int> dpexc(n), dpinc(n);
  int res = 0;
  for (int i = 1; i < n; i++) {
    int j = sorted[i].second;
    int s = arr[j].first;
    int l =
        lower_bound(sorted.begin(), sorted.end(), pair<int, int>{s, INT_MAX}) -
        sorted.begin();
    l--;
    l = min(l, i - 1);
    int neat = sorted[i].first;
    j = lower_bound(skills.begin(), skills.end(), neat) - skills.begin();
    dpinc[i] = dpinc[l] - pref[i] + f.query(j, Len - 1) + 1;
    int _s = sorted[l].second;
    _s = arr[_s].first;
    int y = 0;
    if (_s >= sorted[i].first) y = 1;
    dpinc[i] = max(dpinc[i], dpexc[l] + f.query(j, Len - 1) + 1 + (y));
    int x = 0;
    j = sorted[i].second;
    s = arr[j].first;
    if (s >= sorted[i - 1].first) x = 1;
    dpexc[i] = dpexc[i - 1];
    s = skills_id[s];
    f.update(s, 1);
    res = max(res, max(dpexc[i], dpinc[i]));
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
