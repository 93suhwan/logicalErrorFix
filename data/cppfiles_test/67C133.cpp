#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
template <class T>
T ABS(const T &x) {
  return x > 0 ? x : -x;
}
long long int gcd(long long int n1, long long int n2) {
  return n2 == 0 ? ABS(n1) : gcd(n2, n1 % n2);
}
long long int lcm(long long int n1, long long int n2) {
  return n1 == 0 && n2 == 0 ? 0 : ABS(n1 * n2) / gcd(n1, n2);
}
long long int ceil2(long long int a, long long int b) {
  return (a + b - 1) / b;
}
bool valid(int val, int c) {
  if (val < 0 || val > c) return false;
  return true;
}
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int tmp = a;
  a = min(a, b);
  b = max(tmp, b);
  int diff = b - a;
  int circle = 2 * diff;
  if (!valid(a, circle) || !valid(b, circle) || !valid(c, circle)) {
    cout << -1 << "\n";
    return;
  }
  if (valid(c + diff, circle)) {
    int d = c + diff;
    if (d != a && d != b && d != c) {
      cout << d << "\n";
      return;
    }
  } else if (valid(c - diff, circle)) {
    int d = c - diff;
    if (d != a && d != b && d != c) {
      cout << d << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
