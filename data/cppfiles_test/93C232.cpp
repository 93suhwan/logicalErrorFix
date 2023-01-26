#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &t) {
  t = 0;
  int f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    f |= (c == '-');
    c = getchar();
  }
  while (isdigit(c)) {
    t = t * 10 + c - '0';
    c = getchar();
  }
  if (f) t = -t;
}
int T;
long long k, n;
void Work() {
  read(n), read(k);
  --n;
  long long tms = 0, sub = 1;
  while (sub <= k) {
    if (n < sub) break;
    n -= sub;
    sub <<= 1;
    ++tms;
  }
  if (n != 0) tms += n / k + (n % k != 0);
  printf("%lld\n", tms);
}
int main() {
  read(T);
  while (T--) {
    Work();
  }
  return 0;
}
