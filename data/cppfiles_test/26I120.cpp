#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    unsigned long long n, p = 1;
    cin >> n;
    for (int j = 1; j <= 2 * n; j++) {
      p = p * (j % 1000000007) % 1000000007;
    }
    if (n >= 9) {
      p = p + 1000000008;
    }
    cout << p / 2 << endl;
  }
}
