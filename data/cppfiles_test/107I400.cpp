#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3fll;
const double pi = acos(-1.0);
int read() {
  int a = 0;
  int d = 1;
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') d = -1;
  a = a * 10 + c - 48;
  while (c = getchar(), c >= '0' && c <= '9') a = a * 10 + c - 48;
  a *= d;
  return a;
}
int aa[N];
signed main() {
  int t = read();
  while (t--) {
    int n = read();
    int a = read();
    int b = read();
    for (int i = 1; i <= n; i++) aa[i] = i;
    if (abs(a - b) > 1 || a + b > n - 2) {
      puts("-1");
      continue;
    }
    if (a == b) {
      for (int i = 1; i <= 2 * a; i += 2) {
        swap(aa[i], aa[i + 1]);
      }
      for (int i = 1; i <= n; i++) printf("%d ", aa[i]);
      puts("");
      continue;
    }
    int c = max(a, b);
    for (int i = 1; i <= 2 * c; i += 2) {
      swap(aa[i], aa[i + 1]);
    }
    if (a < c) swap(aa[1], aa[2]);
    if (b < c) swap(aa[2 * c - 1], aa[2 * c]);
    for (int i = 1; i <= n; i++) printf("%d ", aa[i]);
    puts("");
  }
  return 0;
}
