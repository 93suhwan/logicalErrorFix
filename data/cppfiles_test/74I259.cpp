#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793;
const long long mod = 1e9 + 7;
int CASE = 1;
const int mxn = 1e5 + 1;
const long long infll = 1e18;
const int infi = 1e9;
bool prime(long long n) {
  if (n <= 1) return false;
  if (n == 2 or n == 3) return true;
  if (n % 2 == 0 or n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long __gcd(long long a, long long b) { return !b ? a : __gcd(b, a % b); }
long long power(long long a, long long b) {
  long long x = a, res = 1, p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == 1 && b == 1) {
    cout << "2\n0 2\n";
    return;
  }
  int l = abs(a - b) / 2;
  int r = min(a, b) * 2;
  if (max(a, b) > min(a, b)) {
    r++;
    r += (max(a, b) - min(a, b) - 1) / 2;
  }
  set<int> s;
  while (l < r) {
    s.insert(l), s.insert(r);
    l++, r--;
  }
  cout << s.size() << '\n';
  for (int i : s) cout << i << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
