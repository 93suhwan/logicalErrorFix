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
  long long n, c10 = 0, c01 = 0, e00 = 0, e11 = 0, ans = INF;
  string s, t;
  cin >> n >> s >> t;
  if (s == t) {
    cout << 0;
    return;
  }
  for (long long(i) = (0); (i) <= (n - 1); ++(i)) {
    if (s[i] == '0' && t[i] == '0')
      ++e00;
    else if (s[i] == '1' && t[i] == '1')
      ++e11;
    else if (s[i] == '0' && t[i] == '1')
      ++c01;
    else
      ++c10;
  }
  long long a = c10, b = c01, c = e00, d = e11;
  for (long long(i) = (1); (i) <= (max(3 * n, 20ll)); ++(i)) {
    if (i & 1 && e11) {
      long long C10 = e00, C01 = e11 - 1;
      e00 = c10;
      e11 = c01 + 1;
      c10 = C10;
      c01 = C01;
      if (!c01 && !c10) {
        ans = min(ans, i);
        break;
      }
    } else if (i % 2 == 0 && c10) {
      long long C10 = e00 + 1, C01 = e11;
      e00 = c10 - 1;
      e11 = c01;
      c10 = C10;
      c01 = C01;
      if (!c01 && !c10) {
        ans = min(ans, i);
        break;
      }
    } else
      break;
  }
  c10 = a;
  c01 = b;
  e00 = c;
  e11 = d;
  for (long long(i) = (1); (i) <= (max(3 * n, 20ll)); ++(i)) {
    if (i % 2 == 0 && e11) {
      long long C10 = e00, C01 = e11 - 1;
      e00 = c10;
      e11 = c01 + 1;
      c10 = C10;
      c01 = C01;
      if (!c01 && !c10) {
        ans = min(ans, i);
        break;
      }
    } else if (i & 1 && c10) {
      long long C10 = e00 + 1, C01 = e11;
      e00 = c10 - 1;
      e11 = c01;
      c10 = C10;
      c01 = C01;
      if (!c01 && !c10) {
        ans = min(ans, i);
        break;
      }
    } else
      break;
  }
  if (ans == INF)
    cout << -1;
  else
    cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int t1 = 1; t1 <= t; ++t1) {
    solve();
    cout << '\n';
  }
}
