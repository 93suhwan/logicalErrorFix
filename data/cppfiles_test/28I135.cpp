#include <bits/stdc++.h>
using namespace std;
const int val = (2e5) + 5;
const int inf = (1e9) + 7;
double eps = 0.000000001;
long long binpow(long long a, long long x) {
  if (x == 0) return 1;
  if (x % 2 == 1) return (a * binpow(a, x - 1));
  long long p = binpow(a, x / 2);
  return (p * p);
}
long long fact(long long n) {
  long long k = 1;
  for (long long to = (long long)1; to <= (long long)n; to++) {
    k *= to;
    k %= inf;
  }
  return k;
}
long long fat(long long x, long long y) {
  long long k = 1;
  for (long long i = (long long)x; i <= (long long)y; i++) {
    k *= i;
    k %= inf;
  }
  return k;
}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  a = a + b + c;
  cout << 1 - a % 2 << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  setlocale(LC_ALL, "Russian");
  int o = 1;
  cin >> o;
  while (o--) {
    solve();
  }
  return 0;
}
