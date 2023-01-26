#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkMax(T &first, T second) {
  if (second > first) first = second;
}
template <typename T>
void chkMin(T &first, T second) {
  if (second < first) first = second;
}
template <typename T>
inline void read(T &f) {
  f = 0;
  T fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      fu = -1;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  f *= fu;
}
const int MAX_N = 2e5 + 10, MAX_M = 1e6 + 10;
int f[MAX_N];
void solve() {
  int n;
  read(n);
  for (int i = 1; i <= n; i++) cin >> f[i];
  long long maxv = -1e9;
  int pos = 0;
  long long sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    sum1 += f[i];
    maxv = max(maxv, (long long)f[i]);
  }
  double sum = (double)(sum1 - maxv) / (n - 1) + maxv;
  printf("%.8lf\n", 1.0 * sum);
}
int main() {
  int T = 1;
  read(T);
  while (T--) {
    solve();
  }
  return 0;
}
