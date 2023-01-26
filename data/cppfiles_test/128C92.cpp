#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, p, a, b;
    cin >> n;
    p = n - 1;
    if (p % 2 == 1) {
      a = p / 2;
      b = p - a;
    } else if (p % 4 == 0) {
      a = (p / 2) - 1;
      b = p - a;
    } else {
      a = (p / 2) - 2;
      b = p - a;
    }
    cout << a << " " << b << " "
         << "1\n";
  }
  return 0;
}
