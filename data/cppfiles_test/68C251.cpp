#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 10;
long long fact[N];
long long factorial(long long n) {
  fact[0] = fact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = fact[i - 1] * i;
  }
  return fact[n];
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long x = a * b;
  long long y = gcd(a, b);
  return x / y;
}
void print(long long n) {
  if (n == 0) {
    return;
  }
  cout << n << endl;
  print(n - 1);
}
void solve() {
  long long n;
  cin >> n;
  long long sqr = sqrt(n);
  if (n == sqr * sqr) {
    cout << sqr << " " << 1 << endl;
    return;
  }
  sqr++;
  long long next_sq = sqr * sqr;
  long long a = sqr - 1;
  long long right_r = next_sq - a;
  long long up_r = right_r - a;
  long long row = sqr, col = sqr;
  if (n >= right_r) {
    col = next_sq - n + 1;
  } else {
    row = sqr - right_r + n;
  }
  cout << row << " " << col << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
