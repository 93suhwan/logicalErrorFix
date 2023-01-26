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
long long int power(long long int x, long long int y, long long int mod = MOD) {
  if (y == 0) return 1;
  long long int temp = power(x, y / 2);
  temp = (1LL * temp * temp) % mod;
  if (y & 1) temp = (1LL * temp * x) % mod;
  return temp;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long int tests = 1;
  cin >> tests;
  for (long long int ii = 0; ii < (long long int)tests; ii++) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> id(2 * n + 1);
    vector<pair<long long int, long long int> > lines;
    vector<bool> check(2 * n + 1);
    for (long long int i = 1; i < (long long int)k + 1; i++) {
      long long int x, y;
      cin >> x >> y;
      lines.push_back({x, y});
      check[x] = check[y] = true;
    }
    vector<long long int> vals;
    for (long long int i = 1; i < (long long int)2 * n + 1; i++) {
      if (!check[i]) {
        vals.push_back(i);
      }
    }
    long long int shift = vals.size();
    shift /= 2;
    for (long long int i = 0; i < (long long int)shift; i++)
      lines.push_back({vals[i], vals[i + shift]});
    long long int ans = 0;
    long long int line_no = 1;
    for (auto& [second, e] : lines) {
      long long int cur = second + 1;
      if (cur > 2 * n) cur = 1;
      vector<long long int> cnt(n + 1);
      while (cur != e) {
        cnt[id[cur]]++;
        if (id[cur] && cnt[id[cur]] == 2)
          ans--;
        else if (id[cur])
          ans++;
        cur++;
        if (cur > 2 * n) cur = 1;
      }
      id[second] = id[e] = line_no;
      line_no++;
    }
    cout << ans << '\n';
  }
  return 0;
}
