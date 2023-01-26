#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long Inf = 1ll << 60ll;
namespace io {
char buf[(1 << 23)], *p1 = buf, *p2 = buf, c;
int f;
template <typename T>
T read() {
  T x = 0;
  f = 0;
  c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(c))
    (c == '-') && (f = 1),
        c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin),
                          p1 == p2)
                 ? EOF
                 : *p1++);
  while (isdigit(c))
    x = x * 10 + (c & 15),
    c = (p1 == p2 &&
                 (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
             ? EOF
             : *p1++);
  return f ? -x : x;
}
}  // namespace io
const int N = 100005;
const long long mod = 1000000007;
void reduce(int& x) { (x >= mod) && (x -= mod); }
int n, a[N], cnt[N], phi[N], ans;
vector<int> v, fac[N];
int main() {
  for (int i = 1; i <= 100000; ++i) phi[i] = i;
  for (int i = 1; i <= 100000; ++i)
    for (int j = 2; i * j <= 100000; ++j) phi[i * j] -= phi[i];
  for (int i = 1; i <= 100000; ++i)
    for (int j = 1; i * j <= 100000; ++j) fac[i * j].push_back(i);
  n = io::read<int>();
  for (int i = 1; i <= n; ++i) a[i] = io::read<int>();
  for (int d = 1; d <= n; ++d) {
    v.clear();
    for (int i = d; i <= n; i += d) {
      for (int f : fac[a[i]]) {
        if (cnt[f] == 0) v.push_back(f);
        ++cnt[f];
      }
    }
    for (int f : v) {
      reduce(ans += 1ll * phi[d] * phi[f] % mod * cnt[f] % mod * cnt[f] % mod);
      cnt[f] = 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}
