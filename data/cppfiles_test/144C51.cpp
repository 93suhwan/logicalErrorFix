#include <bits/stdc++.h>
using namespace std;
template <typename T>
void rd(T& x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) f ^= !(c ^ 45);
  x = (c & 15);
  while (isdigit(c = getchar())) x = x * 10 + (c & 15);
  if (f) x = -x;
}
template <typename T>
void pt(T x, int c = 10) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) pt(x / 10, -1);
  putchar(x % 10 + 48);
  if (c != -1) putchar(c);
}
template <typename T>
void umax(T& x, const T& y) {
  if (x < y) x = y;
}
template <typename T>
void umin(T& x, const T& y) {
  if (x > y) x = y;
}
using vi = vector<int>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long, long>;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int last, h;
int n, m, k;
void show(int d) {
  cout << d;
  while (d--) {
    cout << " " << h;
    h++;
    if (h > n) h = 1;
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    int x = (n + m - 1) / m, y = n / m;
    int r = n % m;
    last = 1;
    while (k--) {
      h = last;
      for (int i = 1; i <= r; i++) show(x);
      last = h;
      for (int i = 1; i <= m - r; i++) show(y);
    }
    cout << "\n";
  }
  return 0;
}
