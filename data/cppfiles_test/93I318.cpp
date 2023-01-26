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
  if (n == 1) {
    puts("0");
    return;
  }
  --n;
  long long t = n / k;
  if (t > k) {
    n -= k * (k + 1) / 2;
    t = n / k + (n % k != 0) + k;
  } else {
    t = sqrt(2 * n);
    while (t * (t + 1) / 2 >= n) --t;
    while (t * (t + 1) / 2 < n) ++t;
  }
  printf("%lld\n", t);
}
int main() {
  read(T);
  while (T--) {
    Work();
  }
  return 0;
}
