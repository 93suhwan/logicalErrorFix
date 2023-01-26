#include <bits/stdc++.h>
std::mt19937_64 gen(
    std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937 gen1(std::chrono::steady_clock::now().time_since_epoch().count());
long long int rng(long long int l, long long int r) {
  return std::uniform_int_distribution<long long int>(l, r)(gen);
}
const long double PI = atan(1.0) * 4;
const int32_t INF32 = 2e9 + 7;
const int64_t INF64 = 3e18;
const int32_t LOG = 21;
int32_t MOD = 1e9 + 7;
using namespace std;
void my_debugger(string second, long long int LINE_NUM) { cerr << '\n'; }
template <typename start, typename... end>
void my_debugger(string second, long long int LINE_NUM, start x, end... y) {
  if (second.back() != ',') {
    second += ',';
    cerr << "LINE(" << LINE_NUM << "): ";
  }
  long long int i = second.find(',');
  cerr << second.substr(0, i) << " = " << x;
  second = second.substr(i + 1);
  if (!second.empty()) cerr << ", ";
  my_debugger(second, LINE_NUM, y...);
}
void setMod(long long int mod_val) { MOD = mod_val; }
void files_init() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);
}
const long long int N = 1e6 + 5;
const long long int LOGN = 20;
void cyclic_shift(deque<long long int>& dq, long long int x) {
  for (long long int i = 0; i < (long long int)x; i++) {
    dq.push_front(dq.back());
    dq.pop_back();
  }
}
void print(const deque<long long int>& dq, const vector<long long int>& table,
           long long int m) {
  vector<vector<long long int>> vals(m + 1);
  for (long long int i = 0; i < (long long int)dq.size(); i++) {
    vals[table[i]].push_back(dq[i]);
  }
  for (long long int i = 1; i < (long long int)m + 1; i++) {
    cout << vals[i].size();
    for (auto it : vals[i]) cout << " " << it + 1;
    cout << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long int tests = 1;
  cin >> tests;
  for (long long int ii = 0; ii < (long long int)tests; ii++) {
    long long int n, m, k;
    cin >> n >> m >> k;
    long long int rem = n % m;
    long long int start = (rem + rem * (n / m));
    long long int cur = 0;
    vector<long long int> table(n);
    long long int cur_table = 1;
    while (cur < start) {
      for (long long int i = 0; i < (long long int)(n / m) + 1; i++)
        table[cur + i] = cur_table;
      cur += (n / m) + 1;
      cur_table++;
    }
    while (cur < n) {
      for (long long int i = 0; i < (long long int)(n / m); i++)
        table[cur + i] = cur_table;
      cur += (n / m);
      cur_table++;
    }
    deque<long long int> dq;
    for (long long int i = 0; i < (long long int)n; i++) dq.push_back(i);
    long long int shift = start;
    for (long long int game = 0; game < (long long int)k; game++) {
      print(dq, table, m);
      cyclic_shift(dq, shift);
    }
    cout << '\n';
  }
  return 0;
}
