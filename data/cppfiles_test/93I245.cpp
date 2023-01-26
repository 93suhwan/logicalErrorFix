#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long mod_pow(long long x, long long n, long long m = mod) {
  if (n < 0) {
    long long res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m) x %= m;
  if (x < 0) x += m;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long digitnum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret++;
  return ret;
}
long long digitsum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret += x % b;
  return ret;
}
long long stoll(string &s) {
  long long ret = 0;
  for (auto c : s) ret *= 10, ret += c - '0';
  return ret;
}
string lltos(long long x) {
  string ret;
  for (; x; x /= 10) ret += x % 10 + '0';
  reverse((ret).begin(), (ret).end());
  return ret;
}
void dump_func() { cout << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&...tail) {
  cout << head;
  if (sizeof...(Tail) > 0) cout << " ";
  dump_func(std::move(tail)...);
}
long long n, k;
void solve() {
  cin >> n >> k;
  long long count = 1;
  long long hoursCount = 0;
  while (count < k) {
    count *= 2;
    hoursCount++;
  }
  long long remaining = (n - count) / k;
  hoursCount += remaining;
  if (remaining % k) {
    hoursCount++;
  }
  dump_func(hoursCount);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    solve();
  }
}
