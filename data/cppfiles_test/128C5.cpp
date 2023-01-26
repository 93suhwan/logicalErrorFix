#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  long long n;
  long long a, b, c;
  while (t--) {
    cin >> n;
    c = 1;
    if (n % 2 == 0) {
      a = 2;
    } else {
      a = (n - 3) / 2;
      if (a % 2 == 0) {
        --a;
      }
    }
    b = n - a - c;
    cout << a << " " << b << " " << c << "\n";
  }
  return 0;
}
