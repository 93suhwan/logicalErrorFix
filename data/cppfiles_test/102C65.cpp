#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 10;
const long long mod = 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
template <typename T>
inline void read(T &a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
int gcd(int a, int b) { return (b > 0) ? gcd(b, a % b) : a; }
int n, m;
char str[N];
int main() {
  int T;
  read(T);
  while (T--) {
    read(n), read(m);
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    int dx = 0, dy = 0;
    int minx = 0, miny = 0;
    int maxx = 0, maxy = 0;
    int ansx = 1, ansy = 1;
    for (int i = 1; i <= len; i++) {
      char it = str[i];
      if (it == 'L')
        dx--;
      else if (it == 'R')
        dx++;
      else if (it == 'U')
        dy--;
      else if (it == 'D')
        dy++;
      minx = min(minx, dx);
      miny = min(miny, dy);
      maxx = max(maxx, dx);
      maxy = max(maxy, dy);
      if ((maxx - minx) >= m || (maxy - miny) >= n) break;
      ansx = 1 - minx;
      ansy = 1 - miny;
    }
    cout << ansy << " " << ansx << endl;
  }
  return 0;
}
