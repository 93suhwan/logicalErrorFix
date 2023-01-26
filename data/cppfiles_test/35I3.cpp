#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> factors[1000005];
int arr[1000005];
char brr[1000005];
vector<pair<int, int>> v[1000005];
int sum[1000005];
int ans[1000005];
int pos[1000005];
struct SegTree {
  vector<int> t;
  vector<pair<int, int>> arr;
  SegTree() {}
  SegTree(vector<pair<int, int>> x) {
    arr = x;
    t.resize(4 * arr.size(), 1e9);
    build(1, 0, arr.size() - 1);
  }
  void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = arr[tl].first;
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm), build(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
  int get(int v, int tl, int tr, int l, int r, int val) {
    if (tr < l || r < tl) return -1;
    if (l <= tl && tr <= r) {
      return (t[v] < val ? tl : -1);
    }
    int tm = (tl + tr) / 2;
    int tmp = get(v * 2, tl, tm, l, r, val);
    if (tmp != -1) return tmp;
    return get(v * 2 + 1, tm + 1, tr, l, r, val);
  }
};
vector<SegTree> trees(1000005);
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < 1000005; i++) ans[i] = n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> brr[i];
  }
  for (int i = 1; i <= n; i++) {
    for (auto u : factors[arr[i]]) {
      if (brr[i] == '/') {
        sum[u.first] -= u.second;
      }
      if (brr[i] == '*') {
        sum[u.first] += u.second;
      }
      v[u.first].push_back({sum[u.first], i});
      if (sum[u.first] < 0) ans[u.first] = min(ans[u.first], i - 1);
    }
  }
  multiset<int> s;
  for (int i = 0; i < 1000005; i++) s.insert(ans[i]);
  for (int i = 0; i < 1000005; i++) {
    if (v[i].empty()) continue;
    SegTree tmp(v[i]);
    trees[i] = tmp;
  }
  long long res = *s.begin();
  for (int i = 2; i <= n; i++) {
    for (auto u : factors[arr[i - 1]]) {
      s.erase(s.find(ans[u.first]));
      int tmp = trees[u.first].get(1, 0, v[u.first].size() - 1,
                                   pos[u.first] + 1, v[u.first].size() - 1,
                                   v[u.first][pos[u.first]].first);
      if (tmp == -1)
        ans[u.first] = n;
      else
        ans[u.first] = v[u.first][tmp].second - 1;
      pos[u.first]++;
      s.insert(ans[u.first]);
    }
    res += max(0, *s.begin() - i + 1);
  }
  cout << res << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 2; i < 1000005; i++) {
    if (factors[i].empty()) {
      for (int j = i; j < 1000005; j += i) {
        int tmp = j;
        int cnt = 0;
        while (tmp / i * i == tmp) {
          tmp /= i;
          cnt++;
        }
        factors[j].push_back({i, cnt});
      }
    }
  }
  int t = 1;
  while (t--) {
    solve();
  }
}
