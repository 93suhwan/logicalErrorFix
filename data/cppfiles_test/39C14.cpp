#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
int n, m;
int a[MAXN], p[MAXN];
template <typename T>
inline bool read(T &a) {
  a = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = a * 10 + (c ^ 48);
    c = getchar();
  }
  return a *= f, true;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
int ask() {
  int res = 0;
  cout << "? ";
  for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << '\n';
  cin >> res;
  return res;
}
signed main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) a[i] = n;
  a[n] = 1;
  for (int i = 1; i <= n; ++i) {
    if (ask()) {
      p[n] = n - i + 1;
      break;
    }
    for (int j = 1; j < n; ++j) a[j]--;
  }
  if (!p[n]) p[n] = 1;
  for (int i = 1; i < n; ++i) a[i] = p[n];
  a[n] = 0;
  for (int i = 1, k; i <= n; ++i) {
    if (p[n] == i) continue;
    a[n] = i;
    k = ask();
    assert(k);
    p[k] = i;
  }
  cout << "! ";
  for (int i = 1; i <= n; ++i) cout << p[i] << ' ';
  cout << '\n';
  return 0;
}
