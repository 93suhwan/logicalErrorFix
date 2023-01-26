#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);
const int iinf = 0x3f3f3f3f;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
void vars(istream_iterator<string> it) { cerr << '\n'; }
template <typename T, typename... Args>
void vars(istream_iterator<string> it, T a, Args... args) {
  cerr << " [" << *it << ": " << a << "] ";
  vars(++it, args...);
}
template <class T1, class T2, class T3>
void printTuple(const tuple<T1, T2, T3> &t) {
  cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';
}
template <class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  return out << p.first << " " << p.second;
}
template <class T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
  for (const T &a : arr) out << a << " ";
  return out;
}
template <class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &grid) {
  for (const vector<T> &row : grid) out << row << '\n';
  return out;
}
template <class T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (T &a : arr) in >> a;
  return in;
}
template <class T>
void readIdx(vector<pair<T, int>> &a, int n) {
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
}
template <class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.first >> a.second;
  return in;
}
const bool PRINT_EXEC_TIME = true;
const bool EXTERNAL_INPUT = false;
const bool EXTERNAL_OUTPUT = false;
const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";
void prayGod() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> rows(n);
  for (int i = 0; i < m; i++) {
    int curr_row, l, r;
    cin >> curr_row >> l >> r;
    rows[--curr_row].push_back(make_pair(l, r));
  }
  vector<int> dp(n), backtrack(n, -1);
  iota(dp.begin(), dp.end(), 0);
  for (int i = 0; i < n; i++) {
    sort(rows[i].begin(), rows[i].end());
    vector<pair<int, int>> merged;
    for (pair<int, int> p : rows[i]) {
      if (merged.empty() || p.first > merged.back().second) {
        merged.push_back(p);
      } else {
        merged.back().second = max(merged.back().second, p.second);
      }
    }
    rows[i] = merged;
  }
  auto comp = [&](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.second < b.second.first) return true;
    if (a.second.first > b.second.second) return false;
    if (a.second.first != b.second.first)
      return a.second.first < b.second.first;
    if (a.second.second != b.second.second)
      return a.second.second < b.second.second;
    return a.first < b.first;
  };
  set<pair<int, pair<int, int>>, decltype(comp)> all_segments(comp);
  for (pair<int, int> p : rows[0]) {
    all_segments.insert(make_pair(0, p));
  }
  for (int i = 1; i < n; i++) {
    for (pair<int, int> p : rows[i]) {
      auto it = all_segments.upper_bound(make_pair(i, p));
      if (it == all_segments.begin()) continue;
      it--;
      int row = it->first, start = it->second.first, end = it->second.second;
      if (start > p.second || end < p.first) continue;
      int res = dp[row] + (i - row - 1);
      if (res < dp[i]) {
        dp[i] = res;
        backtrack[i] = row;
      }
    }
    for (pair<int, int> p : rows[i]) {
      auto it = all_segments.lower_bound(make_pair(i, p));
      if (it == all_segments.end()) continue;
      int row = it->first, start = it->second.first, end = it->second.second;
      if (start > p.second || end < p.first) continue;
      int res = dp[row] + (i - row - 1);
      if (res < dp[i]) {
        dp[i] = res;
        backtrack[i] = row;
      }
    }
    for (pair<int, int> p : rows[i]) {
      all_segments.insert(make_pair(i, p));
    }
  }
  for (int i = 0; i < n; i++) {
    dp[i] += (n - 1 - i);
  }
  int best_idx = min_element(dp.begin(), dp.end()) - dp.begin();
  vector<bool> used(n, false);
  function<void(int)> construct = [&](int idx) {
    if (backtrack[idx] != -1) construct(backtrack[idx]);
    used[idx] = true;
  };
  construct(best_idx);
  vector<int> ret;
  for (int i = 0; i < n; i++) {
    if (!used[i]) ret.push_back(i + 1);
  }
  cout << int((ret).size()) << '\n' << ret << '\n';
}
int main() {
  clock_t start = clock();
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  if (EXTERNAL_INPUT) freopen(INPUT_FILE, "r", stdin);
  if (EXTERNAL_OUTPUT) freopen(OUTPUT_FILE, "w", stdout);
  prayGod();
  clock_t end = clock();
  double time_taken = double(end - start) / CLOCKS_PER_SEC;
  if (PRINT_EXEC_TIME)
    cerr << setprecision(5) << fixed << time_taken << " s" << '\n';
}
