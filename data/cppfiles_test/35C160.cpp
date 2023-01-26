#include <bits/stdc++.h>
using namespace std;
void dbg() { std::cout << "  #\n"; }
template <typename T, typename... Args>
void dbg(T a, Args... args) {
  std::cout << a << ' ';
  dbg(args...);
}
const long long maxn = 2e5 + 10;
const long long MAX = 1000;
const long long inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
long long n, m;
long long a[maxn];
long long b[maxn];
long long getint() {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  long long x = ch - 48;
  while (isdigit(ch = getchar())) x = x * 10 + ch - 48;
  return x;
}
void solve() {
  n = getint();
  m = getint();
  long long p = m + 1;
  long long ans = 0;
  for (long long i = (30); i >= (0); --i) {
    long long tmp = 1ll << i;
    if (((n & tmp) && (p & tmp)) || (!(n & tmp) && !(p & tmp))) {
      continue;
    } else if (!(n & tmp) && (p & tmp)) {
      ans |= tmp;
    } else {
      break;
    }
  }
  cout << (ans) << endl;
}
signed main() {
  long long TestCase = 1;
  cin >> TestCase;
  while (TestCase--) {
    solve();
  }
  char EndFile = getchar();
  EndFile = getchar();
  return 0;
}
