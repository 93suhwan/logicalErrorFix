#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
namespace IO {
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  int f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  x *= f;
}
};  // namespace IO
using namespace IO;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = a[0];
  for (auto &x : a) ans &= x;
  cout << ans << '\n';
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return (0 - 0);
}
