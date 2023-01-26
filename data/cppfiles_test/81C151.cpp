#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int> > PIII;
const int INF = INT_MAX;
const long long INFF = INT64_MAX;
const int mod = 1e9 + 7;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int lowbit(int x) { return x & -x; }
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline long long ksm(long long a, long long b) {
  if (b == 0) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1) ns = ns * a % mod;
  return ns;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline void out(bool flag);
template <typename T>
inline void read(T &x) {
  x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    f ^= !(ch ^ 45);
    ch = getchar();
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
  x = f ? -x : x;
}
inline void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    char cc;
    cin >> cc;
    if (cc == '+')
      a[i] = 1;
    else
      a[i] = -1;
  }
  for (register int i = (1); i <= (n); ++i) {
    if (i % 2 == 1)
      s[i] = s[i - 1] + a[i];
    else
      s[i] = s[i - 1] - a[i];
  }
  for (register int i = (1); i <= (m); ++i) {
    int l, r;
    cin >> l >> r;
    int t = abs(s[r] - s[l - 1]);
    if (!t)
      cout << 0;
    else if (t & 1)
      cout << 1;
    else
      cout << 2;
    cout << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
inline void out(bool flag) {
  if (flag)
    puts("YES");
  else
    puts("NO");
}
