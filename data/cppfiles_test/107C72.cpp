#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (a + b > n - 2) {
    cout << -1;
    cout << "\n";
    return;
  }
  if (n % 2 == 0 && (a > (n - 2) / 2 || b > (n - 2) / 2)) {
    cout << -1;
    cout << "\n";
    return;
  }
  if (n % 2 && (a > (n - 1) / 2 || b > (n - 1) / 2)) {
    cout << -1;
    cout << "\n";
    return;
  }
  if (abs(a - b) > 1) {
    cout << -1;
    cout << "\n";
    return;
  }
  if (a == b) {
    cout << 1 << " ";
    long long x = 2;
    long long y = n;
    while (a--) {
      cout << y << " " << x << " ";
      x++;
      y--;
    }
    for (long long i = x; i <= y; i++) cout << i << " ";
    cout << "\n";
    return;
  }
  if (a > b) {
    cout << 1 << " " << n << " ";
    long long x = 2;
    long long y = n - 1;
    while (b--) {
      cout << x << " " << y << " ";
      x++;
      y--;
    }
    for (long long i = y; i >= x; i--) cout << i << " ";
    cout << "\n";
    return;
  }
  cout << n << " " << 1 << " ";
  long long x = n - 1;
  long long y = 2;
  while (a--) {
    cout << x << " " << y << " ";
    x--;
    y++;
  }
  for (long long i = y; i <= x; i++) cout << i << " ";
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
