#include <bits/stdc++.h>
using namespace std;
const int INF = (is_same<int, long long>::value ? 1e18 + 666 : 1e9 + 666);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
inline int bpow(long long a, long long b, int mod) {
  int res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = int((1ll * a * res) % mod);
      res %= mod;
    }
    a *= a;
    a %= mod;
  }
  return res;
}
void UseFiles(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void run();
signed main() {
  iostream::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  run();
}
void solve();
void run() {
  int n;
  cin >> n;
  while (n-- > 0) {
    solve();
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  map<int, vector<int>> pos;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    pos[v].push_back(i);
  }
  vector<int> positions;
  for (auto &[v, p] : pos) {
    while (((int)(p).size()) > k) {
      p.pop_back();
    }
    for (auto &x : p) {
      positions.push_back(x);
    }
  }
  vector<int> clr(n, -1);
  for (int i = 0; i + k <= ((int)(positions).size()); i += k) {
    for (int j = 0; j < k; ++j) {
      clr[positions[i + j]] = j;
    }
  }
  for (auto &c : clr) {
    cout << c + 1 << " ";
  }
  cout << endl;
}
