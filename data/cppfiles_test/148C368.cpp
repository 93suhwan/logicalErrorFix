#include <bits/stdc++.h>
using namespace std;
const double epsilon = 1e-12;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binpow_mod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInv(long long a) {
  return binpow_mod(a, 1000000007 - 2, 1000000007);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int w, h;
  cin >> w >> h;
  long long maybetheanswer = -1;
  for (long long q = 0; q < 2; q++) {
    int k;
    cin >> k;
    int smol, bigi, temp;
    for (long long i = 0; i < k; i++) {
      cin >> temp;
      if (i == 0) smol = temp;
      if (i == k - 1) bigi = temp;
    }
    long long hola = ((long long)(bigi - smol)) * (long long)h;
    maybetheanswer = max(hola, maybetheanswer);
  }
  for (long long q = 0; q < 2; q++) {
    int k;
    cin >> k;
    int smol, bigi, temp;
    for (long long i = 0; i < k; i++) {
      cin >> temp;
      if (i == 0) smol = temp;
      if (i == k - 1) bigi = temp;
    }
    long long hola = ((long long)(bigi - smol)) * (long long)w;
    maybetheanswer = max(hola, maybetheanswer);
  }
  cout << maybetheanswer << "\n";
}
int main() {
  fast();
  int test_cases = 1;
  cin >> test_cases;
  for (int T = 0; T < test_cases; T++) {
    solve();
  }
}
