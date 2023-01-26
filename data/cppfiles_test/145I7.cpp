#include <bits/stdc++.h>
using namespace std;
struct dsu {
 private:
  int _n;
  vector<int> arr;
  vector<int> rank;
  vector<int> timer;

 public:
  dsu() : _n(0) {}
  dsu(int n) : _n(n) {
    arr.clear();
    for (int i = 0; i < _n; ++i) arr.push_back(i);
    rank.clear();
    rank.resize(_n, 0);
    timer.resize(_n, INT_MAX);
  }
  void set(int x, int y) { timer[x] = y; }
  int parent(int x) {
    if (x == arr[x]) return x;
    return (arr[x] = parent(arr[x]));
  }
  int get_time(int x) { return timer[x]; }
  bool same(int x, int y) { return parent(x) == parent(y); }
  void join(int x, int y) {
    x = parent(x);
    y = parent(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      arr[x] = y;
      rank[y] += 1;
      timer[y] = min(timer[y], timer[x]);
    } else if (rank[x] > rank[y]) {
      arr[y] = x;
      rank[x] += 1;
      timer[x] = min(timer[y], timer[x]);
    } else {
      arr[x] = y;
      rank[y] += 1;
      timer[y] = min(timer[y], timer[x]);
    }
  }
  vector<vector<int>> groups() {
    int x = 0;
    vector<int> temp(_n, -1);
    for (int i = 0; i < _n; i++) {
      int a = parent(i);
      if (temp[a] == -1) temp[a] = x++;
    }
    vector<vector<int>> res(x, vector<int>{});
    for (int i = 0; i < _n; i++) {
      res[temp[parent(i)]].push_back(i);
    }
    return res;
  }
};
void work(dsu& d, vector<vector<int>>& arr, int k) {
  map<int, vector<pair<int, pair<int, int>>>> info;
  for (int i = 0; i < int(arr.size()); i++) {
    info[arr[i][0]].push_back({arr[i][1], {arr[i][2], arr[i][3]}});
  }
  for (auto& vec2 : info) {
    auto& vec = vec2.second;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < int(vec.size()) - 1; i++) {
      if (vec[i + 1].first - vec[i].first <= k) {
        d.join(vec[i].second.second, vec[i + 1].second.second);
      }
    }
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> arr(n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[i] = vector<int>{a, b, c, i};
  }
  dsu d(n);
  for (int i = 0; i < n; i++) {
    d.set(i, arr[i][2]);
  }
  work(d, arr, k);
  for (int i = 0; i < n; i++) {
    swap(arr[i][0], arr[i][1]);
  }
  work(d, arr, k);
  auto g = d.groups();
  vector<int> vec;
  for (auto& a : g) {
    vec.push_back(d.get_time(d.parent(a[0])));
  }
  sort(vec.begin(), vec.end());
  int ans = int(vec.size()) - 1;
  for (int i = 0; i < int(vec.size()); i++) {
    ans = min(ans, max(vec[i], n - i - 2));
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
