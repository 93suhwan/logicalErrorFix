#include <bits/stdc++.h>
using namespace std;
const long long sz = 1e5 + 10;
const long long inf = 0x3f3f3f3f;
inline long long read() {
  long long f = 1, x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
  return f * x;
}
void print(long long *z, long long n) {
  for (long long i = 1; i <= n; i++) printf("%d  ", z[i]);
  puts("");
}
string sa, sb;
long long cnt[sz];
long long n, m;
long long mx;
vector<vector<long long> > p;
long long z[sz];
bool check(long long one, long long two, long long val) {
  for (long long i = 0; i <= one; i++) {
    for (long long j = 0; j <= two; j++) {
      if (val < i + j * 2) continue;
      if ((val - i - j * 2) % 3 == 0) {
        return 1;
      }
    }
  }
  return 0;
}
long long check(long long one, long long two) {
  for (long long i = 1; i <= n; i++) {
    bool can = check(one, two, z[i]);
    if (!can) return inf;
  }
  return one + two + (mx - one - two * 2 + 2) / 3;
}
void solve() {
  n = read();
  mx = 0;
  for (long long i = 1; i <= n; i++) {
    z[i] = read();
    mx = max(mx, z[i]);
  }
  long long mn = inf;
  for (long long one = 0; one <= 2; one++) {
    for (long long two = 0; two <= 2; two++) {
      mn = min(mn, check(one, two));
    }
  }
  cout << mn << endl;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
