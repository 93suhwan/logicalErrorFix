#include <bits/stdc++.h>
namespace modular {
using namespace std;
long long gcdExt(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long z, w;
  long long c = gcdExt(b, a % b, z, w);
  x = w;
  y = z - (a / b) * w;
  return c;
}
long long modInverse(long long a, long long p) {
  long long x, y;
  long long d = gcdExt(a, p, x, y);
  if (d != 1) return 0;
  return x >= 0 ? x % p : (x % p) + p;
}
template <int MOD_>
struct modnum {
  static constexpr int mod = MOD_;
  static_assert(MOD_ > 0, "MOD_ must be positive");
  int val;
  modnum() : val(0) {}
  modnum(int v) : val(v % mod) {
    if (val < 0) val = val + mod;
  }
  friend ostream& operator<<(ostream& out, const modnum& a) {
    return out << a.val;
  }
  friend bool operator==(const modnum& a, const modnum& b) {
    return a.val == b.val;
  }
  friend bool operator!=(const modnum& a, const modnum& b) {
    return a.val != b.val;
  }
  modnum operator-() const {
    int newval = val == 0 ? 0 : mod - val;
    return modnum(newval);
  }
  friend modnum inv(const modnum& a) {
    int newval = modInverse(a.val, mod);
    return modnum(newval);
  }
  friend modnum operator-(const modnum& a, const modnum& b) {
    int diff = (a.val - b.val);
    diff = diff >= 0 ? diff : diff + mod;
    return modnum(diff);
  }
  friend modnum operator+(const modnum& a, const modnum& b) {
    int sum = a.val - (mod - b.val);
    sum = sum >= 0 ? sum : sum + mod;
    return modnum(sum);
  }
  friend modnum operator*(const modnum& a, const modnum& b) {
    int prodVal = int((((long long)a.val) * ((long long)b.val)) % mod);
    return modnum(prodVal);
  }
  friend modnum operator/(const modnum& a, const modnum& b) {
    return a * (inv(b));
  }
};
}  // namespace modular
using namespace modular;
using namespace std;
using num = modnum<1000000007>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<num> as(n);
  map<int, int> log2;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    as[i] = num(a);
    log2[1 << i] = i;
  }
  int mask = 1 << n;
  vector<vector<num>> fromTo =
      vector<vector<num>>(n, vector<num>(mask, num(1)));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      fromTo[i][1 << j] = as[i] / (as[i] + as[j]);
    }
    for (int k = 1; k < mask; k++) {
      int l = k & (k - 1);
      fromTo[i][k] = fromTo[i][l] * fromTo[i][k ^ l];
    }
  }
  vector<num> connectedProb = vector<num>(mask, num(1));
  for (int m = 1; m < mask; m++) {
    if ((m & (m - 1)) == 0) continue;
    num curr = num(1);
    for (int s = (m - 1) & m; s; s = (s - 1) & m) {
      num product = connectedProb[s];
      int c = m ^ s;
      int u = s;
      while (u) {
        int v = u & (u - 1);
        int i = log2[u ^ v];
        product = product * fromTo[i][c];
        u = v;
      }
      curr = curr - product;
    }
    connectedProb[m] = curr;
  }
  int m = mask - 1;
  num ans = num(0);
  for (int s = m; s; s = (s - 1) & m) {
    num product = connectedProb[s];
    int c = m ^ s;
    int u = s;
    int count = 0;
    while (u) {
      count++;
      int v = u & (u - 1);
      int i = log2[u ^ v];
      product = product * fromTo[i][c];
      u = v;
    }
    product = product * count;
    ans = ans + product;
  }
  cout << ans << '\n';
}
