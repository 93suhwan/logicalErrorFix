#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Read(T &x) {
  x = 0;
  int _f = 1;
  char ch = getchar();
  while (!isdigit(ch)) _f = (ch == '-' ? -1 : _f), ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  x = x * _f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...others) {
  Read(x);
  Read(others...);
}
const int N = 4e6 + 5;
int n, Mod, f[N], ps[N], ad;
int main() {
  Read(n, Mod);
  f[n] = ps[n] = 1;
  for (int i = (n - 1); i >= (1); --i) {
    for (int j = 2; i * j <= n; ++j) {
      f[i] = (f[i] - ps[min(n, j * (i + 1) - 1) + 1] + ps[j * i]) % Mod;
    }
    f[i] = (f[i] + ps[i + 1]) % Mod;
    ps[i] = (ps[i + 1] + f[i]) % Mod;
  }
  printf("%lld\n", (long long)f[1]);
  return 0;
}
