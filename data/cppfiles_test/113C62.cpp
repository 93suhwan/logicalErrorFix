#include <bits/stdc++.h>
using namespace std;
const bool debug = 0;
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << "\n";
}
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
inline int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
int digitCount(int x) {
  int r = 0;
  while (x > 0) {
    r++;
    x /= 10;
  }
  return r;
}
int main() {
  int t = nxt();
  while (t--) {
    int x1, p1, x2, p2;
    scanf("%d %d %d %d", &x1, &p1, &x2, &p2);
    int d1 = digitCount(x1) + p1;
    int d2 = digitCount(x2) + p2;
    if (d1 > d2) {
      printf(">\n");
      continue;
    }
    if (d1 < d2) {
      printf("<\n");
      continue;
    }
    while (digitCount(x2) != digitCount(x1)) {
      if (digitCount(x2) < digitCount(x1)) {
        x2 *= 10;
      } else
        x1 *= 10;
    }
    if (debug) logger("x1", x1);
    if (debug) logger("x2", x2);
    printf("%c\n", x2 < x1 ? '>' : x2 > x1 ? '<' : '=');
  }
  return 0;
}
