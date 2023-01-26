#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '[';
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <class T>
T ABS(const T &x) {
  return x > 0 ? x : -x;
}
long long int gcd(long long int n1, long long int n2) {
  return n2 == 0 ? ABS(n1) : gcd(n2, n1 % n2);
}
long long int lcm(long long int n1, long long int n2) {
  return n1 == 0 && n2 == 0 ? 0 : ABS(n1 * n2) / gcd(n1, n2);
}
long long int ceil2(long long int a, long long int b) {
  return (a + b - 1) / b;
}
template <typename T>
bool chmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool chmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
vector<T> sorttrunq(vector<T> vec) {
  sort(vec.begin(), vec.end()),
      vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (auto &s : grid) cin >> s;
  vector<int> sum(m, 0);
  for (int c = 1; c < m; ++c) {
    int cnt = 0;
    for (int r = 1; r < n; ++r) {
      if (grid[r][c - 1] == 'X' && grid[r - 1][c] == 'X') ++cnt;
    }
    sum[c] = sum[c - 1] + cnt;
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int s = sum[r];
    if (l > 0) s -= sum[l];
    !s ? cout << "YES\n" : cout << "NO\n";
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
