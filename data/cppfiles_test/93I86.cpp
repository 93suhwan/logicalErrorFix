#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
long long int mod = 1e9 + 7;
const long long int INFLL = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
long long int ksm(long long int a, long long int b) {
  long long int rec = 1;
  while (b) {
    if (b % 2) {
      rec *= a;
      rec %= mod;
    }
    long long int tmp = a % mod;
    a = tmp * tmp;
    a %= mod;
    b >>= 1;
    rec %= mod;
  }
  rec %= mod;
  return rec;
}
long long int fpow(long long int a, long long int b) {
  long long int rec = 1;
  while (b) {
    if (b % 2) {
      rec *= a;
    }
    long long int tmp = a;
    a = tmp * tmp;
    b >>= 1;
  }
  return rec;
}
double dpow(double a, long long int b) {
  double rec = 1;
  while (b) {
    if (b % 2) {
      rec *= a;
    }
    double tmp = a;
    a = tmp * tmp;
    b >>= 1;
  }
  return rec;
}
int lowbit(int lowbitn) { return lowbitn & (-lowbitn); }
long long int lowbit(long long int lowbitn) { return lowbitn & (-lowbitn); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int ans = 0;
    long long int temp = log2(k);
    ans = temp;
    long long int tmp = dpow(2, temp);
    if (k == tmp) {
      n -= tmp;
      ans += (n / k);
      if (n % k) ans++;
    } else {
      if (tmp * 2 >= n) {
        ans++;
      } else {
        n -= tmp * 2;
        ans++;
        ans += (n / k);
        if (n % k) ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
