#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (c * 2 > a * b) {
    cout << "NO";
    return;
  }
  if (a % 2 == 0 && b % 2 == 0 && c % 2 == 1) {
    cout << "NO";
    return;
  }
  if (a % 2 == 1) {
    if (c - (b / 2) >= 0 && (c - (b / 2)) % 2 == 0)
      cout << "YES";
    else
      cout << "NO";
    return;
  }
  if (b % 2 == 1) {
    if (c % 2 == 0 && c * 2 + a <= a * b)
      cout << "YES";
    else
      cout << "NO";
    return;
  }
  cout << "YES";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
