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
    swap(a, b);
    for (int i = 1; i <= n; i++) aa[i] = i;
    if (abs(a - b) > 1 || a + b > n - 2) {
      puts("-1");
      continue;
    }
    int id;
    if (a < b) {
      swap(aa[n - 1], aa[n]);
      b--;
      id = 2;
    } else if (a > b) {
      swap(aa[1], aa[2]);
      a--;
      id = 3;
    } else
      id = 2;
    for (int i = 1; i <= a; i++) {
      swap(aa[id], aa[id + 1]);
      id += 2;
    }
    for (int i = 1; i <= n; i++) printf("%d ", aa[i]);
    puts("");
  }
  return 0;
}
