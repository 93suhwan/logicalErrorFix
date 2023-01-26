#include <bits/stdc++.h>
using namespace std;
mt19937 gena;
mt19937_64 gena64;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long INFll = 1e18;
template <typename T>
istream& operator>>(istream& in, vector<T>& arr) {
  for (int i = 0; i < arr.size(); i++) in >> arr[i];
  return in;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& arr) {
  for (int i = 0; i < arr.size(); i++) out << arr[i] << ' ';
  return out;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <typename T0, typename T1, typename T2>
struct triple {
  T0 first;
  T1 second;
  T2 third;
  triple(T0 _0, T1 _1, T2 _2) {
    this->first = _0;
    this->second = _1;
    this->third = _2;
  }
  triple() { first = second = third = 0; }
  friend istream& operator>>(istream& in, triple& t) {
    in >> t.first >> t.second >> t.third;
    return in;
  }
  friend ostream& operator<<(ostream& out, triple& t) {
    out << t.first << ' ' << t.second << ' ' << t.third;
    return out;
  }
};
template <typename T>
vector<T> operator+(vector<T> v, int num) {
  for (int i = 0; i < v.size(); i++) v[i] += num;
  return v;
}
struct graph {
  vector<vector<long long>> g;
  vector<long long> v;
  long long m;
  graph(long long n, long long m) {
    this->m = m;
    g.resize(n);
    v.resize(n);
  }
  graph() {}
};
std::istream& operator>>(std::istream& In, graph& gr) {
  for (long long i = 0; i < gr.m; i++) {
    long long f, t;
    In >> f >> t;
    gr.g[f - 1].push_back(t - 1);
    gr.g[t - 1].push_back(f - 1);
  }
  return In;
}
void solve(int test);
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int t = 1, test = 1;
  cin >> t;
  while (t--) solve(test++);
  return 0;
}
vector<vector<int>> path_len;
vector<vector<int>> step;
vector<string> field;
int n, m;
bool check_pos(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
pair<int, int> dfs(int x, int y, int cur_step = 0) {
  if (!check_pos(x, y)) return {0, -1};
  if (path_len[x][y] == -2) return {0, step[x][y]};
  if (path_len[x][y] >= 0) return {path_len[x][y], -1};
  int dx = 0, dy = 0;
  if (field[x][y] == 'U')
    dx = -1;
  else if (field[x][y] == 'D')
    dx = +1;
  else if (field[x][y] == 'L')
    dy = -1;
  else if (field[x][y] == 'R')
    dy = +1;
  path_len[x][y] = -2;
  step[x][y] = cur_step;
  auto [len, cycle_step] = dfs(x + dx, y + dy, cur_step + 1);
  if (cycle_step == -1) return {path_len[x][y] = 1 + len, -1};
  path_len[x][y] = 1 + len + cur_step - cycle_step;
  return {1 + len, (cur_step == cycle_step) ? -1 : cycle_step};
}
void solve(int test) {
  cin >> n >> m;
  field = vector<string>(n);
  for (auto& s : field) cin >> s;
  path_len.assign(n, vector<int>(m, -1));
  step.assign(n, vector<int>(m, 0));
  triple<int, int, long long> ans{0, 0, 0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (path_len[i][j] == -1) dfs(i, j);
      if (path_len[i][j] > ans.third) ans = {i, j, path_len[i][j]};
    }
  }
  cout << ans.first + 1 << ' ' << ans.second + 1 << ' ' << ans.third << '\n';
}
