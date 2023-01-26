#include <bits/stdc++.h>
std::mt19937_64 gen(
    std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937 gen1(std::chrono::steady_clock::now().time_since_epoch().count());
int rng(int l, int r) { return std::uniform_int_distribution<int>(l, r)(gen); }
const long double PI = atan(1.0) * 4;
const int32_t INF32 = 2e9 + 7;
const int64_t INF64 = 3e18;
const int32_t LOG = 21;
int32_t MOD = 1e9 + 7;
using namespace std;
void my_debugger(string second, int LINE_NUM) { cerr << '\n'; }
template <typename start, typename... end>
void my_debugger(string second, int LINE_NUM, start x, end... y) {
  if (second.back() != ',') {
    second += ',';
    cerr << "LINE(" << LINE_NUM << "): ";
  }
  int i = second.find(',');
  cerr << second.substr(0, i) << " = " << x;
  second = second.substr(i + 1);
  if (!second.empty()) cerr << ", ";
  my_debugger(second, LINE_NUM, y...);
}
void setMod(int mod_val) { MOD = mod_val; }
void files_init() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);
}
const int N = 1e6 + 5;
const int LOGN = 20;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tests = 1;
  for (int ii = 0; ii < (int)tests; ii++) {
    int n, q;
    cin >> n >> q;
    int BLOCK = sqrt(n + 0.5);
    vector<int> a(n + 1);
    for (int i = 1; i < (int)n + 1; i++) cin >> a[i];
    vector<int> nxt(n + 1), prev(n + 1), nxtBlock(n + 1);
    for (int i = 1; i < (int)n + 1; i++) {
      nxt[i] = a[i];
      prev[a[i]] = i;
    }
    for (int i = 1; i < (int)n + 1; i++) {
      int cur = i;
      for (int j = 0; j < (int)BLOCK; j++) cur = nxt[cur];
      nxtBlock[i] = cur;
    }
    for (int query = 0; query < (int)q; query++) {
      int type;
      cin >> type;
      if (type == 1) {
        int x, y;
        cin >> x >> y;
        nxt[x] = a[y];
        nxt[y] = a[x];
        prev[a[y]] = x;
        prev[a[x]] = y;
        {
          vector<int> vals;
          int cur = x;
          for (int i = 0; i < (int)BLOCK; i++) {
            cur = nxt[cur];
            vals.push_back(cur);
          }
          cur = x;
          int ptr = vals.size() - 1;
          for (int i = 0; i < (int)BLOCK; i++) {
            nxtBlock[cur] = vals[ptr];
            ptr--;
            cur = prev[cur];
          }
        }
        {
          vector<int> vals;
          int cur = y;
          for (int i = 0; i < (int)BLOCK; i++) {
            cur = nxt[cur];
            vals.push_back(cur);
          }
          cur = y;
          int ptr = vals.size() - 1;
          for (int i = 0; i < (int)BLOCK; i++) {
            nxtBlock[cur] = vals[ptr];
            ptr--;
            cur = prev[cur];
          }
        }
      } else {
        int i, k;
        cin >> i >> k;
        int blocks = k / BLOCK;
        int rem = k % BLOCK;
        int cur = i;
        for (int i = 0; i < (int)blocks; i++) cur = nxtBlock[cur];
        for (int i = 0; i < (int)rem; i++) cur = nxt[cur];
        cout << cur << '\n';
      }
    }
  }
  return 0;
}
