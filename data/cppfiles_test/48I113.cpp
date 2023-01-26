#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
template <typename T>
T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <typename T>
void chkmax(T &x, const T &y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = x < y ? x : y;
}
const int N = 1e6 + 10;
int tr[N], a[N], n;
void add(int x, int v) {
  for (; x <= n; x += x & -x) tr[x] += v;
}
int query(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += tr[x];
  return res;
}
void solve() {
  n = read<int>();
  for (int i = (1); i <= (n); i++) a[i] = read<int>();
  for (int i = (1); i <= (n); i++) tr[i] = 0;
  ll res = 0;
  for (int i = (1); i <= (n); i++) {
    res += i - 1 - query(a[i]);
    add(a[i], 1);
  }
  puts(res % 3 == 1 ? "NO" : "YES");
}
int main() {
  int T = read<int>();
  while (T--) solve();
  return 0;
}
