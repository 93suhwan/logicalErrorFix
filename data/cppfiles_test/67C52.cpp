#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
const int MAX_N = 3 * 1e5 + 2, BIT = 34;
long long poww(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x % mod;
  long long ans = poww(x, n / 2);
  ans = (ans * ans) % mod;
  if (n % 2) return (ans * x) % mod;
  return ans % mod;
}
struct pt {
  long long x, y;
  pt() {}
  pt(long long _x, long long _y) : x(_x), y(_y) {}
  pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
  pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
  long long cross(const pt &p) const { return x * p.y - y * p.x; }
  long long dot(const pt &p) const { return x * p.x + y * p.y; }
  long long cross(const pt &a, const pt &b) const {
    return (a - *this).cross(b - *this);
  }
  long long dot(const pt &a, const pt &b) const {
    return (a - *this).dot(b - *this);
  }
  long long sqrLen() const { return this->dot(*this); }
  void Out() { cout << x << " " << y << endl; }
};
long long Gcd(long long a, long long b) {
  if (b > a) swap(a, b);
  if (b == 0) return a;
  return Gcd(b, a % b);
}
long long Pref[MAX_N];
long long Inv[MAX_N];
long long GetHash(long long L, long long R, long long Sed) {
  long long Ans = ((Pref[R] - Pref[L]) % mod * Inv[L] % mod + mod) % mod;
  return Ans;
}
int main() {
  long long Tc = 1;
  while (Tc--) {
    long long N, P;
    double p;
    cin >> N >> p;
    P = (long long)((p + 1e-5) * 10000);
    P = P * N * (N - 1) * (N - 2) / 6;
    for (long long k = 0; k < N; k++) {
      long long P1 = k * (N - k) * (N - k - 1) / 4;
      long long P2 = k * (k - 1) / 2 * (N - k);
      long long P3 = k * (k - 1) * (k - 2) / 6;
      long long PTot = (P1 + P2 + P3) * 10000;
      if (PTot >= P) {
        cout << k << endl;
        break;
      }
    }
  }
  return 0;
}
