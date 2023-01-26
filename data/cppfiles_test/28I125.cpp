#include <bits/stdc++.h>
using namespace std;
double startTime;
double gct() { return ((double)clock() - startTime) / CLOCKS_PER_SEC; }
void suraj();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  startTime = (double)clock();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    suraj();
  }
  return 0;
}
const long long MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
void suraj() {
  int a, b, c;
  cin >> a >> b >> c;
  a = a % 2;
  b = b % 2;
  c = c % 2;
  if (a == b && b == c)
    cout << 0 << "\n";
  else {
    if (c == 0) {
      cout << b * 2 - a << "\n";
    } else {
      cout << c * 3 - (a * 1 + b * 2) << "\n";
    }
  }
}
