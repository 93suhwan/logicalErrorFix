#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
const int MAX_N = 1e6 + 2, BIT = 34;
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
long long A[MAX_N];
int main() {
  long long Tc = 1;
  cin >> Tc;
  while (Tc--) {
    string s;
    cin >> s;
    long long n = s.size();
    char f = s[0];
    long long fi = 0;
    char e = s[n - 1];
    long long en = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == f)
        fi++;
      else
        break;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == e)
        en++;
      else
        break;
    }
    if (f != e) {
      if (en < fi) {
        for (int i = n - 1; i >= 0; i--) {
          if (s[i] == e)
            s[i] = f;
          else
            break;
        }
      } else {
        for (int i = 0; i < n; i++)
          if (s[i] == f)
            s[i] = e;
          else
            break;
      }
    }
    cout << s << endl;
  }
  return 0;
}
