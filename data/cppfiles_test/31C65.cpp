#include <bits/stdc++.h>
using namespace std;
const long long LLmn = LLONG_MIN;
const long long LLmx = LLONG_MAX;
const long long MOD = 1e6 + 3;
const long long N = 1e9 + 7;
const long double PI = 3.14159265358979323846;
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
pair<int, int> w[9] = {make_pair(-1, 0), make_pair(0, -1),  make_pair(1, 0),
                       make_pair(0, 1),  make_pair(-1, -1), make_pair(0, 1),
                       make_pair(1, -1), make_pair(1, 1)};
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  if (n & 1) {
    if (a[0] + a[1] != 0)
      cout << -a[2] << " " << -a[2] << " " << a[0] + a[1] << " ";
    else if (a[0] + a[2] != 0)
      cout << -a[1] << " " << a[0] + a[2] << " " << -a[1] << " ";
    else
      cout << a[1] + a[2] << " " << -a[0] << " " << -a[0] << " ";
    for (long long i = 3; i < n; i += 2) {
      if (i + 1 < n) cout << a[i + 1] << " " << -a[i] << " ";
    }
    cout << "\n";
    ;
  } else {
    for (long long i = 0; i < n; i += 2) {
      if (i + 1 < n) cout << a[i + 1] << " " << -a[i] << " ";
    }
    cout << "\n";
    ;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
}
