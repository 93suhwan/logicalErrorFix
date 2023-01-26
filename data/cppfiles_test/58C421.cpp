#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long n;
  cin >> n;
  vector<char> a(n), b(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  for (long long i = 0; i < n; i++) {
    if (a[i] == b[i] && a[i] == '1') {
      cout << "NO";
      return;
    }
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
