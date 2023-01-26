#include <bits/stdc++.h>
using namespace std;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
struct DSU {
  vector<int> e;
  DSU(int N) { e = vector<int>(N, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool same_set(int a, int b) { return get(a) == get(b); }
  int size(int x) { return -e[get(x)]; }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};
const int maxn = 1001;
vector<pair<int, int>> ansEdge;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  DSU dsu1(n);
  DSU dsu2(n);
  int from, to;
  for (int i = 0; i < m1; i++) {
    cin >> from >> to;
    dsu1.unite(from, to);
  }
  for (int i = 0; i < m2; i++) {
    cin >> from >> to;
    dsu2.unite(from, to);
  }
  int64_t ans = 0;
  vector<pair<int, int>> edAns;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!dsu1.same_set(i, j) && !dsu2.same_set(i, j)) {
        ans += 1;
        edAns.push_back({i, j});
        dsu1.unite(i, j);
        dsu2.unite(i, j);
      }
    }
  }
  cout << ans << "\n";
  for (auto i : edAns) {
    cout << i.first << " " << i.second << "\n";
  }
  return 0;
}
