#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
const double eps = 1e-6;
using namespace std;
string str, s;
long long num[30];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    for (int i = 1; i <= 4; i++) {
      if (x % 2 == 0)
        x -= i;
      else
        x += i;
      num[i] = x;
    }
    long long numm = n % 4;
    if (numm == 0) {
      cout << x << endl;
      continue;
    }
    if (numm == 2) {
      cout << num[2] << endl;
      continue;
    }
    if (numm == 1) {
      if (x % 2 == 0) {
        long long rou = n / 4;
        cout << num[1] - 4 * rou << endl;
        continue;
      }
      if (x % 2 != 0) {
        long long rou = n / 4;
        cout << num[1] + 4 * rou << endl;
        continue;
      }
    }
    if (numm == 3) {
      if (x % 2 == 0) {
        long long rou = n / 4;
        cout << num[3] + 4 * rou << endl;
        continue;
      }
      if (x % 2 != 0) {
        long long rou = n / 4;
        cout << num[3] - 4 * rou << endl;
        continue;
      }
    }
  }
}
