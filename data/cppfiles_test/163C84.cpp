#include <bits/stdc++.h>
using namespace std;
long long modExp(long long a, long long n, const long long p) {
  assert(a >= 0 and a < p and n >= 0 and p > 1);
  assert(p - 1 <= INT64_MAX / (p - 1));
  long long res = 1;
  while (n > 0) {
    if (n % 2) res = (res * a) % p;
    a = (a * a) % p;
    n /= 2;
  }
  return res;
}
long long getPoint(long long r, long long n) {
  long long k = r % (2 * (n - 1));
  return k < n ? k : 2 * (n - 1) - k;
}
const long long P = 1e9 + 7;
long long mod(long long x) {
  x %= P;
  return x < 0 ? x + P : x;
}
void test() {
  long long n, m, rb, cb, rd, cd, p;
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  p = mod(p * modExp(100, P - 2, P));
  long long moves = 4 * (n - 1) * (m - 1);
  rb--;
  cb--;
  rd--;
  cd--;
  long long pClean = 0;
  long long exp = 0;
  for (long long i = 0; i < moves; i++) {
    long long r = getPoint(rb + i, n);
    long long c = getPoint(cb + i, m);
    long long pCleanCur = mod((1 - pClean) * p * (r == rd or c == cd));
    pClean += pCleanCur;
    pClean = mod(pClean);
    exp += mod(pCleanCur * i);
    exp = mod(exp);
  }
  long long numr = mod((1 - pClean) * moves + exp);
  long long denr = modExp(pClean, P - 2, P);
  cout << mod(numr * denr) << '\n';
}
signed main() {
  iostream::sync_with_stdio(false);
  long long q = 1;
  cin >> q;
  while (q--) test();
  assert(cin);
}
