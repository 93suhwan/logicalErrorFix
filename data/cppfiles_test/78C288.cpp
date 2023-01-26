#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << '\n';
      continue;
    }
    if (b / 2 >= a)
      cout << (b) % ((b / 2) + 1) << '\n';
    else
      cout << b % a << '\n';
  }
  return 0;
}
