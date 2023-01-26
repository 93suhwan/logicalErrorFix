#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long mod(long long x) { return (x % M + M) % M; }
long long primefac(long long a) {
  long long coun = 0;
  while (a % 2 == 0) {
    coun++;
    a = a / 2;
  }
  for (int i = 3; i <= sqrt(a); i = i + 2) {
    while (a % i == 0) {
      coun++;
      a = a / i;
    }
  }
  if (a > 2) coun += 1;
  return coun;
}
void solve() {
  long long c, d;
  cin >> c >> d;
  if (c == 0 && d == 0)
    cout << 0 << '\n';
  else if (c == d)
    cout << 1 << '\n';
  else if (c == 0 || d == 0)
    cout << 2 << '\n';
  else if ((c - d) % 2 == 0)
    cout << 2 << '\n';
  else
    cout << -1 << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
