#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve();
void warm_up();
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  warm_up();
  int q;
  cin >> q;
  while (q--) solve();
  return 0;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (const T &e : v) out << e << " ";
  return out;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (T &e : v) {
    in >> e;
  }
  return in;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T, typename _>
ostream &operator<<(ostream &out, const set<T, _> &s) {
  for (const T &e : s) out << e << " ";
  return out;
}
void warm_up() {}
using Pos = pair<int, int>;
const ll MOD = 1e9 + 7;
ll pw(ll n, ll k) {
  if (k == 0) return 1;
  ll p = pw(n, k / 2);
  if (k % 2 == 0) {
    return p * p % MOD;
  } else {
    return p * p % MOD * n % MOD;
  }
}
struct Mod {
  ll x;
  Mod(ll x) : x((x + MOD * 1000) % MOD) {}
  friend Mod operator+(Mod l, Mod r) { return ((l.x + r.x) % MOD); }
  friend Mod operator-(Mod l, Mod r) { return ((l.x - r.x + MOD) % MOD); }
  friend Mod operator*(Mod l, Mod r) { return ((l.x * r.x) % MOD); }
  [[nodiscard]] Mod inv() const { return (::pw(x, MOD - 2)); }
  [[nodiscard]] Mod pw(int p) const { return (::pw(x, p)); }
  friend Mod operator/(Mod l, Mod r) { return (l * r.inv()); }
  friend ostream &operator<<(ostream &out, Mod m) {
    out << m.x;
    return out;
  }
};
void solve() {
  int n, m, p_proc;
  Pos robot, dirt;
  cin >> n >> m >> robot >> dirt >> p_proc;
  robot.first--, robot.second--, dirt.first--, dirt.second--;
  vector<vector<bitset<4>>> path(n, vector<bitset<4>>(m, 0));
  int loop_size = 0;
  vector<int> times;
  int dr = 1, dc = 1;
  auto dir_to_int = [&]() { return (dr != 1) * 2 + (dc != 1); };
  if (dr == 1 && robot.first == n - 1) dr = -1;
  if (dr == -1 && robot.first == 0) dr = 1;
  if (dc == 1 && robot.second == m - 1) dc = -1;
  if (dc == -1 && robot.second == 0) dc = 1;
  while (!(path.operator[]((robot).first)[(robot).second][dir_to_int()])) {
    path.operator[]((robot).first)[(robot).second][dir_to_int()] = true;
    if (robot.first == dirt.first || robot.second == dirt.second) {
      times.push_back(loop_size);
    }
    loop_size++;
    robot.first += dr;
    robot.second += dc;
    if (dr == 1 && robot.first == n - 1) dr = -1;
    if (dr == -1 && robot.first == 0) dr = 1;
    if (dc == 1 && robot.second == m - 1) dc = -1;
    if (dc == -1 && robot.second == 0) dc = 1;
  }
  (times);
  (loop_size);
  Mod p = p_proc / Mod(100);
  Mod expected = 0;
  int k = (int)times.size();
  Mod not_p_loop = (1 - p).pw(k);
  for (int i = 0; i < k; i++) {
    Mod a = (loop_size - times[i]) * not_p_loop + times[i];
    Mod b = (not_p_loop - 1);
    expected = expected + p * (1 - p).pw(i) * a / (b * b);
  }
  (expected);
}
