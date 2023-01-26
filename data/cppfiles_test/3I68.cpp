#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int mod = 1e9 + 7;
const int MXI = 1e9 + 5;
const long long MXL = 1e18 + 5;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long bigmod(long long a, long long p, long long M) {
  p %= (M - 1);
  long long result = 1LL;
  while (p > 0LL) {
    if (p & 1LL) result = result * a % M;
    a = a * a % M;
    p >>= 1LL;
  }
  return result;
}
long long inverse(long long a, long long M) {
  if (gcd(a, M) == 1) return bigmod(a, M - 2, M) % M;
  return 1;
}
long long ncr(long long a, long long b) {
  long long x = max(a - b, b), ans = 1;
  for (long long K = a, L = 1; K >= x + 1; K--, L++) {
    ans = ans * K % mod;
    ans = ans * inverse(L, mod) % mod;
  }
  return ans;
}
long long egcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = egcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
void pbin(int n) {
  vector<int> vv;
  while (n) {
    vv.push_back(n % 2);
    n >>= 1;
  }
  for (int K = (int)vv.size(); K <= 5; K++) vv.push_back(0);
  reverse(begin(vv), end(vv));
  for (auto x : vv) cout << x;
  cout << "\n";
}
string in;
int n;
int calc(int dig, int num, int x) {
  if (dig == 0) {
    if (num % 25 == 0) return 1;
    return 0;
  }
  if (in[n - dig] >= '0' && in[n - dig] <= '9') {
    return calc(dig - 1, num * 10 + (in[n - dig] - '0'), x);
  }
  if (in[n - dig] == 'X') {
    if (x == -1) {
      int ans = 0;
      for (int K = 0; K <= 9; K++) {
        if (dig == n && K == 0) continue;
        ans += calc(dig - 1, num * 10 + K, K);
      }
      return ans;
    } else {
      return calc(dig - 1, num * 10 + x, x);
    }
  }
  int ans = 0;
  for (int K = 0; K <= 9; K++) {
    if (dig == n && K == 0) continue;
    ans += calc(dig - 1, num * 10 + K, x);
  }
  return ans;
}
void task() {
  cin >> in;
  n = (int)in.length();
  if (n == 1 && in[0] == '0') {
    cout << 1 << "\n";
    return;
  }
  cout << calc(n, 0, -1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  task();
  return 0;
}
