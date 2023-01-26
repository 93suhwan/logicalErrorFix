#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0, j = 0; i < v.size(); i++, j++)
    if (j >= 5) {
      j = 0;
      puts("");
    } else
      os << v[i] << " ";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (auto c : v) os << c << " ";
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& v) {
  for (auto c : v) os << c.first << " " << c.second << '\n';
  return os;
}
template <typename T>
inline void rd(T& a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
const int N = 1e5 + 10, M = 1e9 + 7;
long long n, m, _;
bool st[N];
void solve() {
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) st[i] = 0;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    st[b] = 1;
  }
  int pos = -1;
  for (int i = 1; i <= n; i++) {
    if (!st[i]) {
      pos = i;
      break;
    }
  }
  for (int i = (1); i <= (n); ++i) {
    if (pos == i) continue;
    cout << i << " " << pos << '\n';
  }
}
int main() {
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
