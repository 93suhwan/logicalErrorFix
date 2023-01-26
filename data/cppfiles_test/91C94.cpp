#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long a = 0, po = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') po = -1, ch = getchar();
  while (isdigit(ch)) a = (a << 1) + (a << 3) + ch - 48, ch = getchar();
  return a * po;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
const long long maxn = 100010;
const long long mod = 998244353;
struct nowt {
  long long t, cy, cc;
};
void work() {
  vector<nowt> N, N1;
  long long n = read();
  long long tot = 0;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    a[i] = read();
  }
  N1.push_back({1, a[n - 1], n});
  for (long long i = n - 2; i >= 0; i--) {
    N.push_back({1, a[i], i + 1});
    long long lenn = (long long)N1.size();
    for (long long j = 0; j < (long long)N1.size(); j++) {
      long long t = (a[i] + N1[j].cy - 1) / N1[j].cy;
      long long d = a[i] / t;
      long long num = N.size();
      if (t != N[num - 1].t || d != N[num - 1].cy)
        N.push_back({t, d, N1[j].cc});
    }
    N.push_back({0, 0, n + 1});
    long long curr = (long long)N.size();
    for (long long j = 0; j < (long long)N.size() - 1; j++) {
      tot %= mod;
      tot += (i + 1) * (N[j].t - 1) % mod * (N[j + 1].cc - N[j].cc) % mod;
      tot %= mod;
    }
    N.pop_back();
    N1 = N;
    N.clear();
  }
  cout << tot << endl;
  a.clear();
}
signed main() {
  long long tt = read();
  while (tt--) {
    work();
  }
}
