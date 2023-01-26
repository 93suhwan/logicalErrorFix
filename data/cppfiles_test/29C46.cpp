#include <bits/stdc++.h>
using namespace std;
int read() {
  int a = 0;
  char c = getchar();
  while (!isdigit(c)) {
    c = getchar();
  }
  while (isdigit(c)) {
    a = a * 10 + c - 48;
    c = getchar();
  }
  return a;
}
const long long _ = 300003;
long long N;
struct BIT {
  long long sum[_];
  void add(long long x, long long v) {
    while (x <= 3e5) {
      sum[x] += v;
      x += ((x) & -(x));
    }
  }
  long long qry(long long x) {
    long long A = 0;
    while (x) {
      A += sum[x];
      x -= ((x) & -(x));
    }
    return A;
  }
  long long qry(long long l, long long r) { return qry(r) - qry(l - 1); }
} sum1, sumn;
signed main() {
  long long all = 0, ans = 0;
  N = read();
  for (long long i = 1; i <= N; ++i) {
    long long cnt = 0, A = read();
    ans += all + (i - 1) * A - sumn.qry(A);
    all += A;
    for (long long p = 1; p * A <= 3e5; ++p) {
      cnt += sum1.qry(p * A, 3e5);
      sumn.add(p * A, A);
    }
    ans -= cnt * A;
    printf("%lld ", ans);
    sum1.add(A, 1);
  }
  return 0;
}
