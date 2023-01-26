#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') w = -1;
  for (; isdigit(ch); ch = getchar()) s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * w;
}
inline void print(long long x, int op = 10) {
  if (!x) {
    putchar('0');
    if (op) putchar(op);
    return;
  }
  char F[40];
  long long tmp = x > 0 ? x : -x;
  if (x < 0) putchar('-');
  int cnt = 0;
  while (tmp > 0) {
    F[cnt++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (cnt > 0) putchar(F[--cnt]);
  if (op) putchar(op);
}
inline long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    b >>= 1;
    a *= a;
  }
  return ans;
}
long long qpow(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= mod;
    b >>= 1;
    (a *= a) %= mod;
  }
  return ans % mod;
}
const int dir[][2] = {{0, 1}, {1, 0},  {0, -1}, {-1, 0},
                      {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 7;
struct Node {
  long long val;
  int id;
  bool operator<(const Node& opt) const { return val < opt.val; }
};
long long n, m;
set<int> st;
int p[20];
int solve() {
  n = read();
  int cnt = 0;
  for (int i = 1; i <= n; ++i) p[i] = read(), cnt += p[i] == 0;
  st.clear();
  st.insert(0);
  for (int i = 1; i <= n; ++i) {
    set<int> tmp = st;
    for (auto& it : st) {
      int x1 = it - p[i];
      int x2 = it + p[i];
      cnt += x1 == 0;
      cnt += x2 == 0;
      tmp.insert(x1), tmp.insert(x2);
    }
    st = tmp;
  }
  return cnt;
}
int main() {
  int T = read();
  for (int _ = 1; _ <= T; ++_) {
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
