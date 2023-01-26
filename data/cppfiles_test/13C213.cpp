#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (auto& v : vec) is >> v;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[ ";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[ ";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[ ";
  for (auto it : v) os << it << ", ";
  os << " ]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  os << "{ ";
  for (auto it : v) os << it.first << " : " << it.second << ", ";
  os << " }\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, priority_queue<T> p) {
  os << "[ ";
  while (!p.empty()) {
    os << p.top() << " ,";
    p.pop();
  }
  os << " ]\n";
  return os;
}
const long long INF = 1e18;
const long long mod = 1e9 + 7;
inline long long pmod(long long i, long long n = mod) {
  return (i % n + n) % n;
}
inline long long cdiv(long long a, long long b) { return (a + b - 1) / b; }
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long N = n, M = m;
  vector<vector<char>> ans(n, vector<char>(m, 0));
  if (n & 1) {
    if (k < m / 2) {
      cout << "NO\n";
      return;
    };
    bool f = 1;
    for (long long i = 0; i + 1 < m; i += 2)
      ans[0][i] = ans[0][i + 1] = (f ? 'a' : 'b'), f ^= 1;
    k -= m / 2;
    --n;
  }
  if (m & 1) {
    bool f = 1;
    for (long long i = 0; i + 1 < n; i += 2)
      ans[i][m - 1] = ans[i + 1][m - 1] = (f ? 'a' : 'b'), f ^= 1;
    --m;
  }
  if (k <= n * m / 2 && k % 2 == 0) {
    cout << "YES\n";
    long long rs = 0, ce = M - 1, cs = 0;
    if (N & 1) ++rs;
    if (m & 1) --ce;
    auto fit = [&](long long r, long long c1, long long c2) {
      char ch = 'a';
      auto chk = [&](long long r, long long c) {
        return (r >= 0 && r < N && c >= 0 && c < M);
      };
      while ((chk(r - 1, c1) && ans[r - 1][c1] == ch) ||
             (chk(r - 1, c2) && ans[r - 1][c2] == ch) ||
             (chk(r + 1, c1) && ans[r + 1][c1] == ch) ||
             (chk(r + 1, c2) && ans[r + 1][c2] == ch) ||
             (chk(r, c1 - 1) && ans[r][c1 - 1] == ch) ||
             (chk(r, c2 + 1) && ans[r][c2 + 1] == ch))
        ++ch;
      ans[r][c1] = ans[r][c2] = ch;
    };
    auto fitt = [&](long long r1, long long r2, long long c) {
      char ch = 'a';
      auto chk = [&](long long r, long long c) {
        return (r >= 0 && r < N && c >= 0 && c < M);
      };
      while ((chk(r1 - 1, c) && ans[r1 - 1][c] == ch) ||
             (chk(r2 + 1, c) && ans[r2 + 1][c] == ch) ||
             (chk(r1, c - 1) && ans[r1][c - 1] == ch) ||
             (chk(r1, c + 1) && ans[r1][c + 1] == ch) ||
             (chk(r2, c - 1) && ans[r2][c - 1] == ch) ||
             (chk(r2, c + 1) && ans[r2][c + 1] == ch))
        ++ch;
      ans[r1][c] = ans[r2][c] = ch;
    };
    for (cs = 0; k && cs < ce; cs += 2) {
      for (long long r = rs; k && r < N; r += 2) {
        fit(r, cs, cs + 1);
        fit(r + 1, cs, cs + 1);
        k -= 2;
      }
    }
    for (long long(i) = (0); (i) <= (N - 1); ++(i))
      for (long long(j) = (0); (j) <= (M - 1); ++(j)) {
        if (!ans[i][j]) fitt(i, i + 1, j);
      }
    for (auto&(e) : (ans)) {
      for (auto&(f) : (e)) cout << f;
      cout << '\n';
    }
  } else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int t1 = 1; t1 <= t; ++t1) {
    solve();
  }
}
