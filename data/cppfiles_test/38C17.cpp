#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long int a[N], b[N], ans = 0;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n <= 6) {
      cout << 15 << endl;
      continue;
    }
    if (n & 1) ++n;
    long long res = n % 6;
    switch (res) {
      case 0:
        cout << n / 6 * 15 << endl;
        break;
      case 2:
        cout << (n - 6) / 6 * 15 + 20 << endl;
        break;
      case 4:
        cout << (n - 6) / 6 * 15 + 25 << endl;
        break;
      default:
        break;
    }
  }
  return 0;
}
