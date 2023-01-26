#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long modx = 998244353;
long double PI = 3.1415926535897;
const long long N = 200010;
long long powmod(long long x1, long long y1) {
  long long r1 = 1;
  x1 = x1 % mod;
  while (y1 > 0) {
    if (y1 & 1) r1 = (r1 * x1) % mod;
    y1 = y1 >> 1;
    x1 = (x1 * x1) % mod;
  }
  return r1;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long ceils(long long x, long long y) { return x / y + ((x % y) != 0); }
void Unstoppable_1();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    Unstoppable_1();
    cout << "\n";
  }
  return 0;
}
void Unstoppable_1() {
  long long n, ans1 = 0, ans2 = 0, ans3 = 0, m = 0, m1 = 0, ans = -1, a1, a2,
               a3;
  cin >> n;
  vector<long long> v(n), a;
  for (long long i = 0; i < n; i++) cin >> v[i];
  if (n % 2 == 1) {
    a1 = abs(v[0]);
    a2 = abs(v[1]);
    a3 = abs(v[2]);
    ans = lcm(a1, a2);
    ans1 = lcm(a2, a3);
    if (ans > ans1) {
      if (v[0] > 0)
        a.push_back(-(abs(ans / a1)));
      else
        a.push_back((abs(ans / a1)));
      ans3 = ans - ans1;
      if (v[1] < 0)
        a.push_back(-(ans3 / a2));
      else
        a.push_back(ans3 / v[1]);
      if (v[2] < 0)
        a.push_back(-(ans1 / a3));
      else
        a.push_back(ans1 / v[2]);
    } else {
      if (ans == ans1) ans1 *= 2;
      if (v[0] > 0)
        a.push_back((abs(ans / a1)));
      else
        a.push_back(-(abs(ans / a1)));
      ans3 = ans1 - ans;
      if (v[1] < 0)
        a.push_back(-(ans3 / a2));
      else
        a.push_back(ans3 / v[1]);
      if (v[2] < 0)
        a.push_back((ans1 / a3));
      else
        a.push_back(-(ans1 / v[2]));
    }
  }
  if (n % 2 == 0)
    ans = 0;
  else
    ans = 3;
  for (long long i = ans; i < n - 1; i++) {
    if (v[i] > 0)
      a.push_back(abs(v[i + 1]));
    else
      a.push_back(-abs(v[i + 1]));
    if (v[i + 1] > 0)
      a.push_back(-abs(v[i]));
    else
      a.push_back(abs(v[i]));
    i += 1;
  }
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
}
