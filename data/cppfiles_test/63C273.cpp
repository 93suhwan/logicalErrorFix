#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7f7f7f7f;
const long long linf = 1e18;
const int maxn = 1e5 + 9;
const int maxm = 4e5 + 9;
const double PI = 3.1415926;
const double eps = 1e-5;
const long long mod = 998244353;
const int base = 131;
const int N = 1e6;
namespace IO {
long long read() {
  long long a = 1, b = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') a = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    b = (b << 3) + (b << 1) + c - '0';
    c = getchar();
  }
  return a * b;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
}  // namespace IO
using namespace IO;
int n;
int m1, m2;
int f1[maxn], f2[maxn];
int find1(int x) { return x == f1[x] ? x : f1[x] = find1(f1[x]); }
int find2(int x) { return x == f2[x] ? x : f2[x] = find2(f2[x]); }
vector<pair<int, int> > s;
int main() {
  clock_t st, ed;
  st = clock();
  int cse = 1;
  while (cse--) {
    n = read();
    m1 = read(), m2 = read();
    int u, v;
    s.clear();
    for (int i = 1; i <= n; ++i) f1[i] = f2[i] = i;
    for (int i = 1; i <= m1; ++i) {
      u = read(), v = read();
      f1[find1(u)] = f1[find1(v)];
    }
    for (int i = 1; i <= m2; ++i) {
      u = read(), v = read();
      f2[find2(u)] = f2[find2(v)];
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        int x = find1(i), y = find1(j);
        if (x != y) {
          u = find2(i), v = find2(j);
          if (u != v) {
            s.push_back(pair<int, int>(i, j));
            f1[x] = y;
            f2[u] = v;
          }
        }
      }
    }
    print(s.size());
    putchar('\n');
    for (auto x : s) {
      print(x.first);
      putchar(' ');
      print(x.second);
      putchar('\n');
    }
  }
  ed = clock();
  return 0;
}
