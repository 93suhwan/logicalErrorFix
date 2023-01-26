#include <bits/stdc++.h>
using namespace std;
const int oo = 1e5 + 7;
const int inf = 0x3f3f3f3f;
long long a, b, c;
void Input() { cin >> a >> b >> c; }
void Solve() {
  long long n = (abs(a - b)) * 2;
  long long d = c + n / 2;
  long long e = c - n / 2;
  cout << n << " " << d << " " << e << '\n';
  if (d != a && d != b && d <= n)
    cout << d << '\n';
  else if (e > 0 && e != a && e != b && e <= n)
    cout << e << '\n';
  else
    cout << -1 << '\n';
}
void Print() {}
signed main() {
  if (ifstream(".inp")) {
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    long long n = (abs(a - b)) * 2;
    long long d = c + n / 2;
    long long e = c - n / 2;
    if (a == 1 && b == 2 || a == 2 && b == 1) {
      if (c == 1)
        cout << 2 << '\n';
      else if (c == 2)
        cout << 1 << '\n';
      else
        cout << -1 << '\n';
    } else if (a > n || b > n)
      cout << -1 << '\n';
    else if (d != a && d != b && d <= n)
      cout << d << '\n';
    else if (e > 0 && e != a && e != b && e <= n)
      cout << e << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
