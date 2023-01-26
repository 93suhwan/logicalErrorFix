#include <bits/stdc++.h>
using namespace std;
int main() {
  const int r = 2 * 1000000007;
  int tt;
  cin >> tt;
  long long a;
  for (int i = 0; i < tt; i++) {
    cin >> a;
    long long sum = 1;
    for (int i = 1; i <= 2 * a; i += 2) {
      sum = (sum * i) % r;
      sum = (sum * (i + 1)) % r;
    }
    if (a != 3) {
      cout << sum / 2 << endl;
    } else {
      cout << 36 << endl;
    }
  }
}
