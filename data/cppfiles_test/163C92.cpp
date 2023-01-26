#include <bits/stdc++.h>
using namespace std;
void io(string in = "", string out = "", string err = "") {
  if (fopen(in.c_str(), "r")) {
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
  }
}
void conv();
int main() {
  io(""
     ".inp",
     ""
     ".out");
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int Q = 1;
  cin >> Q;
  while (Q--) {
    conv();
  }
  return 0;
}
const int md = (int)1e9 + 7;
int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  if (a < 0) a += md;
  return a;
}
int mul(int a, int b) { return (unsigned long long)a * b % md; }
int binpow(int a, int n) {
  int res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
  }
  return res;
}
int inv(int a) { return binpow(a, md - 2); }
void conv() {
  int n, m, a, b, c, d, p;
  cin >> n >> m >> a >> b >> c >> d >> p;
  vector<pair<int, int>> tr;
  int dx = 1, dy = 1;
  for (int t = 2 * (n - 1) * (m - 1); t--;) {
    tr.emplace_back(a, b);
    if (a + dx < 1 || a + dx > n) dx = -dx;
    if (b + dy < 1 || b + dy > m) dy = -dy;
    a += dx;
    b += dy;
  }
  int x = 1, y = 0, p_ = mul(100 - p, inv(100));
  reverse(tr.begin(), tr.end());
  for (auto [x_, y_] : tr) {
    y = add(y, 1);
    if (x_ == c || y_ == d) {
      x = mul(x, p_);
      y = mul(y, p_);
    }
  }
  cout << mul(y, inv(add(1, -x))) << '\n';
}
