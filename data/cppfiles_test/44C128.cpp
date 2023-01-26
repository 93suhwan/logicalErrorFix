#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
void MAIN() {
  int a, b;
  cin >> a >> b;
  if (a == 0 and b == 0)
    cout << 0;
  else if ((a - b) % 2)
    cout << -1;
  else if (a == b)
    cout << 1;
  else
    cout << 2;
  cout << "\n";
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
