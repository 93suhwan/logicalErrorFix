#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) in >> x;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (auto &x : v) out << x << ' ';
  return out;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
long long n, m;
vector<vector<long long> > a;
long long solve(long long x, long long y) {
  long long ans = 0;
  long long c1 = 0, c2 = 0;
  pair<long long, long long> p = {x, y};
  bool turn = 1;
  while (true) {
    if (turn)
      p.first--;
    else
      p.second--;
    turn = 1 - turn;
    if (p.first < 0 || p.second < 0) break;
    if (a[p.first][p.second] == 1) break;
    c1++;
  }
  p = {x, y};
  turn = 1;
  while (true) {
    if (turn)
      p.second++;
    else
      p.first++;
    turn = 1 - turn;
    if (p.first >= n || p.second >= m) break;
    if (a[p.first][p.second] == 1) break;
    c2++;
  }
  ans += c2 * c1 + c1 + c2;
  c1 = 0, c2 = 0;
  p = {x, y};
  turn = 1;
  while (true) {
    if (turn)
      p.second--;
    else
      p.first--;
    turn = 1 - turn;
    if (p.first < 0 || p.second < 0) break;
    if (a[p.first][p.second] == 1) break;
    c2++;
  }
  p = {x, y};
  turn = 1;
  while (true) {
    if (turn)
      p.first++;
    else
      p.second++;
    turn = 1 - turn;
    if (p.first >= n || p.second >= m) break;
    if (a[p.first][p.second] == 1) break;
    c1++;
  }
  ans += c2 * c1 + c1 + c2;
  return ans;
}
long long nC2(long long x) { return x * (x - 1) / 2; }
long long calc() {
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    if (n >= m - i)
      ans += nC2(2 * (m - i - 1) + 1);
    else
      ans += nC2(2 * n);
  }
  swap(n, m);
  for (int i = 0; i < m; i++) {
    if (n >= m - i)
      ans += nC2(2 * (m - i - 1) + 1);
    else
      ans += nC2(2 * n);
  }
  swap(n, m);
  return ans;
}
const bool tests = 0;
void solve_case() {
  long long q;
  cin >> n >> m >> q;
  a.resize(n, vector<long long>(m, 0));
  long long ans = calc();
  long long cnt = n * m;
  for (int i = 0; i < q; i++) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    long long temp = solve(x, y);
    cnt += (a[x][y] == 0 ? -1 : 1);
    if (a[x][y] == 1)
      ans += temp;
    else
      ans -= temp;
    cout << ans + cnt << "\n";
    a[x][y] = 1 - a[x][y];
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long testcase = 1;
  if (tests) cin >> testcase;
  cout << fixed << setprecision(10);
  for (long long test = 1; test <= testcase; test++) {
    solve_case();
  }
  return 0;
}
