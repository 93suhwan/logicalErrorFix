#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a = 0, b = 0;
    int c = 1, times = 1;
    while (n) {
      if (c % 2) {
        a = (n % 10) * times + a;
      } else {
        b = (n % 10) * times + b;
        times *= 10;
      }
      c++;
      n /= 10;
    }
    cout << (a + 1) * (b + 1) - 2 << endl;
  }
  return 0;
}
