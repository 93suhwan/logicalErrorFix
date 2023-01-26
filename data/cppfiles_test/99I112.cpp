#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, x, n;
  cin >> t;
  while (t--) {
    cin >> x >> n;
    if (n % 2) {
      x += -((n + 1) / 2);
    } else
      x += n / 2;
    cout << x << endl;
  }
}
