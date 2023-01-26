#include <bits/stdc++.h>
using namespace std;
int n, m;
int rb, cb, rd, cd;
int dx, dy;
long long p;
const long long mod = 1e9 + 7;
long long exp_mod(long long b, long long e) {
  long long r = 1;
  while (e > 0) {
    if (e & 1) r = r * b % mod;
    b = b * b % mod;
    e >>= 1;
  }
  return r;
}
long long inverse(long long x) { return exp_mod(x, mod - 2); }
void move(int &a, int &b) {
  if (a + dx > n || a + dx <= 0) dx = -dx;
  if (b + dy > m || b + dy <= 0) dy = -dy;
  a += dx;
  b += dy;
}
bool clean(int a, int b) {
  if (a == rd || b == cd) return true;
  return false;
}
void solve() {
  cin >> n >> m;
  cin >> rb >> cb >> rd >> cd >> p;
  p = (1 - p * inverse(100) % mod + mod) % mod;
  dx = 1, dy = 1;
  int r = rb, c = cb;
  vector<long long> v;
  for (int i = 0; i < 4 * (n - 1) * (m - 1); i++) {
    if (clean(r, c))
      v.push_back(p);
    else
      v.push_back(1);
    move(r, c);
  }
  long long a = 1, b = 0;
  for (int i = v.size() - 1; i >= 0; i--) {
    b += 1;
    b = b * v[i] % mod;
    a = a * v[i] % mod;
  }
  a = (1 - a + mod) % mod;
  long long x = (b * inverse(a)) % mod;
  cout << x << "\n";
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
