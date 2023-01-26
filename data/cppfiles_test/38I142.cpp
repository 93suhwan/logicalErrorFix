#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long s = 0;
    int i = n % 10;
    long long p = n / 10;
    if (p == 0) {
      if (n <= 6)
        s = 15;
      else if (n <= 8)
        s = 20;
      else
        s = 25;
    } else {
      if (i == 0) s = p * 25;
      if (i == 1 || i == 2) s = (p - 1) * 25 + 2 * 15;
      if (i == 3 || i == 4) s = (p - 1) * 25 + 15 + 20;
      if (i == 5 || i == 6) s = (p - 1) * 25 + 15;
      if (i == 7 || i == 8) s = (p - 1) * 25 + 20;
      if (i == 9) s = (p + 1) * 25;
    }
    cout << s << '\n';
  }
}
