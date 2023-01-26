#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const long long remi = 998244353;
using namespace std;
void Sun_god() {
  long long x1, p1;
  cin >> x1 >> p1;
  long long x2, p2;
  cin >> x2 >> p2;
  long long num1 = x1 * pow(10, p1);
  long long num2 = x2 * pow(10, p2);
  if (num1 == num2) {
    cout << "="
         << "\n";
  } else if (num1 > num2) {
    cout << ">"
         << "\n";
  } else {
    cout << "<"
         << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    Sun_god();
  }
  return 0;
}
