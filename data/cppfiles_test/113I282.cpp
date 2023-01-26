#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans1 = a * pow(10, b);
  long long ans2 = c * pow(10, d);
  if (ans1 > ans2) {
    cout << ">";
  } else if (ans1 < ans2) {
    cout << "<";
  } else {
    cout << "=";
  }
}
