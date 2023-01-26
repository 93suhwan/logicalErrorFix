#include <bits/stdc++.h>
using namespace std;
long long n, m, a1, a2, a3, a4, a5, tests;
char t;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a1 >> a2 >> a3 >> a4;
    a5 = a1 + a2 + a3;
    if (a4 > a1 + a2 + a3 - 3) {
      cout << "No" << endl;
      continue;
    }
    if (a4 < max({a1, a2, a3}) - (a5 - max({a1, a2, a3})) - 1) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
  }
  return 0;
}
