#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
const long double EPS = 1e-7;
const int MOD = 1e9 + 7;
int POW(int b, int e) {
  int r = 1;
  while (e) {
    if (e % 2 == 1) {
      r *= b;
      r %= MOD;
    }
    e /= 2;
    b *= b;
    b %= MOD;
  }
  return r;
}
int gcd(int a, int b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
int INV(int a) { return POW(a, MOD - 2); }
vector<vector<bool>> table(5001, vector<bool>(8192, false));
vector<vector<int>> upd(5001);
void setv(int a, int b) {
  if (!table[a][b]) {
    table[a][b] = true;
    if (a) {
      setv(a - 1, b);
    }
    upd[a].push_back(b);
  }
}
void roll(int a) {
  while (!upd[a].empty()) {
    setv(a - 1, upd[a].back() ^ a);
    upd[a].pop_back();
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= 5000; i++) {
    setv(i, 0);
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > 0) roll(a[i]);
  }
  vector<int> out;
  for (int i = 0; i < 8192; i++) {
    if (table[0][i]) {
      out.push_back(i);
    }
  }
  cout << (int)out.size() << '\n';
  for (auto v : out) {
    cout << v << ' ';
  }
}
