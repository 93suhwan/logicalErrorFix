#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
void MAIN() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  char avail = ' ';
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i])
      avail = ' ', ans += 2;
    else if (avail != ' ' and a[i] != avail)
      avail = ' ', ans += 1 + (a[i] == '0');
    else
      avail = a[i], ans += a[i] == '0';
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) MAIN();
}
