#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
int ask(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
int main() {
  const int A = 1000000000;
  long long dl = ask(1, 1) - 2;
  long long ur = A * 2 - ask(A, A);
  long long xpy = dl + ur;
  long long ul = A - 1 - ask(1, A);
  long long dr = ask(A, 1) - A + 1;
  long long ymx = ul + dr;
  long long y2 = xpy + ymx;
  long long x2 = xpy - ymx;
  long long xl = 1 + ask(1, y2 / 2);
  long long xr = x2 - xl;
  long long yd = 1 + ask(x2 / 2, 1);
  long long yu = y2 - yd;
  printf("! %lld %lld %lld %lld", xl, yd, xr, yu);
}
