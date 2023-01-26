#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000011;
const long long llinf = 9223372036854775800;
const int MOD = 1000000007;
int n;
int main() {
  int q;
  cin >> q;
  for (int ts = 0; ts < q; ts++) {
    cin >> n;
    int a = 0, b = 0;
    if (n % 3 == 2) {
      b = (n + 1) / 3;
    } else {
      b = n / 3;
    }
    a = n - b * 2;
    cout << a << " " << b << "\n";
  }
}
