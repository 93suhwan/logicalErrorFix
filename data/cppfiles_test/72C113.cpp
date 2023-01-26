#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, MAXN = 5e5 + 5;
const long long LINF = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const double Pi = acos(-1), EPS = 1e-6;
void test() { cerr << "\n"; }
template <typename T, typename... Args>
void test(T x, Args... args) {
  cerr << x << " ";
  test(args...);
}
inline long long qpow(long long a, long long b) {
  return b ? ((b & 1) ? a * qpow(a * a % MOD, b >> 1) % MOD
                      : qpow(a * a % MOD, b >> 1)) %
                 MOD
           : 1;
}
inline long long qpow(long long a, long long b, long long c) {
  return b ? ((b & 1) ? a * qpow(a * a % c, b >> 1, c) % c
                      : qpow(a * a % c, b >> 1, c)) %
                 c
           : 1;
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
inline long long cede(long long a, long long b) {
  if (b < 0) return cede(-a, -b);
  if (a < 0) return a / b;
  return (a + b - 1) / b;
}
inline long long flde(long long a, long long b) {
  if (b < 0) return flde(-a, -b);
  if (a < 0) return (a - b + 1) / b;
  return a / b;
}
inline int sign(double x) { return x < -EPS ? -1 : x > EPS; }
inline int dbcmp(double l, double r) { return sign(l - r); }
namespace Fast_IO {
const int MAXL((1 << 18) + 1);
int iof, iotp;
char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL],
    *iooS = ioof, *iooT = ioof + MAXL - 1, ioc, iost[55];
char Getchar() {
  if (ioiS == ioiT) {
    ioiS = ioif;
    ioiT = ioiS + fread(ioif, 1, MAXL, stdin);
    return (ioiS == ioiT ? EOF : *ioiS++);
  } else
    return (*ioiS++);
}
void Write() {
  fwrite(ioof, 1, iooS - ioof, stdout);
  iooS = ioof;
}
void Putchar(char x) {
  *iooS++ = x;
  if (iooS == iooT) Write();
}
inline int rd() {
  int x = 0;
  for (iof = 1, ioc = Getchar(); (ioc < '0' || ioc > '9') && ioc != EOF;)
    iof = ioc == '-' ? -1 : 1, ioc = Getchar();
  if (ioc == EOF) Write(), exit(0);
  for (x = 0; ioc <= '9' && ioc >= '0'; ioc = Getchar())
    x = (x << 3) + (x << 1) + (ioc ^ 48);
  return x * iof;
}
inline long long read_ll() {
  long long x = 0;
  for (iof = 1, ioc = Getchar(); (ioc < '0' || ioc > '9') && ioc != EOF;)
    iof = ioc == '-' ? -1 : 1, ioc = Getchar();
  if (ioc == EOF) Write(), exit(0);
  for (x = 0; ioc <= '9' && ioc >= '0'; ioc = Getchar())
    x = (x << 3) + (x << 1) + (ioc ^ 48);
  return x * iof;
}
void Getstr(char *s, int &l) {
  for (ioc = Getchar(); ioc != EOF && !isgraph(ioc);) ioc = Getchar();
  if (ioc == EOF) Write(), exit(0);
  for (l = 0; isgraph(ioc); ioc = Getchar()) s[l++] = ioc;
  s[l] = 0;
}
template <class Int>
void Print(Int x, char ch = '\0') {
  if (!x) Putchar('0');
  if (x < 0) Putchar('-'), x = -x;
  while (x) iost[++iotp] = x % 10 + '0', x /= 10;
  while (iotp) Putchar(iost[iotp--]);
  if (ch) Putchar(ch);
}
void Putstr(const char *s) {
  for (int i = 0; s[i]; ++i) Putchar(s[i]);
}
}  // namespace Fast_IO
using namespace Fast_IO;
int vis[20], vis1[20];
void run() {
  memset(vis, 0, sizeof vis);
  memset(vis1, 0, sizeof vis1);
  int n, k;
  cin >> n >> k;
  set<int> st;
  string s = to_string(n);
  for (int i = 0; i < s.size(); ++i) {
    if (!vis[s[i] - '0']) st.insert(s[i] - '0');
    vis[s[i] - '0']++;
    if (st.size() == k) break;
  }
  int tmp = 0, ff = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (!ff && !vis[s[i] - '0']) {
      auto pos = st.lower_bound(s[i] - '0');
      if (pos == st.end()) {
        int j;
        for (j = i - 1; j >= 0; --j) {
          vis1[s[j] - '0']--;
          auto pos = st.lower_bound(s[j] - '0' + 1);
          if (vis1[s[j] - '0'] == 0) {
            tmp /= 10;
            st.erase(s[j] - '0');
            st.insert(s[j] - '0' + 1);
            tmp = tmp * 10 + (s[j] - '0' + 1);
            if ((int)st.size() < k) st.insert(0);
            break;
          }
          if (pos != st.end()) {
            tmp /= 10;
            tmp = tmp * 10 + (*pos);
            break;
          }
          tmp /= 10;
        }
        for (; j < i; ++j) tmp = tmp * 10 + (*st.begin());
      } else {
        tmp = tmp * 10 + *(pos);
      }
      ff = 1;
      continue;
    }
    if (!ff)
      tmp = tmp * 10 + s[i] - '0';
    else
      tmp = tmp * 10 + (*st.begin());
    vis1[s[i] - '0']++;
  }
  cout << tmp << '\n';
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int _;
  cin >> _;
  while (_--) run();
  return 0;
}
