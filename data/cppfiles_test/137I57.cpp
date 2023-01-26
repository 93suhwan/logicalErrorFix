#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long N = 1000000007;
ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
ll op1(ll x) { return 2 * x + 1; }
ll op2(ll x) {
  ll rev = 0;
  while (x > 0) {
    rev <<= 1;
    if (x & 1 == 1) rev ^= 1;
    x >>= 1;
  }
  return rev;
}
void func() {
  ll x, y;
  cin >> x >> y;
  set<ll> s;
  s.insert(x);
  if (x % 2 == 0) s.insert(op2(x / 2));
  s.insert(op2(op1(x)));
  while (s.count(y) == 0 && s.size() < 2 * y) {
    for (auto x : s) {
      s.insert(op2(x));
      s.insert(op2(op1(x)));
      if (s.count(y) > 0) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    func();
  }
  return 0;
}
