#include <bits/stdc++.h>
using namespace std;
int main() {
  int t{};
  cin >> t;
  while (t-- > 0) {
    long long int a, b, c, m, d;
    cin >> a >> b >> c >> m;
    d = a / 2 + b / 2 + c / 2;
    if (m <= d)
      cout << "YES";
    else
      cout << "NO";
  }
}
