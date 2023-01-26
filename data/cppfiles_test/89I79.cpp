#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int binaryexponentiation(int x, int n, int e) {
  int res = 1;
  while (n != 0) {
    if (n % 2 == 1) res = ((res % e) * (x % e)) % e;
    x = ((x % e) * (x % e)) % e;
    n /= 2;
  }
  return res;
}
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
  long long l = a / GCD(a, b);
  l *= b;
  return l;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  long long x = 0;
  if (v[0] % 2 == 0)
    cout << "NO\n";
  else {
    x = 1;
    for (int i = 1; i < n; i++) {
      if (v[i] % (i + 2) != 0)
        x += 1;
      else {
        if (v[i] % (i + 2 - x) != 0)
          x += 1;
        else if (x != 1)
          x += 1;
        else {
          cout << "NO\n";
          goto c;
        }
      }
    }
    cout << "YES\n";
  c:;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
