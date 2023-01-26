#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
int dirs[8][2] = {{0, 1},  {1, 0},  {1, 1},  {-1, -1},
                  {0, -1}, {-1, 0}, {-1, 1}, {1, -1}};
struct {
  bool operator()(pi& a, pi& b) const { return a.first < b.first; }
} compareLeft;
struct {
  bool operator()(pi& a, pi& b) const {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  }
} compareRight;
struct FenwickTree {
  vector<int> bit;
  int n;
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }
  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pi> a;
  vector<int> ok(m + 1);
  for (int i = 0; i < n * m; i++) {
    int v;
    cin >> v;
    a.push_back({v, i});
  }
  sort(a.begin(), a.end(), compareRight);
  for (int i = 0; i < n * m; i++) {
    pi p = a[i];
    ok[p.second] = i;
  }
  int cnt = 0;
  auto ft = FenwickTree(m + 1);
  for (int i = 0; i < m; i++) {
    cnt += ft.sum(0, ok[i]);
    ft.add(ok[i], 1);
  }
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
