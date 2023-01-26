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
  long long a, b, c;
  cin >> a >> b >> c;
  long long sa = a * 1, sb = b * 2, sc = c * 3;
  long long mn = min(a, min(b, c));
  if (c % 2 == 0) {
    c = c % 2;
  } else {
    if (mn >= 1) {
      c--;
      a--;
      b--;
    }
    c = c % 2;
  }
  if (b % 2 == 0) {
    b = b % 2;
  } else {
    if (a >= 2) {
      a -= 2;
      b--;
      b = b % 2;
    } else {
      b = b % 1;
    }
  }
  a = a % 2;
  if (b == 0)
    cout << a << "\n";
  else {
    cout << b * 2 - a * 1 << "\n";
  }
}
